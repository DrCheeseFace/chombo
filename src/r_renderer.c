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

bool R_draw_overlay_menu_window(L_Colors outline_colour)
{
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

bool R_draw_help(struct G_GameState gamestate)
{
	if (!gamestate.show_help) {
		if (L_draw(sdl_renderer, L_TEXT_BOTTOM_HELP,
			   (struct SDL_Point){ 4, screen_height - 50 }))
			return true;
		return false;
	}

	if (R_draw_overlay_menu_window(L_COLOR_WHITE))
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

bool R_draw_hand(struct G_GameState gamestate)
{
	int x = 10;
	for (int i = 0; i < MAX_HAND_TILE_COUNT; i++) {
		if (T_tile_draw(sdl_renderer, gamestate.hand_tiles[i],
				(struct SDL_Point){ x, 17 }, 21)) {
			return true;
		}
		x += 88;
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

bool R_draw_dora(struct G_GameState gamestate)
{
	int x = 10;
	for (int i = 0; i < MAX_DORA_TILE_COUNT; i++) {
		if (T_tile_draw(sdl_renderer, gamestate.dora_tiles[i],
				(struct SDL_Point){ x, 190 }, 21)) {
			return true;
		}
		x += 88;
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

bool R_draw_seat_wind_selector(struct G_GameState gamestate)
{
	const T_Tile wind_tiles[4] = { T_TILE_TON, T_TILE_NAN, T_TILE_SHAA,
				       T_TILE_PEI };

	int x = 10;
	for (int i = 0; i < 4; i++) {
		if (T_tile_draw(sdl_renderer, wind_tiles[i],
				(struct SDL_Point){
					x,
					gamestate.seat_wind == wind_tiles[i] ?
						373 :
						393 },
				21)) {
			return true;
		}
		x += 100;
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

bool R_draw_prevelant_wind_selector(struct G_GameState gamestate)
{
	const T_Tile wind_tiles[4] = { T_TILE_TON, T_TILE_NAN, T_TILE_SHAA,
				       T_TILE_PEI };

	int x = 10;
	for (int i = 0; i < 4; i++) {
		if (T_tile_draw(sdl_renderer, wind_tiles[i],
				(struct SDL_Point){
					x, gamestate.prevelant_wind ==
							   wind_tiles[i] ?
						   586 :
						   606 },
				21)) {
			return true;
		}
		x += 100;
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

bool R_draw_conditions(struct G_GameState gamestate)
{
	int y = 373;
	if (L_draw(sdl_renderer,
		   gamestate.riichi ? L_TEXT_CONDITION_RIICHI_ON :
				      L_TEXT_CONDITION_RIICHI_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.double_riichi ? L_TEXT_CONDITION_DOUBLE_RIICHI_ON :
					     L_TEXT_CONDITION_DOUBLE_RIICHI_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.ippatsu ? L_TEXT_CONDITION_IPPATSU_ON :
				       L_TEXT_CONDITION_IPPATSU_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.haitei ? L_TEXT_CONDITION_HAITEI_ON :
				      L_TEXT_CONDITION_HAITEI_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.chankan ? L_TEXT_CONDITION_CHANKAN_ON :
				       L_TEXT_CONDITION_CHANKAN_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;
	y += 80;
	if (L_draw(sdl_renderer,
		   gamestate.rinshan ? L_TEXT_CONDITION_RINSHAN_ON :
				       L_TEXT_CONDITION_RINSHAN_OFF,
		   (struct SDL_Point){ 500, y }))
		return true;

	return false;
}

bool R_draw_handshapes_selector(struct G_GameState gamestate)
{
	if (R_draw_overlay_menu_window(L_COLOR_RED))
		return true;
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
						19)) {
					return true;
				}
				x += 80;
			}
			x += 10;
		}
		y += 120;
		if (gamestate.selector_idx == i) {
			SDL_SetRenderDrawColor(sdl_renderer,
					       L_COLORS[L_COLOR_GREEN].r,
					       L_COLORS[L_COLOR_GREEN].g,
					       L_COLORS[L_COLOR_GREEN].b,
					       L_COLORS[L_COLOR_GREEN].a);
			SDL_RenderFillRects(
				sdl_renderer,
				&(struct SDL_FRect){ 80, y, x - 80, 5 }, 1);
		}
		y += 80;
	}

	return false;
}

bool R_draw_handshape_group_open_close_selector(struct G_GameState gamestate)
{
	if (R_draw_overlay_menu_window(L_COLOR_BLUE))
		return true;
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
					(struct SDL_Point){ x, y }, 24)) {
				return true;
			}
			x += 100;
		}
		x += 100;

		if (L_draw(sdl_renderer,
			   gamestate.selected_handshape.groups[i].isopen ?
				   L_TEXT_GROUP_OPEN :
				   L_TEXT_GROUP_CLOSED,
			   (struct SDL_Point){ 600, y }))
			return true;

		y += 140;

		if (gamestate.selector_idx == i) {
			SDL_SetRenderDrawColor(sdl_renderer,
					       L_COLORS[L_COLOR_GREEN].r,
					       L_COLORS[L_COLOR_GREEN].g,
					       L_COLORS[L_COLOR_GREEN].b,
					       L_COLORS[L_COLOR_GREEN].a);
			SDL_RenderFillRects(
				sdl_renderer,
				&(struct SDL_FRect){ 80, y, 900, 5 }, 1);
		}

		y += 40;
	}
	return false;
}

bool R_draw_winning_tile_selector(struct G_GameState gamestate)
{
	(void)gamestate;
	if (R_draw_overlay_menu_window(L_COLOR_MAGENTA))
		return 1;
	return 0;
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

	if (R_draw_hand(gamestate))
		return true;
	if (R_draw_dora(gamestate))
		return true;
	if (R_draw_seat_wind_selector(gamestate))
		return true;
	if (R_draw_prevelant_wind_selector(gamestate))
		return true;
	if (R_draw_conditions(gamestate))
		return true;

	switch (gamestate.overlayed_menu) {
	case G_OVERLAYED_MENU_NONE:
		break;
	case G_OVERLAYED_MENU_HANDSHAPES_SELECTOR:
		if (R_draw_handshapes_selector(gamestate))
			return true;
		break;
	case G_OVERLAYED_MENU_HANDSHAPE_GROUP_OPEN_CLOSE_SELECTOR:
		if (R_draw_handshape_group_open_close_selector(gamestate))
			return true;
		break;
	case G_OVERLAYED_MENU_WINNING_TILE_SELECTOR:
		if (R_draw_winning_tile_selector(gamestate))
			return true;
		break;
	case G_OVERLAYED_MENU_COUNT:
		break;
	default:
		break;
	}

	if (R_draw_help(gamestate))
		return true;

	SDL_RenderPresent(sdl_renderer);
	return false;
}
