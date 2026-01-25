#ifndef B_BUTTON_H
#define B_BUTTON_H

#include "g_gamestate.h"
#include <SDL3/SDL.h>
#include <mr_utils.h>

typedef struct {
	MrsString id_str;

	SDL_FRect box;

	// registerd func to run if button is clicked
	void (*on_click)(struct G_GameState *gamestate, void *args);

	// registered func to check if button should be destroyed
	bool (*destroy_when)(struct G_GameState *gamestate);

	// passed args to on_click func
	void *args;
} B_Button;

void B_init(void);
void B_destroy(void);

// adds button to active buttons to check for every frame
int B_register_button(const char *id_str, SDL_FRect box,
		      void (*on_click)(struct G_GameState *gamestate,
				       void *args),
		      bool (*destroy_when)(struct G_GameState *gamestate),
		      void *args);

// checks for buttons to destroy
void B_active_buttons_purge(struct G_GameState *gamestate);

// checks all active buttons, and runs the most recently created button
bool B_handle_click(struct G_GameState *gamestate, SDL_Renderer *sdl_renderer,
		    SDL_MouseButtonEvent button_event);

#endif
