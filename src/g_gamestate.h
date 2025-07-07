#ifndef G_GAMESTATE_H
#define G_GAMESTATE_H
#include "t_tiles.h"

#define MAX_HAND_TILE_COUNT 18
#define MAX_DORA_TILE_COUNT 13

typedef struct {
	int window_w;
	int window_h;
	float scale;
	double target_fps;
	double target_frametime_ms;
	Uint32 frame_ticks_start;

	int show_help;

	short int toggle_hand_dora_focus; //0 = focus on hand tiles

	T_Tile hand_tiles[MAX_HAND_TILE_COUNT];
	int hand_tiles_len;

	T_Tile dora_tiles[MAX_DORA_TILE_COUNT];
	int dora_tiles_len;

	T_Tile seat_wind;

	T_Tile prevelant_wind;

} G_GameState;

G_GameState *G_gamestate_create(int target_fps, int window_width, int window_height, float scale);

void G_frame_start(G_GameState *gamestate);
void G_frame_end(G_GameState *gamestate);
void G_destroy(G_GameState *gamestate);

void G_window_renderer_resize(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer, int width,
			      int height, float scale);

#endif // !G_GAMESTATE_H
