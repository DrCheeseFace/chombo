#ifndef B_BUTTON_H
#define B_BUTTON_H

#include "g_gamestate.h"
#include <SDL3/SDL.h>
#include <mr_utils.h>

typedef struct {
#define MAX_BUTTON_ID_STR_LEN 32
	char id_str[MAX_BUTTON_ID_STR_LEN];

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
// WARNING expects strlen(id_str) < MAX_BUTTON_ID_STR_LEN
Err B_register_button(const char *id_str, SDL_FRect box,
		      void (*on_click)(struct G_GameState *gamestate,
				       void *args),
		      bool (*destroy_when)(struct G_GameState *gamestate),
		      void *args);

// checks and removes registered buttons if needs to be destroy
void B_registered_buttons_purge_dead(struct G_GameState *gamestate);

// checks all active buttons, and runs the most recently created button
bool B_handle_click(struct G_GameState *gamestate, SDL_Renderer *sdl_renderer,
		    SDL_MouseButtonEvent button_event);

#endif
