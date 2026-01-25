#include "b_button.h"
#include "mr_utils/mrv_vectors.h"
#include "src/g_gamestate.h"
#include "util.h"

#include <SDL3/SDL.h>
#include <mr_utils.h>
#include <stdlib.h>

MrvVector active_buttons;

mr_internal B_Button *B_button_exists(const char *id);
mr_internal void B_button_destroy(size_t idx);

void B_init(void)
{
	mrv_init(&active_buttons, 0, sizeof(B_Button));

	return;
}

void B_destroy(void)
{
	for (size_t i = active_buttons.len; i > 0; i--) {
		B_button_destroy(i - 1);
	}

	mrv_free(&active_buttons);
}

int B_register_button(const char *id_str, SDL_FRect box,
		      void (*on_click)(struct G_GameState *gamestate),
		      bool (*destroy_when)(struct G_GameState *gamestate))
{
	B_Button *button = B_button_exists(id_str);
	if (!button) {
		B_Button new_button = { 0 };
		mrs_init(strlen(id_str), id_str, strlen(id_str),
			 &new_button.id_str);

		if (mrv_append(&active_buttons, &new_button,
			       APPEND_SCALING_INCREMENT) != OK) {
			mrs_free(&new_button.id_str);
			return 1;
		}

		button = mrv_get_idx(&active_buttons, active_buttons.len - 1);
	}

	button->box = box;
	button->on_click = on_click;
	button->destroy_when = destroy_when;

	return 0;
}

void B_active_buttons_purge(struct G_GameState *gamestate)
{
	B_Button *button;
	for (size_t i = active_buttons.len; i > 0; i--) {
		size_t idx = i - 1;
		button = mrv_get_idx(&active_buttons, idx);

		if (button->destroy_when && button->destroy_when(gamestate)) {
			B_button_destroy(idx);
		}
	}
}

bool B_handle_click(struct G_GameState *gamestate, SDL_Renderer *sdl_renderer,
		    SDL_MouseButtonEvent button_event)
{
	B_active_buttons_purge(gamestate);

	// searched backwards for most recently added button
	B_Button *button;
	size_t idx;
	for (size_t i = active_buttons.len; i > 0; i--) {
		idx = i - 1;

		button = mrv_get_idx(&active_buttons, idx);
		if (is_pointer_within_bounds(sdl_renderer, button_event,
					     button->box)) {
			button->on_click(gamestate);
			return true;
		}
	}
	return false;
}

mr_internal void B_button_destroy(size_t idx)
{
	B_Button *button_to_destroy = mrv_get_idx(&active_buttons, idx);
	mrs_free(&button_to_destroy->id_str);
	mrv_remove(&active_buttons, idx);
}

mr_internal B_Button *B_button_exists(const char *id)
{
	B_Button *button;
	for (size_t i = 0; i < active_buttons.len; i++) {
		button = mrv_get_idx(&active_buttons, i);
		if (strcmp(button->id_str.value, id) == 0) {
			return button;
		}
	}

	return NULL;
}
