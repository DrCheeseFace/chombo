#include "g_gamestate.h"
#include "t_tiles.h"
#include <SDL2/SDL_timer.h>
#include <stdlib.h>

Uint32 frame_ticks;

G_GameState *G_gamestate_create(int target_fps, int window_width, int window_height)
{
	G_GameState *gamestate = malloc(sizeof(G_GameState));
	gamestate->target_fps = target_fps;
	gamestate->target_frametime_ms = (1000.0 / (double)target_fps);
	gamestate->window_w = window_width;
	gamestate->window_h = window_height;
	gamestate->tile = T_SHAA;

	return gamestate;
}

void G_destroy(G_GameState *gamestate)
{
	free(gamestate);
}

void G_frame_start(G_GameState *gamestate)
{
	gamestate->frame_ticks_start = SDL_GetTicks64();
}

void G_frame_end(G_GameState *gamestate)
{
	frame_ticks = SDL_GetTicks64() - gamestate->frame_ticks_start;
	if (frame_ticks < gamestate->target_frametime_ms) {
		SDL_Delay(gamestate->target_frametime_ms - frame_ticks);
	}
}
