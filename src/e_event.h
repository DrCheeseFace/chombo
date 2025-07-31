#ifndef E_EVENT_H
#define E_EVENT_H

#include "g_gamestate.h"

bool E_handle_event(struct G_GameState *gamestate, SDL_Renderer *sdl_renderer,
		    SDL_Event event);

#endif // !E_EVENT_H
