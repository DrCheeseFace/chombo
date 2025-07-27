#include "g_gamestate.h"
#include "t_tiles.h"

Uint32 frame_ticks;

G_GameState *G_gamestate_create(int target_fps, int window_width,
				int window_height, float scale)
{
	G_GameState *gamestate = (G_GameState *)malloc(sizeof(G_GameState));
	gamestate->target_fps = target_fps;
	gamestate->target_frametime_ms = (1000.0 / (double)target_fps);
	gamestate->window_w = window_width;
	gamestate->window_h = window_height;
	gamestate->scale = scale;

	gamestate->show_help = 0;
	gamestate->selected_main_menu_option = G_SELECTED_MAIN_MENU_OPTION_HAND;
	gamestate->overlayed_menu = G_OVERLAYED_MENU_NONE;

	gamestate->hand_tiles_len = 0;
	memset(gamestate->hand_tiles, T_BACK, sizeof(gamestate->hand_tiles));
	gamestate->dora_tiles_len = 0;
	memset(gamestate->dora_tiles, T_BACK, sizeof(gamestate->dora_tiles));

	gamestate->seat_wind = T_TON;
	gamestate->prevelant_wind = T_TON;

	gamestate->riichi = 0;
	gamestate->double_riichi = 0;
	gamestate->ippatsu = 0;
	gamestate->haitei = 0;
	gamestate->chankan = 0;
	gamestate->rinshan = 0;

	memset(gamestate->handshapes.hands, 0,
	       sizeof(gamestate->handshapes.hands));
	gamestate->handshapes.hands_len = 0;

	gamestate->handshape_selector_idx = 0;
	memset(gamestate->selected_handshape.groups, 0,
	       sizeof(gamestate->selected_handshape.groups));
	gamestate->selected_handshape.group_count = 0;

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

void G_window_renderer_resize(SDL_Window *sdl_window,
			      SDL_Renderer *sdl_renderer, int width, int height,
			      float scale)
{
	SDL_SetRenderScale(sdl_renderer, scale, scale);
	SDL_SetWindowSize(sdl_window, width * scale, height * scale);
	SDL_SetWindowPosition(sdl_window, SDL_WINDOWPOS_CENTERED,
			      SDL_WINDOWPOS_CENTERED);
}

void G_increment_main_menu_selector(G_GameState *gamestate)
{
	gamestate->selected_main_menu_option++;
	if (gamestate->selected_main_menu_option ==
	    G_SELECTED_MAIN_MENU_OPTION_COUNT) {
		gamestate->selected_main_menu_option =
			G_SELECTED_MAIN_MENU_OPTION_HAND;
	}
}

void G_decrement_main_menu_selector(G_GameState *gamestate)
{
	if (gamestate->selected_main_menu_option ==
	    G_SELECTED_MAIN_MENU_OPTION_HAND) {
		gamestate->selected_main_menu_option =
			G_SELECTED_MAIN_MENU_OPTION_PREVALENT_WIND;
	} else {
		gamestate->selected_main_menu_option--;
	}
}

void G_decrement_seat_wind(G_GameState *gamestate)
{
	if (gamestate->seat_wind == T_TON) {
		gamestate->seat_wind = T_PEI;
	} else {
		gamestate->seat_wind--;
	}
}

void G_increment_seat_wind(G_GameState *gamestate)
{
	if (gamestate->seat_wind == T_PEI) {
		gamestate->seat_wind = T_TON;
	} else {
		gamestate->seat_wind++;
	}
}

void G_increment_prevelant_wind(G_GameState *gamestate)
{
	if (gamestate->prevelant_wind == T_TON) {
		gamestate->prevelant_wind = T_PEI;
	} else {
		gamestate->prevelant_wind--;
	}
}

void G_decrement_prevelant_wind(G_GameState *gamestate)
{
	if (gamestate->prevelant_wind == T_PEI) {
		gamestate->prevelant_wind = T_TON;
	} else {
		gamestate->prevelant_wind++;
	}
}

int G_calculate_handshapes(G_GameState *gamestate)
{
	char tiles[(MAX_HAND_TILE_COUNT * 3) + 1] = "";

	for (int i = 0; i < gamestate->hand_tiles_len; i++) {
		const char *tile_notation =
			T_TILE_NOTATION[gamestate->hand_tiles[i]];
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

void G_decrement_handshape_selector(G_GameState *gamestate)
{
	gamestate->handshape_selector_idx++;
	if (gamestate->handshape_selector_idx >=
	    (int)gamestate->handshapes.hands_len) {
		gamestate->handshape_selector_idx = 0;
	}
}

void G_increment_handshape_selector(G_GameState *gamestate)
{
	gamestate->handshape_selector_idx--;
	if (gamestate->handshape_selector_idx < 0) {
		gamestate->handshape_selector_idx =
			gamestate->handshapes.hands_len - 1;
	}
}
