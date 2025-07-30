#include "g_gamestate.h"
#include "t_tiles.h"
#include <stdlib.h>

Uint32 frame_ticks;

struct G_GameState *G_gamestate_create(int target_fps, int window_width,
				       int window_height, float scale)
{
	struct G_GameState *gamestate = malloc(sizeof(struct G_GameState));
	gamestate->target_fps = target_fps;
	gamestate->target_frametime_ms = (1000.0 / (double)target_fps);
	gamestate->window_w = window_width;
	gamestate->window_h = window_height;
	gamestate->scale = scale;

	gamestate->show_help = false;
	gamestate->selected_main_menu_option = G_SELECTED_MAIN_MENU_OPTION_HAND;
	gamestate->overlayed_menu = G_OVERLAYED_MENU_NONE;

	gamestate->hand_tiles_len = 0;
	memset(gamestate->hand_tiles, T_TILE_BACK,
	       sizeof(gamestate->hand_tiles));
	gamestate->dora_tiles_len = 0;
	memset(gamestate->dora_tiles, T_TILE_BACK,
	       sizeof(gamestate->dora_tiles));

	gamestate->seat_wind = T_TILE_TON;
	gamestate->prevelant_wind = T_TILE_TON;

	gamestate->riichi = false;
	gamestate->double_riichi = false;
	gamestate->ippatsu = false;
	gamestate->haitei = false;
	gamestate->chankan = false;
	gamestate->rinshan = false;

	memset(gamestate->handshapes.hands, 0,
	       sizeof(gamestate->handshapes.hands));
	gamestate->handshapes.hands_len = 0;

	gamestate->selector_idx = 0;
	memset(gamestate->selected_handshape.groups, 0,
	       sizeof(gamestate->selected_handshape.groups));
	gamestate->selected_handshape.group_count = 0;

	return gamestate;
}

void G_destroy(struct G_GameState *gamestate)
{
	free(gamestate);
}

void G_frame_start(struct G_GameState *gamestate)
{
	gamestate->frame_ticks_start = SDL_GetTicks();
}

void G_frame_end(struct G_GameState *gamestate)
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

void G_increment_main_menu_selector(struct G_GameState *gamestate)
{
	gamestate->selected_main_menu_option++;
	if (gamestate->selected_main_menu_option ==
	    G_SELECTED_MAIN_MENU_OPTION_COUNT) {
		gamestate->selected_main_menu_option =
			G_SELECTED_MAIN_MENU_OPTION_HAND;
	}
}

void G_decrement_main_menu_selector(struct G_GameState *gamestate)
{
	if (gamestate->selected_main_menu_option ==
	    G_SELECTED_MAIN_MENU_OPTION_HAND) {
		gamestate->selected_main_menu_option =
			G_SELECTED_MAIN_MENU_OPTION_PREVALENT_WIND;
	} else {
		gamestate->selected_main_menu_option--;
	}
}

void G_decrement_seat_wind(struct G_GameState *gamestate)
{
	if (gamestate->seat_wind == T_TILE_TON) {
		gamestate->seat_wind = T_TILE_PEI;
	} else {
		gamestate->seat_wind--;
	}
}

void G_increment_seat_wind(struct G_GameState *gamestate)
{
	if (gamestate->seat_wind == T_TILE_PEI) {
		gamestate->seat_wind = T_TILE_TON;
	} else {
		gamestate->seat_wind++;
	}
}

void G_increment_prevelant_wind(struct G_GameState *gamestate)
{
	if (gamestate->prevelant_wind == T_TILE_TON) {
		gamestate->prevelant_wind = T_TILE_PEI;
	} else {
		gamestate->prevelant_wind--;
	}
}

void G_decrement_prevelant_wind(struct G_GameState *gamestate)
{
	if (gamestate->prevelant_wind == T_TILE_PEI) {
		gamestate->prevelant_wind = T_TILE_TON;
	} else {
		gamestate->prevelant_wind++;
	}
}

int G_calculate_handshapes(struct G_GameState *gamestate)
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

void G_decrement_handshape_selector(struct G_GameState *gamestate)
{
	gamestate->selector_idx++;
	if (gamestate->selector_idx >= (int)gamestate->handshapes.hands_len) {
		gamestate->selector_idx = 0;
	}
}

void G_increment_handshape_selector(struct G_GameState *gamestate)
{
	gamestate->selector_idx--;
	if (gamestate->selector_idx < 0) {
		gamestate->selector_idx = gamestate->handshapes.hands_len - 1;
	}
}

void G_group_selector_decrement(struct G_GameState *gamestate)
{
	gamestate->selector_idx++;
	if (gamestate->selector_idx >=
	    (int)gamestate->selected_handshape.group_count) {
		gamestate->selector_idx = 0;
	}
}

void G_group_selector_increment(struct G_GameState *gamestate)
{
	gamestate->selector_idx--;
	if (gamestate->selector_idx < 0) {
		gamestate->selector_idx =
			gamestate->selected_handshape.group_count - 1;
	}
}

void G_selected_handshape_set(struct G_GameState *gamestate)
{
	gamestate->selected_handshape =
		gamestate->handshapes.hands[gamestate->selector_idx];
}

void G_group_selector_open_close_toggle(struct G_GameState *gamestate)
{
	gamestate->selected_handshape.groups[gamestate->selector_idx].isopen =
		!gamestate->selected_handshape.groups[gamestate->selector_idx]
			 .isopen;
}

void G_backtrack_menu(struct G_GameState *gamestate)
{
	gamestate->selector_idx = 0;
	switch (gamestate->overlayed_menu) {
	case G_OVERLAYED_MENU_NONE:
		break;
	case G_OVERLAYED_MENU_HANDSHAPES_SELECTOR:
		gamestate->selector_idx = 0;
		gamestate->overlayed_menu = G_OVERLAYED_MENU_NONE;
		break;
	case G_OVERLAYED_MENU_HANDSHAPE_GROUP_OPEN_CLOSE_SELECTOR:
		gamestate->selector_idx = 0;
		if (gamestate->handshapes.hands_len == 1) {
			gamestate->overlayed_menu = G_OVERLAYED_MENU_NONE;
		} else {
			gamestate->overlayed_menu =
				G_OVERLAYED_MENU_HANDSHAPES_SELECTOR;
		}
		break;
	case G_OVERLAYED_MENU_WINNING_TILE_SELECTOR:
		gamestate->selector_idx = 0;
		if (gamestate->selected_handshape.group_count >= 7) {
			gamestate->overlayed_menu = G_OVERLAYED_MENU_NONE;
		} else {
			gamestate->overlayed_menu =
				G_OVERLAYED_MENU_HANDSHAPE_GROUP_OPEN_CLOSE_SELECTOR;
		}
		break;
	case G_OVERLAYED_MENU_COUNT:
		break;
	default:
		break;
	}
}
