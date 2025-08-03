#include "g_gamestate.h"
#include "l_letter.h"
#include <stdio.h>

SDL_Renderer *sdl_renderer;
int screen_width, screen_height;
float scale;

SDL_Renderer *R_create(SDL_Window *window, int width, int height)
{
	sdl_renderer = SDL_CreateRenderer(window, NULL);

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

bool R_overlay_menu_window_draw(L_Colors outline_colour)
{
	if (!SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_MUL)) {
		fprintf(stderr,
			"Failed to set render blend mode to SDL_BLENDMODE_MUL: %s\n",
			SDL_GetError());
		return true;
	}

	SDL_FRect outline = { .w = screen_width - 50,
			      .h = screen_height - 50,
			      .x = 25,
			      .y = 25 };
	if (!SDL_SetRenderDrawColor(sdl_renderer, L_COLORS[outline_colour].r,
				    L_COLORS[outline_colour].g,
				    L_COLORS[outline_colour].b,
				    L_COLORS[outline_colour].a))
		return true;

	if (!SDL_RenderFillRect(sdl_renderer, &outline))
		return true;

	if (!SDL_SetRenderDrawColor(sdl_renderer,
				    L_COLORS[L_COLOR_MENU_BACKDROP].r,
				    L_COLORS[L_COLOR_MENU_BACKDROP].g,
				    L_COLORS[L_COLOR_MENU_BACKDROP].b,
				    L_COLORS[L_COLOR_MENU_BACKDROP].a))
		return true;

	SDL_FRect background = { .w = screen_width - 55,
				 .h = screen_height - 55,
				 .x = 27.5,
				 .y = 27.5 };
	if (!SDL_RenderFillRect(sdl_renderer, &background))
		return true;

	return false;
}

bool R_help_draw(struct G_GameState gamestate)
{
	if (!gamestate.show_help) {
		if (L_draw(sdl_renderer, L_TEXT_BOTTOM_HELP,
			   (struct SDL_Point){ 4, screen_height - 50 }))
			return true;
		return false;
	}

	if (R_overlay_menu_window_draw(L_COLOR_WHITE))
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_0_9,
		   (struct SDL_Point){ 80, 140 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_MAN1,
			(struct SDL_Point){ 280, 150 }, 16) != 0)
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_SHIFT,
		   (struct SDL_Point){ 80, 240 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_PIN1,
			(struct SDL_Point){ 280, 250 }, 16) != 0)
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_CTRL,
		   (struct SDL_Point){ 80, 340 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_SOU1,
			(struct SDL_Point){ 280, 350 }, 16) != 0)
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_E, (struct SDL_Point){ 80, 440 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_TON,
			(struct SDL_Point){ 280, 450 }, 16) != 0)
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_S, (struct SDL_Point){ 80, 540 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_NAN,
			(struct SDL_Point){ 280, 550 }, 16) != 0)
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_W, (struct SDL_Point){ 80, 640 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_SHAA,
			(struct SDL_Point){ 280, 650 }, 16) != 0)
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_S, (struct SDL_Point){ 80, 740 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_PEI,
			(struct SDL_Point){ 280, 750 }, 16) != 0)
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_C, (struct SDL_Point){ 420, 140 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_CHUN,
			(struct SDL_Point){ 500, 150 }, 16) != 0)
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_H, (struct SDL_Point){ 420, 240 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_HAKU,
			(struct SDL_Point){ 500, 250 }, 16) != 0)
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_G, (struct SDL_Point){ 420, 340 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_HATSU,
			(struct SDL_Point){ 500, 350 }, 16) != 0)
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HELP_RIICHI,
		   (struct SDL_Point){ 760, 140 }))
		return true;
	if (L_draw(sdl_renderer, L_TEXT_HELP_DOUBLE_RIICHI,
		   (struct SDL_Point){ 760, 240 }))
		return true;
	if (L_draw(sdl_renderer, L_TEXT_HELP_IPPATSU,
		   (struct SDL_Point){ 760, 340 }))
		return true;
	if (L_draw(sdl_renderer, L_TEXT_HELP_HAITEI,
		   (struct SDL_Point){ 760, 440 }))
		return true;
	if (L_draw(sdl_renderer, L_TEXT_HELP_CHANKAN,
		   (struct SDL_Point){ 760, 540 }))
		return true;
	if (L_draw(sdl_renderer, L_TEXT_HELP_RINSHAN,
		   (struct SDL_Point){ 760, 640 }))
		return true;
	if (L_draw(sdl_renderer, L_TEXT_HELP_SPACE_TOGGLE,
		   (struct SDL_Point){ 760, 740 }))
		return true;

	return false;
}

bool R_hand_draw(struct G_GameState gamestate)
{
	const int tile_size = 21;
	int x = 10;
	for (int i = 0; i < MAX_HAND_TILE_COUNT; i++) {
		if (T_tile_draw(sdl_renderer, gamestate.hand_tiles[i],
				(struct SDL_Point){ x, 17 }, tile_size)) {
			return true;
		}
		x += ((tile_size * T_TILE_WIDTH_RATIO) + 4);
	}
	if (L_draw(sdl_renderer,
		   gamestate.selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_HAND ?
			   L_TEXT_HAND_LABEL_SELECTED :
			   L_TEXT_HAND_LABEL,
		   (struct SDL_Point){ 10, 130 }))
		return true;
	if (L_draw(sdl_renderer,
		   gamestate.handshapes.hands_len != 0 ? L_TEXT_HAND_VALID :
							 L_TEXT_HAND_INVALID,
		   (struct SDL_Point){ 200, 130 }))
		return true;
	return false;
}

bool R_dora_draw(struct G_GameState gamestate)
{
	const int tile_size = 21;

	int x = 10;
	for (int i = 0; i < MAX_DORA_TILE_COUNT; i++) {
		if (T_tile_draw(sdl_renderer, gamestate.dora_tiles[i],
				(struct SDL_Point){ x, 190 }, tile_size)) {
			return true;
		}
		x += ((tile_size * T_TILE_WIDTH_RATIO) + 4);
	}
	if (L_draw(sdl_renderer,
		   gamestate.selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA ?
			   L_TEXT_DORA_LABEL_SELECTED :
			   L_TEXT_DORA_LABEL,
		   (struct SDL_Point){ 10, 303 }))
		return true;
	return false;
}

bool R_seat_wind_selector_draw(struct G_GameState gamestate)
{
	const T_Tile wind_tiles[4] = { T_TILE_TON, T_TILE_NAN, T_TILE_SHAA,
				       T_TILE_PEI };
	const int tile_size = 21;

	int x = 10;
	for (int i = 0; i < 4; i++) {
		if (T_tile_draw(sdl_renderer, wind_tiles[i],
				(struct SDL_Point){
					x,
					gamestate.seat_wind == wind_tiles[i] ?
						373 :
						393 },
				tile_size)) {
			return true;
		}
		x += ((tile_size * T_TILE_WIDTH_RATIO) + 16);
	}

	if (L_draw(sdl_renderer,
		   gamestate.selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_SEAT_WIND ?
			   L_TEXT_DORA_SEAT_WIND_SELECTED :
			   L_TEXT_DORA_SEAT_WIND,
		   (struct SDL_Point){ 10, 516 }))
		return true;

	return false;
}

bool R_prevelant_wind_selector_draw(struct G_GameState gamestate)
{
	const T_Tile wind_tiles[4] = { T_TILE_TON, T_TILE_NAN, T_TILE_SHAA,
				       T_TILE_PEI };
	const int tile_size = 21;

	int x = 10;
	for (int i = 0; i < 4; i++) {
		if (T_tile_draw(sdl_renderer, wind_tiles[i],
				(struct SDL_Point){
					x, gamestate.prevelant_wind ==
							   wind_tiles[i] ?
						   586 :
						   606 },
				tile_size)) {
			return true;
		}
		x += ((tile_size * T_TILE_WIDTH_RATIO) + 16);
	}

	if (L_draw(sdl_renderer,
		   gamestate.selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_PREVALENT_WIND ?
			   L_TEXT_DORA_PREVELANT_WIND_SELECTED :
			   L_TEXT_DORA_PREVELANT_WIND,
		   (struct SDL_Point){ 10, 729 }))
		return true;
	return false;
}

bool R_conditions_draw(struct G_GameState gamestate)
{
	int y = 330;
	if (L_draw(sdl_renderer,
		   gamestate.conditions.tsumo ? L_TEXT_CONDITION_TSUMO_ON :
						L_TEXT_CONDITION_TSUMO_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.conditions.riichi ? L_TEXT_CONDITION_RIICHI_ON :
						 L_TEXT_CONDITION_RIICHI_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.conditions.double_riichi ?
			   L_TEXT_CONDITION_DOUBLE_RIICHI_ON :
			   L_TEXT_CONDITION_DOUBLE_RIICHI_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.conditions.ippatsu ? L_TEXT_CONDITION_IPPATSU_ON :
						  L_TEXT_CONDITION_IPPATSU_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.conditions.haitei ? L_TEXT_CONDITION_HAITEI_ON :
						 L_TEXT_CONDITION_HAITEI_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.conditions.chankan ? L_TEXT_CONDITION_CHANKAN_ON :
						  L_TEXT_CONDITION_CHANKAN_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.conditions.rinshan ? L_TEXT_CONDITION_RINSHAN_ON :
						  L_TEXT_CONDITION_RINSHAN_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;

	if (L_draw(sdl_renderer,
		   gamestate.conditions.tenhou ? L_TEXT_CONDITION_TENHOU_ON :
						 L_TEXT_CONDITION_TENHOU_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;

	return false;
}

bool R_honba_draw(struct G_GameState gamestate)
{
	if (L_draw(sdl_renderer,
		   gamestate.selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_HONBA ?
			   L_TEXT_HONBA_ON :
			   L_TEXT_HONBA_OFF,
		   (struct SDL_Point){ 10, 800 }))
		return true;

	if (L_draw(sdl_renderer, L_TEXT_HONBA_COUNT,
		   (struct SDL_Point){ 270, 790 }))
		return true;

	return false;
}

bool R_main_menu_draw(struct G_GameState gamestate)
{
	if (!SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_NONE)) {
		fprintf(stderr,
			"Failed to set render blend mode to SDL_BLENDMODE_NONE: %s\n",
			SDL_GetError());
		return true;
	}

	if (!SDL_SetRenderDrawColor(sdl_renderer, L_COLORS[L_COLOR_BACKDROP].r,
				    L_COLORS[L_COLOR_BACKDROP].g,
				    L_COLORS[L_COLOR_BACKDROP].b,
				    L_COLORS[L_COLOR_BACKDROP].a)) {
		fprintf(stderr, "Failed to set render draw color: %s\n",
			SDL_GetError());
		return true;
	}

	if (!SDL_RenderClear(sdl_renderer)) {
		fprintf(stderr, "Failed to clear renderer: %s\n",
			SDL_GetError());
		return true;
	}

	if (R_hand_draw(gamestate))
		return true;
	if (R_dora_draw(gamestate))
		return true;
	if (R_seat_wind_selector_draw(gamestate))
		return true;
	if (R_prevelant_wind_selector_draw(gamestate))
		return true;
	if (R_conditions_draw(gamestate))
		return true;
	if (R_honba_draw(gamestate))
		return true;

	return false;
}

bool R_handshapes_selector_draw(struct G_GameState gamestate)
{
	if (R_overlay_menu_window_draw(L_COLOR_RED))
		return true;
	const int tile_size = 19;

	int y = 100;
	for (int i = 0; i < (int)gamestate.handshapes.hands_len; i++) {
		int x = 80;
		for (size_t j = 0;
		     j < gamestate.handshapes.hands[i].group_count; j++) {
			for (size_t k = 0;
			     k <
			     gamestate.handshapes.hands[i].groups[j].tiles_len;
			     k++) {
				if (T_tile_draw(sdl_renderer,
						T_mtile_to_ttile(
							gamestate.handshapes
								.hands[i]
								.groups[j]
								.tiles[k]),
						(struct SDL_Point){ x, y },
						tile_size)) {
					return true;
				}

				x += ((tile_size * T_TILE_WIDTH_RATIO) + 4);
			}
			x += 10;
		}

		y += ((tile_size * T_TILE_HEIGHT_RATIO) + 10);

		if (gamestate.selector_idx == i) {
			if (!SDL_SetRenderDrawBlendMode(sdl_renderer,
							SDL_BLENDMODE_NONE)) {
				fprintf(stderr,
					"Failed to set render blend mode to SDL_BLENDMODE_NONE: %s\n",
					SDL_GetError());
				return true;
			}
			SDL_SetRenderDrawColor(sdl_renderer,
					       L_COLORS[L_COLOR_WHITE].r,
					       L_COLORS[L_COLOR_WHITE].g,
					       L_COLORS[L_COLOR_WHITE].b,
					       L_COLORS[L_COLOR_WHITE].a);
			SDL_RenderFillRects(
				sdl_renderer,
				&(struct SDL_FRect){ 80, y, x - 80, 5 }, 1);
		}
		y += 80;
	}

	return false;
}

bool R_handshape_group_open_close_selector_draw(struct G_GameState gamestate)
{
	if (R_overlay_menu_window_draw(L_COLOR_BLUE))
		return true;

	const int tile_size = 24;

	int y = 80;
	for (int i = 0; i < (int)gamestate.selected_handshape.group_count;
	     i++) {
		int x = 80;
		for (size_t j = 0;
		     j < gamestate.selected_handshape.groups[i].tiles_len;
		     j++) {
			if (T_tile_draw(sdl_renderer,
					T_mtile_to_ttile(
						gamestate.selected_handshape
							.groups[i]
							.tiles[j]),
					(struct SDL_Point){ x, y },
					tile_size)) {
				return true;
			}
			x += ((tile_size * T_TILE_WIDTH_RATIO) + 12);
		}
		x += 100;

		if (L_draw(sdl_renderer,
			   gamestate.selected_handshape.groups[i].isopen ?
				   L_TEXT_GROUP_OPEN :
				   L_TEXT_GROUP_CLOSED,
			   (struct SDL_Point){ gamestate.window_w / 2, y }))
			return true;

		y += 140;

		if (gamestate.selector_idx == i) {
			if (!SDL_SetRenderDrawBlendMode(sdl_renderer,
							SDL_BLENDMODE_NONE)) {
				fprintf(stderr,
					"Failed to set render blend mode to SDL_BLENDMODE_NONE: %s\n",
					SDL_GetError());
				return true;
			}
			SDL_SetRenderDrawColor(sdl_renderer,
					       L_COLORS[L_COLOR_WHITE].r,
					       L_COLORS[L_COLOR_WHITE].g,
					       L_COLORS[L_COLOR_WHITE].b,
					       L_COLORS[L_COLOR_WHITE].a);
			SDL_RenderFillRects(
				sdl_renderer,
				&(struct SDL_FRect){
					80, y,
					(float)gamestate.window_w / 4 * 3, 5 },
				1);
		}

		y += 40;
	}
	return false;
}

bool R_winning_tile_selector_draw(struct G_GameState gamestate)
{
	if (R_overlay_menu_window_draw(L_COLOR_MAGENTA))
		return true;

	const int tile_size = 30;

	int tile_idx = 0;
	int x = 80;
	int y = 80;
	for (int i = 0; i < (int)gamestate.selected_handshape.group_count;
	     i++) {
		for (size_t j = 0;
		     j < gamestate.selected_handshape.groups[i].tiles_len;
		     j++) {
			if (T_tile_draw(sdl_renderer,
					T_mtile_to_ttile(
						gamestate.selected_handshape
							.groups[i]
							.tiles[j]),
					(struct SDL_Point){
						x, gamestate.selector_idx ==
								   tile_idx ?
							   y - 20 :
							   y },
					tile_size)) {
				return true;
			}
			tile_idx++;
			x += tile_size * T_TILE_WIDTH_RATIO + 10;
		}

		x += tile_size * T_TILE_WIDTH_RATIO + 10;

		if (x + (tile_size * T_TILE_WIDTH_RATIO) + 40 >
		    gamestate.window_w) {
			y += ((tile_size * T_TILE_HEIGHT_RATIO) + 40);
			x = 80;
		}
	}

	return false;
}

bool R_score_view_draw(struct G_GameState gamestate)
{
	if (R_overlay_menu_window_draw(L_COLOR_GREEN))
		return true;
	(void)gamestate;
	return false;
}

bool R_gamestate_draw(SDL_Renderer *sdl_renderer, SDL_Window *sdl_window,
		      struct G_GameState gamestate)
{
	if (gamestate.scale != scale) {
		G_window_renderer_resize(sdl_window, sdl_renderer,
					 gamestate.window_w, gamestate.window_h,
					 gamestate.scale);
		scale = gamestate.scale;
	}

	R_main_menu_draw(gamestate);

	switch (gamestate.overlayed_menu) {
	case G_OVERLAYED_MENU_NONE:
		break;
	case G_OVERLAYED_MENU_HANDSHAPES_SELECTOR:
		if (R_handshapes_selector_draw(gamestate))
			return true;
		break;
	case G_OVERLAYED_MENU_HANDSHAPE_GROUP_OPEN_CLOSE_SELECTOR:
		if (R_handshape_group_open_close_selector_draw(gamestate))
			return true;
		break;
	case G_OVERLAYED_MENU_WINNING_TILE_SELECTOR:
		if (R_winning_tile_selector_draw(gamestate))
			return true;
		break;
	case G_OVERLAYED_MENU_SCORE_VIEW:
		if (R_score_view_draw(gamestate))
			return true;
		break;
	case G_OVERLAYED_MENU_COUNT:
		break;
	default:
		break;
	}

	if (R_help_draw(gamestate))
		return true;

	SDL_RenderPresent(sdl_renderer);
	return false;
}
