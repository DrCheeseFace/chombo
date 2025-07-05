#include "g_gamestate.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

int E_handle_event(G_GameState *gamestate, SDL_Event event)
{
	switch (event.type) {
	case SDL_KEYUP:
		gamestate->show_help = 0;
		return 1;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_SLASH && event.key.keysym.mod == KMOD_LSHIFT) {
			gamestate->show_help = 1;
			return 1;
		}
		return 0;
	case SDL_WINDOWEVENT:
		return 1;
	case SDL_DISPLAYEVENT:
		return 1;
	default:
		return 0;
	}
}
