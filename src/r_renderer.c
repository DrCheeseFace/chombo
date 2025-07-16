#include "g_gamestate.h"
#include "l_letter.h"
#include <stdio.h>

SDL_Renderer *sdl_renderer;
int screen_width, screen_height;
float scale;

SDL_Renderer *R_create(SDL_Window *window, int width, int height)
{
	sdl_renderer = SDL_CreateRenderer(window, NULL);
	SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl_renderer);

	screen_width = width;
	screen_height = height;
	scale = 0.5;

	T_tiles_init(sdl_renderer);

	return sdl_renderer;
}

void R_destroy(SDL_Renderer *sdl_renderer)
{
	T_tiles_destroy();
	SDL_DestroyRenderer(sdl_renderer);
}

int R_draw_help(void)
{
	SDL_FRect help_outline = {
		.w = screen_width - 50, .h = screen_height - 50, .x = 25, .y = 25
	};
	if (!SDL_SetRenderDrawColor(sdl_renderer, L_COLORS[L_COLOR_WHITE].r,
				    L_COLORS[L_COLOR_WHITE].g, L_COLORS[L_COLOR_WHITE].b,
				    L_COLORS[L_COLOR_WHITE].a))
		return 1;

	if (!SDL_RenderFillRect(sdl_renderer, &help_outline))
		return 1;
	if (!SDL_SetRenderDrawColor(sdl_renderer, L_COLORS[L_COLOR_MENU_BACKDROP].r,
				    L_COLORS[L_COLOR_MENU_BACKDROP].g,
				    L_COLORS[L_COLOR_MENU_BACKDROP].b,
				    L_COLORS[L_COLOR_MENU_BACKDROP].a)) {
		return 1;
	}

	SDL_FRect help_background = {
		.w = screen_width - 55, .h = screen_height - 55, .x = 27.5, .y = 27.5
	};
	if (!SDL_RenderFillRect(sdl_renderer, &help_background))
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_0_9, (struct SDL_Point){ 80, 140 }) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_MAN1, (struct SDL_Point){ 280, 150 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_SHIFT, (struct SDL_Point){ 80, 240 }) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_PIN1, (struct SDL_Point){ 280, 250 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_CTRL, (struct SDL_Point){ 80, 340 }) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_SOU1, (struct SDL_Point){ 280, 350 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_E, (struct SDL_Point){ 80, 440 }) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_TON, (struct SDL_Point){ 280, 450 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_S, (struct SDL_Point){ 80, 540 }) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_NAN, (struct SDL_Point){ 280, 550 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_W, (struct SDL_Point){ 80, 640 }) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_SHAA, (struct SDL_Point){ 280, 650 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_S, (struct SDL_Point){ 80, 740 }) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_PEI, (struct SDL_Point){ 280, 750 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_C, (struct SDL_Point){ 420, 140 }) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_CHUN, (struct SDL_Point){ 500, 150 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_H, (struct SDL_Point){ 420, 240 }) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_HAKU, (struct SDL_Point){ 500, 250 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_G, (struct SDL_Point){ 420, 340 }) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_HATSU, (struct SDL_Point){ 500, 350 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, L_TEXT_HELP_RIICHI, (struct SDL_Point){ 760, 140 }) != 0)
		return 1;
	if (L_draw(sdl_renderer, L_TEXT_HELP_DOUBLE_RIICHI, (struct SDL_Point){ 760, 240 }) != 0)
		return 1;
	if (L_draw(sdl_renderer, L_TEXT_HELP_IPPATSU, (struct SDL_Point){ 760, 340 }) != 0)
		return 1;
	if (L_draw(sdl_renderer, L_TEXT_HELP_HAITEI, (struct SDL_Point){ 760, 440 }) != 0)
		return 1;
	if (L_draw(sdl_renderer, L_TEXT_HELP_CHANKAN, (struct SDL_Point){ 760, 540 }) != 0)
		return 1;
	if (L_draw(sdl_renderer, L_TEXT_HELP_RINSHAN, (struct SDL_Point){ 760, 640 }) != 0)
		return 1;
	if (L_draw(sdl_renderer, L_TEXT_HELP_SPACE_TOGGLE, (struct SDL_Point){ 760, 740 }) != 0)
		return 1;

	return 0;
}

int R_draw_hand(SDL_Renderer *sdl_renderer, G_GameState gamestate)
{
	int x = 10;
	for (int i = 0; i < MAX_HAND_TILE_COUNT; i++) {
		if (T_tile_draw(sdl_renderer, gamestate.hand_tiles[i], (struct SDL_Point){ x, 17 },
				21)) {
			return 1;
		}
		x += 88;
	}
	if (gamestate.selected_menu == G_MENU_HAND) {
		if (L_draw(sdl_renderer, L_TEXT_HAND_LABEL_SELECTED,
			   (struct SDL_Point){ 10, 130 }) != 0)
			return 1;
	} else {
		if (L_draw(sdl_renderer, L_TEXT_HAND_LABEL, (struct SDL_Point){ 10, 130 }) != 0)
			return 1;
	}
	if (gamestate.handshapes.hands_len != 0) {
		if (L_draw(sdl_renderer, L_TEXT_HAND_VALID, (struct SDL_Point){ 200, 130 }) != 0)
			return 1;
	} else {
		if (L_draw(sdl_renderer, L_TEXT_HAND_INVALID, (struct SDL_Point){ 200, 130 }) != 0)
			return 1;
	}
	return 0;
}

int R_draw_dora(SDL_Renderer *sdl_renderer, G_GameState gamestate)
{
	int x = 10;
	for (int i = 0; i < MAX_DORA_TILE_COUNT; i++) {
		if (T_tile_draw(sdl_renderer, gamestate.dora_tiles[i], (struct SDL_Point){ x, 190 },
				21)) {
			return 1;
		}
		x += 88;
	}
	if (gamestate.selected_menu == G_MENU_DORA) {
		if (L_draw(sdl_renderer, L_TEXT_DORA_LABEL_SELECTED,
			   (struct SDL_Point){ 10, 303 }) != 0)
			return 1;
	} else {
		if (L_draw(sdl_renderer, L_TEXT_DORA_LABEL, (struct SDL_Point){ 10, 303 }) != 0)
			return 1;
	}
	return 0;
}

int R_draw_seat_wind_selector(SDL_Renderer *sdl_renderer, G_GameState gamestate)
{
	const T_Tile wind_tiles[4] = { T_TON, T_NAN, T_SHAA, T_PEI };

	int x = 10;
	for (int i = 0; i < 4; i++) {
		if (gamestate.seat_wind == wind_tiles[i]) {
			if (T_tile_draw(sdl_renderer, wind_tiles[i], (struct SDL_Point){ x, 373 },
					21)) {
				return 1;
			}
		} else if (T_tile_draw(sdl_renderer, wind_tiles[i], (struct SDL_Point){ x, 393 },
				       21)) {
			return 1;
		}
		x += 100;
	}

	if (gamestate.selected_menu == G_MENU_SEAT_WIND) {
		if (L_draw(sdl_renderer, L_TEXT_DORA_SEAT_WIND_SELECTED,
			   (struct SDL_Point){ 10, 516 }) != 0)
			return 1;
	} else if (L_draw(sdl_renderer, L_TEXT_DORA_SEAT_WIND, (struct SDL_Point){ 10, 516 }) != 0)
		return 1;

	return 0;
}

int R_draw_prevelant_wind_selector(SDL_Renderer *sdl_renderer, G_GameState gamestate)
{
	const T_Tile wind_tiles[4] = { T_TON, T_NAN, T_SHAA, T_PEI };

	int x = 10;
	for (int i = 0; i < 4; i++) {
		if (gamestate.prevelant_wind == wind_tiles[i]) {
			if (T_tile_draw(sdl_renderer, wind_tiles[i], (struct SDL_Point){ x, 586 },
					21)) {
				return 1;
			}
		} else if (T_tile_draw(sdl_renderer, wind_tiles[i], (struct SDL_Point){ x, 606 },
				       21)) {
			return 1;
		}
		x += 100;
	}

	if (gamestate.selected_menu == G_MENU_PREVALENT_WIND) {
		if (L_draw(sdl_renderer, L_TEXT_DORA_PREVELANT_WIND_SELECTED,
			   (struct SDL_Point){ 10, 729 }) != 0)
			return 1;
	} else if (L_draw(sdl_renderer, L_TEXT_DORA_PREVELANT_WIND,
			  (struct SDL_Point){ 10, 729 }) != 0)
		return 1;

	return 0;
}

int R_draw_conditions(SDL_Renderer *sdl_renderer, G_GameState gamestate)
{
	int y = 373;
	if (gamestate.riichi) {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_RIICHI_ON,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	} else {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_RIICHI_OFF,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	}
	y += 80;
	if (gamestate.double_riichi) {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_DOUBLE_RIICHI_ON,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	} else {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_DOUBLE_RIICHI_OFF,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	}
	y += 80;
	if (gamestate.ippatsu) {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_IPPATSU_ON,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	} else {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_IPPATSU_OFF,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	}
	y += 80;
	if (gamestate.haitei) {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_HAITEI_ON,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	} else {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_HAITEI_OFF,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	}
	y += 80;
	if (gamestate.chankan) {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_CHANKAN_ON,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	} else {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_CHANKAN_OFF,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	}
	y += 80;
	if (gamestate.rinshan) {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_RINSHAN_ON,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	} else {
		if (L_draw(sdl_renderer, L_TEXT_CONDITION_RINSHAN_OFF,
			   (struct SDL_Point){ 500, y }) != 0)
			return 1;
	}

	return 0;
}

int R_gamestate_draw(SDL_Renderer *sdl_renderer, SDL_Window *sdl_window, G_GameState gamestate)
{
	if (gamestate.scale != scale) {
		G_window_renderer_resize(sdl_window, sdl_renderer, gamestate.window_w,
					 gamestate.window_h, gamestate.scale);
		scale = gamestate.scale;
	}

	if (!SDL_SetRenderDrawColor(sdl_renderer, L_COLORS[L_COLOR_BACKDROP].r,
				    L_COLORS[L_COLOR_BACKDROP].g, L_COLORS[L_COLOR_BACKDROP].b,
				    L_COLORS[L_COLOR_BACKDROP].a)) {
		fprintf(stderr, "Failed to set render draw color: %s\n", SDL_GetError());
		return 1;
	}

	if (!SDL_RenderClear(sdl_renderer)) {
		fprintf(stderr, "Failed to clear renderer: %s\n", SDL_GetError());
		return 1;
	}

	if (R_draw_hand(sdl_renderer, gamestate) != 0)
		return 1;
	if (R_draw_dora(sdl_renderer, gamestate) != 0)
		return 1;
	if (R_draw_seat_wind_selector(sdl_renderer, gamestate) != 0)
		return 1;
	if (R_draw_prevelant_wind_selector(sdl_renderer, gamestate) != 0)
		return 1;
	if (R_draw_conditions(sdl_renderer, gamestate) != 0)
		return 1;

	if (gamestate.show_help == 1) {
		if (R_draw_help() != 0) {
			return 1;
		}
	} else {
		if (L_draw(sdl_renderer, L_TEXT_BOTTOM_HELP,
			   (struct SDL_Point){ 4, screen_height - 50 }) != 0)
			return 1;
	}

	SDL_RenderPresent(sdl_renderer);
	return 0;
}
