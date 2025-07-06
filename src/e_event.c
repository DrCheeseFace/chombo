#include "g_gamestate.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

int E_handle_key_down(G_GameState *gamestate, SDL_KeyboardEvent key_event)
{
	if (key_event.keysym.sym == SDLK_SLASH) {
		gamestate->show_help = 1;
		return 1;
	} else if (key_event.keysym.sym == SDLK_EQUALS && key_event.keysym.mod == KMOD_LSHIFT) {
		gamestate->scale += 0.1;
		return 0;
	} else if (key_event.keysym.sym == SDLK_MINUS && key_event.keysym.mod == KMOD_LSHIFT) {
		gamestate->scale -= 0.1;
		return 0;
	}
	return 0;
}

int E_handle_event(G_GameState *gamestate, SDL_Event event)
{
	switch (event.type) {
	case SDL_KEYUP:
		gamestate->show_help = 0;
		return 1;
	case SDL_KEYDOWN:
		return E_handle_key_down(gamestate, event.key);
	case SDL_WINDOWEVENT:
		return 1;
	case SDL_DISPLAYEVENT:
		return 1;
	default:
		return 0;
	}
}
