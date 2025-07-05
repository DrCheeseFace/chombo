#ifndef G_GAMESTATE_H
#define G_GAMESTATE_H
#include "t_tiles.h"
#include <stdint.h>

typedef struct {
	int window_w;
	int window_h;
	float scale;
	double target_fps;
	double target_frametime_ms;
	Uint32 frame_ticks_start;
	T_Tile tile;
} G_GameState;

G_GameState *G_gamestate_create(int target_fps, int window_width, int window_height, float scale);

void G_frame_start(G_GameState *gamestate);
void G_frame_end(G_GameState *gamestate);
void G_destroy(G_GameState *gamestate);

void W_window_renderer_resize(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer, int width,
			      int height, float scale);

#endif // !G_GAMESTATE_H
