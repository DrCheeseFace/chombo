#ifndef G_GAMESTATE_H
#define G_GAMESTATE_H
#include "t_tiles.h"
#include "mahc.h"

#define MAX_HAND_TILE_COUNT 18
#define MAX_DORA_TILE_COUNT 13

typedef enum {
	G_MENU_HAND = 0,
	G_MENU_DORA,
	G_MENU_SEAT_WIND,
	G_MENU_PREVALENT_WIND,
	G_MENU_COUNT,
} G_Selected_menu;

typedef struct {
	int window_w;
	int window_h;
	float scale;
	double target_fps;
	double target_frametime_ms;
	Uint32 frame_ticks_start;

	int show_help;

	G_Selected_menu selected_menu;
	int is_selected_menu_backgrounded;

	T_Tile hand_tiles[MAX_HAND_TILE_COUNT];
	int hand_tiles_len;

	T_Tile dora_tiles[MAX_DORA_TILE_COUNT];
	int dora_tiles_len;

	T_Tile seat_wind;

	T_Tile prevelant_wind;

	int riichi;
	int double_riichi;
	int ippatsu;
	int haitei;
	int chankan;
	int rinshan;

	int show_confirm_handshape_menu;
	HandShapes handshapes;
} G_GameState;

G_GameState *G_gamestate_create(int target_fps, int window_width, int window_height, float scale);

void G_frame_start(G_GameState *gamestate);
void G_frame_end(G_GameState *gamestate);
void G_destroy(G_GameState *gamestate);
void G_increment_menu(G_GameState *gamestate);
void G_decrement_menu(G_GameState *gamestate);
void G_increment_seat_wind(G_GameState *gamestate);
void G_decrement_seat_wind(G_GameState *gamestate);
void G_increment_prevelant_wind(G_GameState *gamestate);
void G_decrement_prevelant_wind(G_GameState *gamestate);

// returns 1 if successful
int G_calculate_handshapes(G_GameState *gamestate);

void G_window_renderer_resize(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer, int width,
			      int height, float scale);

#endif // !G_GAMESTATE_H
