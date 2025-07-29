#ifndef G_GAMESTATE_H
#define G_GAMESTATE_H
#include "t_tiles.h"

#define MAX_HAND_TILE_COUNT 18
#define MAX_DORA_TILE_COUNT 13

typedef enum {
	G_SELECTED_MAIN_MENU_OPTION_HAND = 0,
	G_SELECTED_MAIN_MENU_OPTION_DORA,
	G_SELECTED_MAIN_MENU_OPTION_SEAT_WIND,
	G_SELECTED_MAIN_MENU_OPTION_PREVALENT_WIND,
	G_SELECTED_MAIN_MENU_OPTION_COUNT,
} G_Selected_Main_Menu_Option;

typedef enum {
	G_OVERLAYED_MENU_NONE = 0,
	G_OVERLAYED_MENU_HANDSHAPES_SELECTOR,
	G_OVERLAYED_MENU_HANDSHAPE_GROUP_OPEN_CLOSE_SELECTOR,
	G_OVERLAYED_MENU_WINNING_TILE_SELECTOR,
	G_OVERLAYED_MENU_COUNT,
} G_Overlayed_Menu;

struct G_GameState {
	int window_w;
	int window_h;
	float scale;
	double target_fps;
	double target_frametime_ms;
	Uint32 frame_ticks_start;

	int show_help;

	G_Selected_Main_Menu_Option selected_main_menu_option;
	G_Overlayed_Menu overlayed_menu;

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

	int selector_idx;

	HandShapes handshapes;

	HandShape selected_handshape;
};

struct G_GameState *G_gamestate_create(int target_fps, int window_width,
				       int window_height, float scale);

void G_frame_start(struct G_GameState *gamestate);

void G_frame_end(struct G_GameState *gamestate);

void G_destroy(struct G_GameState *gamestate);

void G_increment_main_menu_selector(struct G_GameState *gamestate);

void G_decrement_main_menu_selector(struct G_GameState *gamestate);

void G_decrement_seat_wind(struct G_GameState *gamestate);

void G_increment_seat_wind(struct G_GameState *gamestate);

void G_increment_prevelant_wind(struct G_GameState *gamestate);

void G_decrement_prevelant_wind(struct G_GameState *gamestate);

void G_decrement_handshape_selector(struct G_GameState *gamestate);

void G_increment_handshape_selector(struct G_GameState *gamestate);

void G_group_selector_decrement(struct G_GameState *gamestate);

void G_group_selector_increment(struct G_GameState *gamestate);

void G_group_selector_open_close_toggle(struct G_GameState *gamestate);

// returns 1 if successful
int G_calculate_handshapes(struct G_GameState *gamestate);

void G_window_renderer_resize(SDL_Window *sdl_window,
			      SDL_Renderer *sdl_renderer, int width, int height,
			      float scale);

void G_selected_handshape_set(struct G_GameState *gamestate);

void G_backtrack_menu(struct G_GameState *gamestate);

#endif // !G_GAMESTATE_H
