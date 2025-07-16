#include "g_gamestate.h"

Uint32 frame_ticks;

G_GameState *G_gamestate_create(int target_fps, int window_width, int window_height, float scale)
{
	G_GameState *gamestate = (G_GameState *)malloc(sizeof(G_GameState));
	gamestate->target_fps = target_fps;
	gamestate->target_frametime_ms = (1000.0 / (double)target_fps);
	gamestate->window_w = window_width;
	gamestate->window_h = window_height;
	gamestate->scale = scale;

	gamestate->show_help = 0;
	gamestate->selected_menu = G_MENU_HAND;

	gamestate->hand_tiles_len = 0;
	SDL_memset(gamestate->hand_tiles, T_BACK, sizeof(gamestate->hand_tiles));
	gamestate->dora_tiles_len = 0;
	SDL_memset(gamestate->dora_tiles, T_BACK, sizeof(gamestate->dora_tiles));

	gamestate->seat_wind = T_TON;
	gamestate->prevelant_wind = T_TON;

	gamestate->riichi = 0;
	gamestate->double_riichi = 0;
	gamestate->ippatsu = 0;
	gamestate->haitei = 0;
	gamestate->chankan = 0;
	gamestate->rinshan = 0;

	SDL_memset(gamestate->handshapes.hands, 0, sizeof(gamestate->handshapes.hands));
	gamestate->handshapes.hands_len = 0;
	gamestate->show_confirm_handshape_menu = 0;

	return gamestate;
}

void G_destroy(G_GameState *gamestate)
{
	free(gamestate);
}

void G_frame_start(G_GameState *gamestate)
{
	gamestate->frame_ticks_start = SDL_GetTicks();
}

void G_frame_end(G_GameState *gamestate)
{
	frame_ticks = SDL_GetTicks() - gamestate->frame_ticks_start;
	if (frame_ticks < gamestate->target_frametime_ms) {
		SDL_Delay(gamestate->target_frametime_ms - frame_ticks);
	}
}

void G_window_renderer_resize(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer, int width,
			      int height, float scale)
{
	SDL_SetRenderScale(sdl_renderer, scale, scale);
	SDL_SetWindowSize(sdl_window, width * scale, height * scale);
	SDL_SetWindowPosition(sdl_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void G_increment_menu(G_GameState *gamestate)
{
	switch (gamestate->selected_menu) {
	case G_MENU_HAND:
		gamestate->selected_menu = G_MENU_DORA;
		return;
	case G_MENU_DORA:
		gamestate->selected_menu = G_MENU_SEAT_WIND;
		return;
	case G_MENU_SEAT_WIND:
		gamestate->selected_menu = G_MENU_PREVALENT_WIND;
		return;
	case G_MENU_PREVALENT_WIND:
		gamestate->selected_menu = G_MENU_HAND;
		return;
	case G_MENU_COUNT:
		return;
	default:
		return;
	};
}

void G_decrement_menu(G_GameState *gamestate)
{
	switch (gamestate->selected_menu) {
	case G_MENU_HAND:
		gamestate->selected_menu = G_MENU_PREVALENT_WIND;
		return;
	case G_MENU_DORA:
		gamestate->selected_menu = G_MENU_HAND;
		return;
	case G_MENU_SEAT_WIND:
		gamestate->selected_menu = G_MENU_DORA;
		return;
	case G_MENU_PREVALENT_WIND:
		gamestate->selected_menu = G_MENU_SEAT_WIND;
		return;
	case G_MENU_COUNT:
		return;
	default:
		return;
	};
}

#pragma GCC diagnostic ignored "-Wswitch-enum" //fuck you and yuh mudduh
void G_increment_seat_wind(G_GameState *gamestate)
{
	switch (gamestate->seat_wind) {
	case T_TON:
		gamestate->seat_wind = T_PEI;
		return;
	case T_NAN:
		gamestate->seat_wind = T_TON;
		return;
	case T_SHAA:
		gamestate->seat_wind = T_NAN;
		return;
	case T_PEI:
		gamestate->seat_wind = T_SHAA;
		return;
	default:
		return;
	}
}

#pragma GCC diagnostic ignored "-Wswitch-enum"
void G_decrement_seat_wind(G_GameState *gamestate)
{
	switch (gamestate->seat_wind) {
	case T_TON:
		gamestate->seat_wind = T_NAN;
		return;
	case T_NAN:
		gamestate->seat_wind = T_SHAA;
		return;
	case T_SHAA:
		gamestate->seat_wind = T_PEI;
		return;
	case T_PEI:
		gamestate->seat_wind = T_TON;
		return;
	default:
		return;
	}
}

#pragma GCC diagnostic ignored "-Wswitch-enum"
void G_increment_prevelant_wind(G_GameState *gamestate)
{
	switch (gamestate->prevelant_wind) {
	case T_TON:
		gamestate->prevelant_wind = T_PEI;
		return;
	case T_NAN:
		gamestate->prevelant_wind = T_TON;
		return;
	case T_SHAA:
		gamestate->prevelant_wind = T_NAN;
		return;
	case T_PEI:
		gamestate->prevelant_wind = T_SHAA;
		return;
	default:
		return;
	}
}

#pragma GCC diagnostic ignored "-Wswitch-enum"
void G_decrement_prevelant_wind(G_GameState *gamestate)
{
	switch (gamestate->prevelant_wind) {
	case T_TON:
		gamestate->prevelant_wind = T_NAN;
		return;
	case T_NAN:
		gamestate->prevelant_wind = T_SHAA;
		return;
	case T_SHAA:
		gamestate->prevelant_wind = T_PEI;
		return;
	case T_PEI:
		gamestate->prevelant_wind = T_TON;
		return;
	default:
		return;
	}
}

int G_calculate_handshapes(G_GameState *gamestate)
{
	char tiles[(MAX_HAND_TILE_COUNT * 3) + 1] = "";

	for (int i = 0; i < gamestate->hand_tiles_len; i++) {
		const char *tile_notation = T_TILE_NOTATION[gamestate->hand_tiles[i]];
		strcat(tiles, tile_notation);
		strcat(tiles, " ");
	}

	struct HandShapes *x = C_get_valid_hand_shapes(tiles);
	if (x != NULL) {
		gamestate->handshapes = *x;
		C_free_hand_shapes(x);
		return 1;
	} else {
		gamestate->handshapes.hands_len = 0;
	}
	return 0;
}
