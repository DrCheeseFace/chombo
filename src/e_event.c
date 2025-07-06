#include "g_gamestate.h"

int E_handle_key_down(G_GameState *gamestate, SDL_KeyboardEvent key_event)
{
	if (key_event.key == SDLK_SLASH) {
		gamestate->show_help = 1;
		return 1;
	} else if (key_event.key == SDLK_EQUALS &&
		   (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT)) {
		gamestate->scale += 0.1;
		return 1;
	} else if (key_event.key == SDLK_MINUS &&
		   (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT)) {
		gamestate->scale -= 0.1;
		return 1;
	}
	return 0;
}

int E_handle_event(G_GameState *gamestate, SDL_Event event)
{
	switch (event.type) {
	case SDL_EVENT_KEY_UP:
		gamestate->show_help = 0;
		return 1;
	case SDL_EVENT_KEY_DOWN:
		return E_handle_key_down(gamestate, event.key);
	default:
		return 0;
	}
}
