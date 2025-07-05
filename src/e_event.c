#include "g_gamestate.h"

int E_handle_event(G_GameState *gamestate, SDL_Event event)
{
	switch (event.type) {
	case SDL_KEYUP:
		gamestate->tile = T_PEI;
		return 1;
	case SDL_WINDOWEVENT:
		return 1;
	case SDL_DISPLAYEVENT:
		return 1;
	default:
		return 0;
	}
}
