#include "g_gamestate.h"
#include "t_tiles.h"

int E_handle_event(G_GameState *gamestate, SDL_Event event)
{
	switch (event.type) {
	case SDL_KEYUP:
		gamestate->tile = T_PEI;
		return 1;
	default:
		return 0;
	}
}
