#ifndef E_EVENT_H
#define E_EVENT_H

#include "g_gamestate.h"
#include <SDL2/SDL_events.h>

/**
 * returns 1 if redraw needed
**/
int E_handle_event(G_GameState *gamestate, SDL_Event event);

#endif // !E_EVENT_H
