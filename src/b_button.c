#include "b_button.h"
#include "g_gamestate.h"
#include "util.h"

#include <SDL3/SDL.h>
#include <mr_utils.h>
#include <stdlib.h>

MrvVector registered_buttons;

void B_init(void)
{
	mrv_init(&registered_buttons, 0, sizeof(B_Button));

	return;
}

void B_destroy(void)
{
	for (size_t i = registered_buttons.len; i > 0; i--) {
		B_Button *button = mrv_get_idx(&registered_buttons, i - 1);
		B_registered_button_destroy(button);
	}

	mrv_free(&registered_buttons);
}

int B_register_button(const char *id_str, SDL_FRect box,
		      void (*on_click)(struct G_GameState *gamestate,
				       void *args),
		      bool (*destroy_when)(struct G_GameState *gamestate),
		      void *args)
{
	B_Button *button = B_get_registered_button(id_str, NULL);
	if (!button) {
		B_Button new_button = { 0 };
		mrs_init(strlen(id_str), id_str, strlen(id_str),
			 &new_button.id_str);

		if (mrv_append(&registered_buttons, &new_button,
			       APPEND_SCALING_INCREMENT) != OK) {
			mrs_free(&new_button.id_str);
			return 1;
		}

		button = mrv_get_idx(&registered_buttons,
				     registered_buttons.len - 1);
	}

	button->box = box;
	button->on_click = on_click;
	button->destroy_when = destroy_when;
	button->args = args;

	return 0;
}

void B_registered_buttons_purge_dead(struct G_GameState *gamestate)
{
	B_Button *button;
	for (size_t i = registered_buttons.len; i > 0; i--) {
		size_t idx = i - 1;
		button = mrv_get_idx(&registered_buttons, idx);

		if (button->destroy_when && button->destroy_when(gamestate)) {
			B_registered_button_destroy(button);
		}
	}
}

bool B_handle_click(struct G_GameState *gamestate, SDL_Renderer *sdl_renderer,
		    SDL_MouseButtonEvent button_event)
{
	B_registered_buttons_purge_dead(gamestate);

	// searched backwards for most recently added button
	B_Button *button;
	size_t idx;
	for (size_t i = registered_buttons.len; i > 0; i--) {
		idx = i - 1;

		button = mrv_get_idx(&registered_buttons, idx);
		if (is_pointer_within_bounds(sdl_renderer, button_event,
					     button->box)) {
			button->on_click(gamestate, button->args);
			return true;
		}
	}
	return false;
}

void B_registered_button_destroy(B_Button *button_to_destroy)
{
	int idx;
	B_get_registered_button(button_to_destroy->id_str.value, &idx);
	mrs_free(&button_to_destroy->id_str);
	mrv_remove(&registered_buttons, idx);
}

B_Button *B_get_registered_button(const char *id_str, int *idx)
{
	B_Button *button;
	for (size_t i = 0; i < registered_buttons.len; i++) {
		button = mrv_get_idx(&registered_buttons, i);
		if (strcmp(button->id_str.value, id_str) == 0) {
			if (idx != NULL) {
				*idx = i;
			}
			return button;
		}
	}

	return NULL;
}
