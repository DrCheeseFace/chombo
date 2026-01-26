#include "b_button.h"
#include "g_gamestate.h"
#include "g_gamestate_button_handlers.h"
#include "l_letter.h"
#include "mahc.h"
#include "t_tiles.h"
#include "util.h"

#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

SDL_Renderer *sdl_renderer;
float scale;

SDL_Renderer *R_create(SDL_Window *window)
{
	sdl_renderer = SDL_CreateRenderer(window, NULL);

	scale = 0.5;

	T_tiles_init(sdl_renderer);

	return sdl_renderer;
}

void R_destroy(void)
{
	T_tiles_destroy();
	SDL_DestroyRenderer(sdl_renderer);
}

bool R_draw(SDL_Texture *tex, SDL_Point point)
{
	SDL_FRect rect = {
		.x = point.x, .y = point.y, .w = tex->w, .h = tex->h
	};

	if (!SDL_RenderTexture(sdl_renderer, tex, NULL, &rect)) {
		fprintf(stderr, "Failed to render text texture: %s\n",
			SDL_GetError());
		return true;
	}
	return false;
}

void R_redraw_score_texts(struct G_GameState gamestate)
{
	char han_str[4] = PLACEHOLDER_TEXT;
	SDL_itoa(gamestate.score_result.score_info.han_score, han_str, 10);
	L_rewrite_text(sdl_renderer, L_TEXT_SCORE_HAN_SCORE, han_str);

	char fu_str[4] = PLACEHOLDER_TEXT;
	SDL_itoa(gamestate.score_result.score_info.fu_score, fu_str, 10);
	L_rewrite_text(sdl_renderer, L_TEXT_SCORE_FU_SCORE, fu_str);

	char honba_str[4] = PLACEHOLDER_TEXT;
	SDL_itoa(gamestate.honba, honba_str, 10);
	L_rewrite_text(sdl_renderer, L_TEXT_SCORE_HONBA_COUNT, honba_str);

	char dora_str[4] = PLACEHOLDER_TEXT;
	SDL_itoa(gamestate.score_result.score_info.dora_count, dora_str, 10);
	L_rewrite_text(sdl_renderer, L_TEXT_SCORE_DORA_COUNT, dora_str);

	if (gamestate.seat_wind == gamestate.prevalent_wind) {
		char dealer_to_non_dealer[7] = PLACEHOLDER_TEXT;
		if (gamestate.conditions.tsumo) {
			SDL_itoa(gamestate.score_result.score_info.dealer_tsumo,
				 dealer_to_non_dealer, 10);
		} else {
			SDL_itoa(gamestate.score_result.score_info.dealer_ron,
				 dealer_to_non_dealer, 10);
		}
		L_rewrite_text(sdl_renderer, L_TEXT_SCORE_POINTS,
			       dealer_to_non_dealer);
	} else { // as non dealer
		char from_dealer[7] = PLACEHOLDER_TEXT;
		char from_non_dealer[7] = PLACEHOLDER_TEXT;
		char combined_points_str[14] = PLACEHOLDER_TEXT;

		if (gamestate.conditions.tsumo) {
			SDL_itoa(gamestate.score_result.score_info
					 .non_dealer_tsumo_non_dealer,
				 from_non_dealer, 10);
			SDL_itoa(gamestate.score_result.score_info
					 .non_dealer_tsumo_dealer,
				 from_dealer, 10);
			strcpy(combined_points_str, from_non_dealer);
			strcat(combined_points_str, SCORE_SPACER);
			strcat(combined_points_str, from_dealer);
			L_rewrite_text(sdl_renderer, L_TEXT_SCORE_POINTS,
				       combined_points_str);
		} else {
			SDL_itoa(
				gamestate.score_result.score_info.non_dealer_ron,
				combined_points_str, 10);
			L_rewrite_text(sdl_renderer, L_TEXT_SCORE_POINTS,
				       combined_points_str);
		}
	}
}

bool R_overlay_menu_window_draw(L_Colors outline_colour)
{
	if (!SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_MUL)) {
		fprintf(stderr,
			"Failed to set render blend mode to SDL_BLENDMODE_MUL: %s\n",
			SDL_GetError());
		return true;
	}

	SDL_FRect outline = { .w = WINDOW_WIDTH - 50,
			      .h = WINDOW_HEIGHT - 50,
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

	SDL_FRect background = { .w = WINDOW_WIDTH - 55,
				 .h = WINDOW_HEIGHT - 55,
				 .x = 27.5,
				 .y = 27.5 };
	if (!SDL_RenderFillRect(sdl_renderer, &background))
		return true;

	return false;
}

bool R_overlay_keyboard_window_draw(L_Colors outline_colour)
{
	if (!SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_NONE)) {
		fprintf(stderr,
			"Failed to set render blend mode to SDL_BLENDMODE_MUL: %s\n",
			SDL_GetError());
		return true;
	}

	SDL_FRect outline = { .w = WINDOW_WIDTH - 50,
			      .h = WINDOW_HEIGHT - 395,
			      .x = 25,
			      .y = 347.5 };
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

	SDL_FRect background = { .w = WINDOW_WIDTH - 55,
				 .h = WINDOW_HEIGHT - 400,
				 .x = 27.5,
				 .y = 350 };
	if (!SDL_RenderFillRect(sdl_renderer, &background))
		return true;

	return false;
}

bool R_help_draw(struct G_GameState gamestate)
{
	if (!gamestate.show_help) {
		if (L_draw_text(L_TEXT_BOTTOM_HELP,
				(struct SDL_Point){ -1, -1 }))
			return true;
		return false;
	}

	if (R_overlay_menu_window_draw(L_COLOR_WHITE))
		return true;

	if (L_draw_text(L_TEXT_HELP_0_9, (struct SDL_Point){ -1, -1 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_MAN1,
			(struct SDL_Point){ 280, 150 }, 16) != 0)
		return true;

	if (L_draw_text(L_TEXT_HELP_SHIFT, (struct SDL_Point){ -1, -1 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_PIN1,
			(struct SDL_Point){ 280, 250 }, 16) != 0)
		return true;

	if (L_draw_text(L_TEXT_HELP_CTRL, (struct SDL_Point){ -1, -1 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_SOU1,
			(struct SDL_Point){ 280, 350 }, 16) != 0)
		return true;

	if (L_draw_text(L_TEXT_HELP_E, (struct SDL_Point){ -1, -1 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_TON,
			(struct SDL_Point){ 280, 450 }, 16) != 0)
		return true;

	if (L_draw_text(L_TEXT_HELP_S, (struct SDL_Point){ -1, -1 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_NAN,
			(struct SDL_Point){ 280, 550 }, 16) != 0)
		return true;

	if (L_draw_text(L_TEXT_HELP_W, (struct SDL_Point){ -1, -1 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_SHAA,
			(struct SDL_Point){ 280, 650 }, 16) != 0)
		return true;

	if (L_draw_text(L_TEXT_HELP_N, (struct SDL_Point){ -1, -1 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_PEI,
			(struct SDL_Point){ 280, 750 }, 16) != 0)
		return true;

	if (L_draw_text(L_TEXT_HELP_C, (struct SDL_Point){ -1, -1 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_CHUN,
			(struct SDL_Point){ 500, 150 }, 16) != 0)
		return true;

	if (L_draw_text(L_TEXT_HELP_H, (struct SDL_Point){ -1, -1 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_HAKU,
			(struct SDL_Point){ 500, 250 }, 16) != 0)
		return true;

	if (L_draw_text(L_TEXT_HELP_G, (struct SDL_Point){ -1, -1 }))
		return true;
	if (T_tile_draw(sdl_renderer, T_TILE_HATSU,
			(struct SDL_Point){ 500, 350 }, 16) != 0)
		return true;

	if (L_draw_text(L_TEXT_HELP_SPACE_TOGGLE, (struct SDL_Point){ -1, -1 }))
		return true;

	if (L_draw_text(L_TEXT_HELP_ESCAPE_BACKTRACK,
			(struct SDL_Point){ -1, -1 }))
		return true;

	if (L_draw_text(L_TEXT_HELP_RETURN_CONTINUE,
			(struct SDL_Point){ -1, -1 }))
		return true;

	if (L_draw_text(L_TEXT_HELP_ARROW_NAVIGATE,
			(struct SDL_Point){ -1, -1 }))
		return true;

	if (L_draw_text(L_TEXT_HELP_CLEAR_STATE, (struct SDL_Point){ -1, -1 }))
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
	if (L_draw_text(gamestate.selected_main_menu_option ==
					G_SELECTED_MAIN_MENU_OPTION_HAND ?
				L_TEXT_HAND_LABEL_SELECTED :
				L_TEXT_HAND_LABEL,
			(struct SDL_Point){ -1, -1 }))
		return true;
	if (L_draw_text(gamestate.handshapes.hands_len != 0 ?
				L_TEXT_HAND_VALID :
				L_TEXT_HAND_INVALID,
			(struct SDL_Point){ -1, -1 }))
		return true;

	B_register_button("toggle_hand_keyboard",
			  L_TEXTS_OBJS[L_TEXT_HAND_TOGGLE_KEYBOARD].box,
			  G_on_click_toggle_hand_keyboard,
			  G_destroy_toggle_hand_dora_keyboard_button, NULL);
	if (L_draw_text(L_TEXT_HAND_TOGGLE_KEYBOARD,
			(struct SDL_Point){ -1, -1 }))
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
	if (L_draw_text(gamestate.selected_main_menu_option ==
					G_SELECTED_MAIN_MENU_OPTION_DORA ?
				L_TEXT_DORA_LABEL_SELECTED :
				L_TEXT_DORA_LABEL,
			(struct SDL_Point){ -1, -1 }))
		return true;

	B_register_button("toggle_dora_keyboard",
			  L_TEXTS_OBJS[L_TEXT_DORA_TOGGLE_KEYBOARD].box,
			  G_on_click_toggle_dora_keyboard,
			  G_destroy_toggle_hand_dora_keyboard_button, NULL);
	if (L_draw_text(L_TEXT_DORA_TOGGLE_KEYBOARD,
			(struct SDL_Point){ -1, -1 }))
		return true;
	return false;
}

bool R_seat_wind_selector_draw(struct G_GameState gamestate)
{
	const T_Tile wind_tiles[4] = { T_TILE_TON, T_TILE_NAN, T_TILE_SHAA,
				       T_TILE_PEI };
	const char *wind_tiles_button_id[4] = { "ton_seat_wind",
						"nan_seat_wind",
						"shaa_seat_wind",
						"pei_seat_wind" };
	void (*wind_tiles_button_on_click[4])(struct G_GameState *,
					      void *args) = {
		&G_on_click_select_seat_ton, &G_on_click_select_seat_nan,
		&G_on_click_select_seat_shaa, &G_on_click_select_seat_pei
	};

	const int tile_size = 21;
	const int unselected_y = 393;
	const int selected_y = 373;
	const int horizontal_padding = 16;

	int x = 10;
	for (int i = 0; i < 4; i++) {
		SDL_FRect tile_rect = { x, unselected_y,
					tile_size * T_TILE_WIDTH_RATIO,
					tile_size * T_TILE_HEIGHT_RATIO };

		B_register_button(wind_tiles_button_id[i], tile_rect,
				  wind_tiles_button_on_click[i],
				  G_destroy_main_menu_button, NULL);

		if (T_tile_draw(sdl_renderer, wind_tiles[i],
				(struct SDL_Point){
					x,
					gamestate.seat_wind == wind_tiles[i] ?
						selected_y :
						unselected_y },
				tile_size)) {
			return true;
		}
		x += ((tile_size * T_TILE_WIDTH_RATIO) + horizontal_padding);
	}

	if (L_draw_text(gamestate.selected_main_menu_option ==
					G_SELECTED_MAIN_MENU_OPTION_SEAT_WIND ?
				L_TEXT_SEAT_WIND_SELECTED :
				L_TEXT_SEAT_WIND,
			(struct SDL_Point){ -1, -1 }))
		return true;

	return false;
}

bool R_prevalent_wind_selector_draw(struct G_GameState gamestate)
{
	const T_Tile wind_tiles[4] = { T_TILE_TON, T_TILE_NAN, T_TILE_SHAA,
				       T_TILE_PEI };
	const char *wind_tiles_button_id[4] = { "ton_prevalent_wind",
						"nan_prevalent_wind",
						"shaa_prevalent_wind",
						"pei_prevalent_wind" };
	void (*wind_tiles_button_on_click[4])(
		struct G_GameState *,
		void *args) = { &G_on_click_select_prevalent_ton,
				&G_on_click_select_prevalent_nan,
				&G_on_click_select_prevalent_shaa,
				&G_on_click_select_prevalent_pei };

	const int tile_size = 21;
	const int unselected_y = 606;
	const int selected_y = 586;
	const int horizontal_padding = 16;

	int x = 10;
	for (int i = 0; i < 4; i++) {
		SDL_FRect tile_rect = { x, unselected_y,
					tile_size * T_TILE_WIDTH_RATIO,
					tile_size * T_TILE_HEIGHT_RATIO };

		B_register_button(wind_tiles_button_id[i], tile_rect,
				  wind_tiles_button_on_click[i],
				  G_destroy_main_menu_button, NULL);

		if (T_tile_draw(sdl_renderer, wind_tiles[i],
				(struct SDL_Point){
					x, gamestate.prevalent_wind ==
							   wind_tiles[i] ?
						   selected_y :
						   unselected_y },
				tile_size)) {
			return true;
		}
		x += ((tile_size * T_TILE_WIDTH_RATIO) + horizontal_padding);
	}

	if (L_draw_text(
		    gamestate.selected_main_menu_option ==
				    G_SELECTED_MAIN_MENU_OPTION_PREVALENT_WIND ?
			    L_TEXT_PREVALENT_WIND_SELECTED :
			    L_TEXT_PREVALENT_WIND,
		    (struct SDL_Point){ -1, -1 }))
		return true;
	return false;
}

bool R_conditions_draw(struct G_GameState gamestate)
{
	if (B_register_button("condition_tsumo_toggle",
			      L_TEXTS_OBJS[L_TEXT_CONDITION_TSUMO_ON].box,
			      &G_on_click_toggle_tsumo,
			      &G_destroy_main_menu_button, NULL))
		return true;
	if (L_draw_text(gamestate.conditions.tsumo ? L_TEXT_CONDITION_TSUMO_ON :
						     L_TEXT_CONDITION_TSUMO_OFF,
			(struct SDL_Point){ -1, -1 }))
		return true;

	if (B_register_button("condition_riichi_toggle",
			      L_TEXTS_OBJS[L_TEXT_CONDITION_RIICHI_ON].box,
			      &G_on_click_toggle_riichi,
			      &G_destroy_main_menu_button, NULL))
		return true;
	if (L_draw_text(gamestate.conditions.riichi ?
				L_TEXT_CONDITION_RIICHI_ON :
				L_TEXT_CONDITION_RIICHI_OFF,
			(struct SDL_Point){ -1, -1 }))
		return true;

	if (B_register_button(
		    "condition_double_riichi_toggle",
		    L_TEXTS_OBJS[L_TEXT_CONDITION_DOUBLE_RIICHI_OFF].box,
		    &G_on_click_toggle_double_riichi,
		    &G_destroy_main_menu_button, NULL))
		return true;
	if (L_draw_text(gamestate.conditions.double_riichi ?
				L_TEXT_CONDITION_DOUBLE_RIICHI_ON :
				L_TEXT_CONDITION_DOUBLE_RIICHI_OFF,
			(struct SDL_Point){ -1, -1 }))
		return true;

	if (B_register_button("condition_ippatsu_toggle",
			      L_TEXTS_OBJS[L_TEXT_CONDITION_IPPATSU_OFF].box,
			      &G_on_click_toggle_ippatsu,
			      &G_destroy_main_menu_button, NULL))
		return true;
	if (L_draw_text(gamestate.conditions.ippatsu ?
				L_TEXT_CONDITION_IPPATSU_ON :
				L_TEXT_CONDITION_IPPATSU_OFF,
			(struct SDL_Point){ -1, -1 }))
		return true;

	if (B_register_button("condition_haitei_toggle",
			      L_TEXTS_OBJS[L_TEXT_CONDITION_HAITEI_OFF].box,
			      &G_on_click_toggle_haitei,
			      &G_destroy_main_menu_button, NULL))
		return true;
	if (L_draw_text(gamestate.conditions.haitei ?
				L_TEXT_CONDITION_HAITEI_ON :
				L_TEXT_CONDITION_HAITEI_OFF,
			(struct SDL_Point){ -1, -1 }))
		return true;

	if (B_register_button("condition_chankan_toggle",
			      L_TEXTS_OBJS[L_TEXT_CONDITION_CHANKAN_OFF].box,
			      &G_on_click_toggle_chankan,
			      &G_destroy_main_menu_button, NULL))
		return true;
	if (L_draw_text(gamestate.conditions.chankan ?
				L_TEXT_CONDITION_CHANKAN_ON :
				L_TEXT_CONDITION_CHANKAN_OFF,
			(struct SDL_Point){ -1, -1 }))
		return true;

	if (B_register_button("condition_rinshan_toggle",
			      L_TEXTS_OBJS[L_TEXT_CONDITION_RINSHAN_OFF].box,
			      &G_on_click_toggle_rinshan,
			      &G_destroy_main_menu_button, NULL))
		return true;
	if (L_draw_text(gamestate.conditions.rinshan ?
				L_TEXT_CONDITION_RINSHAN_ON :
				L_TEXT_CONDITION_RINSHAN_OFF,
			(struct SDL_Point){ -1, -1 }))
		return true;

	if (B_register_button("condition_tenhou_toggle",
			      L_TEXTS_OBJS[L_TEXT_CONDITION_TENHOU_OFF].box,
			      &G_on_click_toggle_tenhou,
			      &G_destroy_main_menu_button, NULL))
		return true;
	if (L_draw_text(gamestate.conditions.tenhou ?
				L_TEXT_CONDITION_TENHOU_ON :
				L_TEXT_CONDITION_TENHOU_OFF,
			(struct SDL_Point){ -1, -1 }))
		return true;

	return false;
}

bool R_honba_draw(struct G_GameState gamestate)
{
	if (L_draw_text(gamestate.selected_main_menu_option ==
					G_SELECTED_MAIN_MENU_OPTION_HONBA ?
				L_TEXT_HONBA_ON :
				L_TEXT_HONBA_OFF,
			(struct SDL_Point){ -1, -1 }))
		return true;

	char honba_str[4] = PLACEHOLDER_TEXT;
	SDL_itoa(gamestate.honba, honba_str, 10);
	L_rewrite_text(sdl_renderer, L_TEXT_HONBA_COUNT, honba_str);

	B_register_button("honba_up", L_TEXTS_OBJS[L_TEXT_HONBA_UP].box,
			  G_increment_honba_counter, G_destroy_main_menu_button,
			  NULL);
	B_register_button("honba_down", L_TEXTS_OBJS[L_TEXT_HONBA_DOWN].box,
			  G_decrement_honba_counter, G_destroy_main_menu_button,
			  NULL);
	if (L_draw_text(L_TEXT_HONBA_UP, (struct SDL_Point){ -1, -1 }))
		return true;
	if (L_draw_text(L_TEXT_HONBA_COUNT, (struct SDL_Point){ -1, -1 }))
		return true;
	if (L_draw_text(L_TEXT_HONBA_DOWN, (struct SDL_Point){ -1, -1 }))
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
	if (R_prevalent_wind_selector_draw(gamestate))
		return true;
	if (R_conditions_draw(gamestate))
		return true;
	if (R_honba_draw(gamestate))
		return true;

	return false;
}

bool R_hand_keyboard(void)
{
	if (R_overlay_keyboard_window_draw(L_COLOR_MAGENTA))
		return true;

	const int tile_size = 18;
	const int horizontal_padding = 30;
	const int vertical_padding = 30;

	int x = 100;
	int y = 400;

	char button_id[16] = { 0 };
	// draw dragons
	for (T_Tile dragon_tile = T_TILE_CHUN; dragon_tile <= T_TILE_HAKU;
	     dragon_tile++) {
		SDL_FRect button_rect = { x, y, tile_size * T_TILE_WIDTH_RATIO,
					  tile_size * T_TILE_HEIGHT_RATIO };
		sprintf(button_id, "%ddragonhand", dragon_tile);
		B_register_button(button_id, button_rect,
				  G_on_click_add_hand_tile,
				  &G_destroy_hand_keyboard_button,
				  (void *)(intptr_t)dragon_tile);

		if (T_tile_draw(sdl_renderer, dragon_tile,
				(SDL_Point){ .x = x, .y = y }, tile_size))
			return true;
		x += tile_size * T_TILE_WIDTH_RATIO + horizontal_padding;
	}

	// draw winds
	for (T_Tile wind_tile = T_TILE_TON; wind_tile <= T_TILE_PEI;
	     wind_tile++) {
		SDL_FRect button_rect = { x, y, tile_size * T_TILE_WIDTH_RATIO,
					  tile_size * T_TILE_HEIGHT_RATIO };
		sprintf(button_id, "%dwindhand", wind_tile);
		B_register_button(button_id, button_rect,
				  G_on_click_add_hand_tile,
				  &G_destroy_hand_keyboard_button,
				  (void *)(intptr_t)wind_tile);

		if (T_tile_draw(sdl_renderer, wind_tile,
				(SDL_Point){ .x = x, .y = y }, tile_size))
			return true;
		x += tile_size * T_TILE_WIDTH_RATIO + horizontal_padding;
	}

	x = 100;
	y += tile_size * T_TILE_HEIGHT_RATIO + vertical_padding;

	// draw man
	for (T_Tile man_tile = T_TILE_MAN1; man_tile <= T_TILE_MAN9;
	     man_tile++) {
		SDL_FRect button_rect = { x, y, tile_size * T_TILE_WIDTH_RATIO,
					  tile_size * T_TILE_HEIGHT_RATIO };
		sprintf(button_id, "%dmanhand", man_tile);
		B_register_button(button_id, button_rect,
				  G_on_click_add_hand_tile,
				  &G_destroy_hand_keyboard_button,
				  (void *)(intptr_t)man_tile);

		if (T_tile_draw(sdl_renderer, man_tile,
				(SDL_Point){ .x = x, .y = y }, tile_size))
			return true;
		x += tile_size * T_TILE_WIDTH_RATIO + horizontal_padding;
	}

	x = 100;
	y += tile_size * T_TILE_HEIGHT_RATIO + vertical_padding;

	// draw pin
	for (T_Tile pin_tile = T_TILE_PIN1; pin_tile <= T_TILE_PIN9;
	     pin_tile++) {
		SDL_FRect button_rect = { x, y, tile_size * T_TILE_WIDTH_RATIO,
					  tile_size * T_TILE_HEIGHT_RATIO };
		sprintf(button_id, "%dpinhand", pin_tile);
		B_register_button(button_id, button_rect,
				  G_on_click_add_hand_tile,
				  &G_destroy_hand_keyboard_button,
				  (void *)(intptr_t)pin_tile);

		if (T_tile_draw(sdl_renderer, pin_tile,
				(SDL_Point){ .x = x, .y = y }, tile_size))
			return true;
		x += tile_size * T_TILE_WIDTH_RATIO + horizontal_padding;
	}

	x = 100;
	y += tile_size * T_TILE_HEIGHT_RATIO + vertical_padding;

	// draw sou
	for (T_Tile sou_tile = T_TILE_SOU1; sou_tile <= T_TILE_SOU9;
	     sou_tile++) {
		SDL_FRect button_rect = { x, y, tile_size * T_TILE_WIDTH_RATIO,
					  tile_size * T_TILE_HEIGHT_RATIO };
		sprintf(button_id, "%dsouhand", sou_tile);
		B_register_button(button_id, button_rect,
				  G_on_click_add_hand_tile,
				  &G_destroy_hand_keyboard_button,
				  (void *)(intptr_t)sou_tile);

		if (T_tile_draw(sdl_renderer, sou_tile,
				(SDL_Point){ .x = x, .y = y }, tile_size))
			return true;
		x += tile_size * T_TILE_WIDTH_RATIO + horizontal_padding;
	}

	return false;
}

bool R_dora_keyboard(void)
{
	if (R_overlay_keyboard_window_draw(L_COLOR_BLUE))
		return true;

	const int tile_size = 18;
	const int horizontal_padding = 30;
	const int vertical_padding = 30;

	int x = 100;
	int y = 400;

	char button_id[16] = { 0 };
	// draw dragons
	for (T_Tile dragon_tile = T_TILE_CHUN; dragon_tile <= T_TILE_HAKU;
	     dragon_tile++) {
		SDL_FRect button_rect = { x, y, tile_size * T_TILE_WIDTH_RATIO,
					  tile_size * T_TILE_HEIGHT_RATIO };
		sprintf(button_id, "%ddragondora", dragon_tile);
		B_register_button(button_id, button_rect,
				  G_on_click_add_dora_tile,
				  &G_destroy_dora_keyboard_button,
				  (void *)(intptr_t)dragon_tile);

		if (T_tile_draw(sdl_renderer, dragon_tile,
				(SDL_Point){ .x = x, .y = y }, tile_size))
			return true;
		x += tile_size * T_TILE_WIDTH_RATIO + horizontal_padding;
	}

	// draw winds
	for (T_Tile wind_tile = T_TILE_TON; wind_tile <= T_TILE_PEI;
	     wind_tile++) {
		SDL_FRect button_rect = { x, y, tile_size * T_TILE_WIDTH_RATIO,
					  tile_size * T_TILE_HEIGHT_RATIO };
		sprintf(button_id, "%dwinddora", wind_tile);
		B_register_button(button_id, button_rect,
				  G_on_click_add_dora_tile,
				  &G_destroy_dora_keyboard_button,
				  (void *)(intptr_t)wind_tile);

		if (T_tile_draw(sdl_renderer, wind_tile,
				(SDL_Point){ .x = x, .y = y }, tile_size))
			return true;
		x += tile_size * T_TILE_WIDTH_RATIO + horizontal_padding;
	}

	x = 100;
	y += tile_size * T_TILE_HEIGHT_RATIO + vertical_padding;

	// draw man
	for (T_Tile man_tile = T_TILE_MAN1; man_tile <= T_TILE_MAN9;
	     man_tile++) {
		SDL_FRect button_rect = { x, y, tile_size * T_TILE_WIDTH_RATIO,
					  tile_size * T_TILE_HEIGHT_RATIO };
		sprintf(button_id, "%dmandora", man_tile);
		B_register_button(button_id, button_rect,
				  G_on_click_add_dora_tile,
				  &G_destroy_dora_keyboard_button,
				  (void *)(intptr_t)man_tile);

		if (T_tile_draw(sdl_renderer, man_tile,
				(SDL_Point){ .x = x, .y = y }, tile_size))
			return true;
		x += tile_size * T_TILE_WIDTH_RATIO + horizontal_padding;
	}

	x = 100;
	y += tile_size * T_TILE_HEIGHT_RATIO + vertical_padding;

	// draw pin
	for (T_Tile pin_tile = T_TILE_PIN1; pin_tile <= T_TILE_PIN9;
	     pin_tile++) {
		SDL_FRect button_rect = { x, y, tile_size * T_TILE_WIDTH_RATIO,
					  tile_size * T_TILE_HEIGHT_RATIO };
		sprintf(button_id, "%dpindora", pin_tile);
		B_register_button(button_id, button_rect,
				  G_on_click_add_dora_tile,
				  &G_destroy_dora_keyboard_button,
				  (void *)(intptr_t)pin_tile);

		if (T_tile_draw(sdl_renderer, pin_tile,
				(SDL_Point){ .x = x, .y = y }, tile_size))
			return true;
		x += tile_size * T_TILE_WIDTH_RATIO + horizontal_padding;
	}

	x = 100;
	y += tile_size * T_TILE_HEIGHT_RATIO + vertical_padding;

	// draw sou
	for (T_Tile sou_tile = T_TILE_SOU1; sou_tile <= T_TILE_SOU9;
	     sou_tile++) {
		SDL_FRect button_rect = { x, y, tile_size * T_TILE_WIDTH_RATIO,
					  tile_size * T_TILE_HEIGHT_RATIO };
		sprintf(button_id, "%dsoudora", sou_tile);
		B_register_button(button_id, button_rect,
				  G_on_click_add_dora_tile,
				  &G_destroy_dora_keyboard_button,
				  (void *)(intptr_t)sou_tile);

		if (T_tile_draw(sdl_renderer, sou_tile,
				(SDL_Point){ .x = x, .y = y }, tile_size))
			return true;
		x += tile_size * T_TILE_WIDTH_RATIO + horizontal_padding;
	}

	return false;
}

// holy fuckjing balls. shield your eyes or skip to line 1003
bool R_handshapes_selector_draw(struct G_GameState gamestate)
{
	if (R_overlay_menu_window_draw(L_COLOR_RED))
		return true;

	const int tile_size = 19;
	const int vertical_padding = 80;
	const int horizontal_padding = 4;
	const int group_padding = 10;
	const int handshape_to_selector_gap = 10;
	const int x_initial = 80;
	char button_id[32] = { 0 };

	int y = 100;
	for (int i = 0; i < (int)gamestate.handshapes.hands_len; i++) {
		int x = x_initial;
		int y_initial = y;
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

				x += ((tile_size * T_TILE_WIDTH_RATIO) +
				      horizontal_padding);
			}
			x += group_padding;
		}

		y += ((tile_size * T_TILE_HEIGHT_RATIO) +
		      handshape_to_selector_gap);

		sprintf(button_id, "%dhandshape_selector", i);
		B_register_button(
			button_id,
			(SDL_FRect){ .x = 0,
				     .y = y_initial,
				     .w = x,
				     .h = (float)(y - y_initial + 5) },
			&G_on_click_select_handshape,
			&G_destroy_select_handshape_button,
			(void *)(intptr_t)i);

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
			SDL_RenderFillRects(sdl_renderer,
					    &(struct SDL_FRect){ x_initial, y,
								 x - x_initial,
								 5 },
					    1);
		}
		y += vertical_padding;
	}

	return false;
}

bool R_handshape_group_open_close_selector_draw(struct G_GameState gamestate)
{
	if (R_overlay_menu_window_draw(L_COLOR_BLUE))
		return true;

	const int tile_size = 24;
	const int group_to_open_closed_text_gap = 100;
	const int group_to_selector_gap = 10;
	const int previous_group_to_lower_group_gap = 40;
	int x_initial = 80;

	char button_id[32] = { 0 };

	int y = 80;
	for (int i = 0; i < (int)gamestate.selected_handshape.group_count;
	     i++) {
		int x = x_initial;
		int y_initial = y;

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
		x += group_to_open_closed_text_gap;

		if (L_draw_text(gamestate.selected_handshape.groups[i].isopen ?
					L_TEXT_GROUP_OPEN :
					L_TEXT_GROUP_CLOSED,
				(struct SDL_Point){ WINDOW_WIDTH / 2, y }))
			return true;

		y += ((tile_size * T_TILE_HEIGHT_RATIO) +
		      group_to_selector_gap);

		sprintf(button_id, "%dgroup_open_closed_toggler", i);
		B_register_button(button_id,
				  (SDL_FRect){ .x = 0,
					       .y = y_initial,
					       .w = WINDOW_WIDTH,
					       .h = (float)(y - y_initial) },
				  &G_on_click_toggle_group_open_closed,
				  &G_destroy_toggle_group_open_closed,
				  (void *)(intptr_t)i);

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
					80, y, (float)WINDOW_WIDTH / 4 * 3, 5 },
				1);
		}

		y += previous_group_to_lower_group_gap;
	}
	return false;
}

bool R_winning_tile_selector_draw(struct G_GameState gamestate)
{
	if (R_overlay_menu_window_draw(L_COLOR_MAGENTA))
		return true;

	const int tile_size = 30;
	const int tile_horizontal_padding = 10;
	const int tile_vertical_padding = 40;

	char button_id[32] = { 0 };

	int tile_idx = 0;
	int x = 80;
	int y = 80;
	for (int i = 0; i < (int)gamestate.selected_handshape.group_count;
	     i++) {
		for (size_t j = 0;
		     j < gamestate.selected_handshape.groups[i].tiles_len;
		     j++) {
			sprintf(button_id, "%dwinning_tile", tile_idx);
			B_register_button(
				button_id,
				(SDL_FRect){
					.x = x,
					.y = y,
					.w = tile_size * T_TILE_WIDTH_RATIO,
					.h = tile_size * T_TILE_HEIGHT_RATIO },
				&G_on_click_select_winning_tile,
				&G_destroy_select_winning_tile_button,
				(void *)(intptr_t)tile_idx);

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
			x += tile_size * T_TILE_WIDTH_RATIO +
			     tile_horizontal_padding;
		}

		x += tile_size * T_TILE_WIDTH_RATIO + tile_horizontal_padding;

		if (x +
			    ((tile_size * T_TILE_WIDTH_RATIO) *
			     (int)gamestate.selected_handshape.groups[i]
				     .tiles_len) +
			    40 >
		    gamestate.window_w) {
			y += ((tile_size * T_TILE_HEIGHT_RATIO) +
			      tile_vertical_padding);

			x = 80;
		}
	}

	return false;
}

bool R_score_view_draw_err(struct FfiResult err)
{
	char *err_message = C_calc_err_string(err);
	L_rewrite_text(sdl_renderer, L_TEXT_ERR_MESSAGE, err_message);
	C_free_c_string(err_message);

	if (L_draw_text(
		    L_TEXT_ERR_HEADER,
		    (struct SDL_Point){
			    (WINDOW_WIDTH - L_text_width(L_TEXT_ERR_HEADER)) / 2,
			    (WINDOW_HEIGHT - L_text_height(L_TEXT_ERR_HEADER)) /
				    5,
		    }))
		return true;

	if (L_draw_text(
		    L_TEXT_ERR_MESSAGE,
		    (struct SDL_Point){
			    (WINDOW_WIDTH - L_text_width(L_TEXT_ERR_MESSAGE)) /
				    2,
			    (WINDOW_HEIGHT - L_text_height(L_TEXT_ERR_MESSAGE)) /
				    2,
		    }))
		return true;

	return false;
}

bool R_score_view_draw_score_info(struct G_GameState gamestate)
{
	// drawing yaku list section
	SDL_Texture *yaku_textures[MAX_ALLOCATED_TEXTURES];
	int yaku_textures_len = 0;

	int yaku_pointsize = 60;
	int max_yaku_column_width = 0;
	for (int i = 0; i < (int)gamestate.score_result.score_info.yaku_len;
	     i++) {
		if (i > MAX_ALLOCATED_TEXTURES) {
			for (int j = 0; j < yaku_textures_len; j++) {
				SDL_DestroyTexture(yaku_textures[j]);
			}
			return false; // AYO WATCH OUT!
		}

		char *yaku_string = C_yaku_string(
			gamestate.score_result.score_info.yaku[i],
			gamestate.score_result.score_info.is_open);

		L_Text_Obj yaku_text_obj = {
			.text = yaku_string,
			.point_size = yaku_pointsize,
			.color = L_COLOR_WHITE,
			.wraplength = 0,
			.align = TTF_HORIZONTAL_ALIGN_LEFT
		};

		yaku_textures[i] =
			L_texture_from_text_obj(sdl_renderer, yaku_text_obj);

		C_free_c_string(yaku_string);

		if (yaku_textures[i] == NULL) {
			for (int k = 0; k < yaku_textures_len; k++) {
				SDL_DestroyTexture(yaku_textures[k]);
			}
			return true;
		}

		if (yaku_textures[i]->w > max_yaku_column_width) {
			max_yaku_column_width = yaku_textures[i]->w;
		}

		yaku_textures_len++;
	}

	int initial_col_x = WINDOW_WIDTH / 36 * 2;
	int x = initial_col_x;
	int y = WINDOW_HEIGHT / 10;

	if (C_yaku_is_yakuman(gamestate.score_result.score_info.yaku[0])) {
		if (L_draw_text(L_TEXT_YAKUMAN_HEADER,
				(SDL_Point){ .x = x, .y = y }))
			return true;
	} else {
		if (L_draw_text(L_TEXT_YAKU_HEADER,
				(SDL_Point){ .x = x, .y = y }))
			return true;
	}

	y += 150;

	for (int i = 0; i < yaku_textures_len; i++) {
		if (R_draw(yaku_textures[i], (SDL_Point){ .x = x, .y = y }))
			return true;

		y += 60;
	}

	for (int i = 0; i < yaku_textures_len; i++) {
		SDL_DestroyTexture(yaku_textures[i]);
	}

	y += 60;

	// drawing han fu and honba section
	if (!C_yaku_is_yakuman(gamestate.score_result.score_info.yaku[0])) {
		L_draw_text(L_TEXT_SCORE_HAN, (SDL_Point){ .x = x, .y = y });
		x += L_text_width(L_TEXT_SCORE_HAN);
		L_draw_text(L_TEXT_SCORE_HAN_SCORE,
			    (SDL_Point){ .x = x, .y = y });

		x += L_text_width(L_TEXT_SCORE_HAN_SCORE);

		L_draw_text(L_TEXT_SCORE_FU, (SDL_Point){ .x = x, .y = y });
		x += L_text_width(L_TEXT_SCORE_FU);
		L_draw_text(L_TEXT_SCORE_FU_SCORE,
			    (SDL_Point){ .x = x, .y = y });

		int han_fu_width = L_text_width(L_TEXT_SCORE_HAN_SCORE) +
				   L_text_width(L_TEXT_SCORE_FU_SCORE) +
				   L_text_width(L_TEXT_SCORE_HAN) +
				   L_text_width(L_TEXT_SCORE_FU);
		if (max_yaku_column_width < han_fu_width) {
			max_yaku_column_width = han_fu_width;
		}

		y += L_text_height(L_TEXT_SCORE_FU_SCORE);
		x = initial_col_x;

		L_draw_text(L_TEXT_SCORE_DORA, (SDL_Point){ .x = x, .y = y });
		x += L_text_width(L_TEXT_SCORE_DORA);
		L_draw_text(L_TEXT_SCORE_DORA_COUNT,
			    (SDL_Point){ .x = x, .y = y });

		y += L_text_height(L_TEXT_SCORE_DORA_COUNT);
	}

	x = initial_col_x;
	L_draw_text(L_TEXT_SCORE_HONBA, (SDL_Point){ .x = x, .y = y });
	x += L_text_width(L_TEXT_SCORE_HONBA);
	L_draw_text(L_TEXT_SCORE_HONBA_COUNT, (SDL_Point){ .x = x, .y = y });

	x = WINDOW_WIDTH / 36 * 4 + max_yaku_column_width;
	y = WINDOW_HEIGHT / 10;

	// drawing fu list section
	if (!C_yaku_is_yakuman(gamestate.score_result.score_info.yaku[0])) {
		SDL_Texture *fu_textures[MAX_ALLOCATED_TEXTURES];
		int fu_textures_len = 0;

		int fu_pointsize = 50;
		for (int i = 0;
		     i < (int)gamestate.score_result.score_info.fu_len; i++) {
			if (i > MAX_ALLOCATED_TEXTURES) {
				for (int j = 0; j < fu_textures_len; j++) {
					SDL_DestroyTexture(fu_textures[j]);
				}
				return false; // AYO CHECK IT!
			}

			char *fu_string = C_fu_string(
				gamestate.score_result.score_info.fu[i]);

			L_Text_Obj fu_text_obj = {
				.text = fu_string,
				.point_size = fu_pointsize,
				.color = L_COLOR_WHITE,
				.wraplength = 0,
				.align = TTF_HORIZONTAL_ALIGN_LEFT
			};

			fu_textures[i] = L_texture_from_text_obj(sdl_renderer,
								 fu_text_obj);

			C_free_c_string(fu_string);

			if (fu_textures[i] == NULL) {
				for (int k = 0; k < fu_textures_len; k++) {
					SDL_DestroyTexture(fu_textures[k]);
				}
				return true;
			}

			fu_textures_len++;
		}

		if (L_draw_text(L_TEXT_FU_HEADER,
				(SDL_Point){ .x = x, .y = y }))
			return true;

		y += 150;

		for (int i = 0; i < fu_textures_len; i++) {
			if (R_draw(fu_textures[i],
				   (SDL_Point){ .x = x, .y = y }))
				return true;

			y += fu_textures[i]->h;
		}

		y += 60;

		for (int i = 0; i < fu_textures_len; i++) {
			SDL_DestroyTexture(fu_textures[i]);
		}
	}

	// drawing points section
	L_Text points_header;
	if (gamestate.seat_wind == gamestate.prevalent_wind) {
		if (gamestate.conditions.tsumo) {
			points_header = L_TEXT_SCORE_DEALER_TSUMO;
		} else {
			points_header = L_TEXT_SCORE_DEALER_RON;
		};
	} else {
		if (gamestate.conditions.tsumo) {
			points_header = L_TEXT_SCORE_NON_DEALER_TSUMO;
		} else {
			points_header = L_TEXT_SCORE_NON_DEALER_RON;
		};
	}

	L_draw_text(points_header, (SDL_Point){ .x = x, .y = y });
	y += L_text_height(points_header);
	L_draw_text(L_TEXT_SCORE_POINTS, (SDL_Point){ .x = x, .y = y });

	return false;
}

bool R_score_view_draw(struct G_GameState gamestate)
{
	if (R_overlay_menu_window_draw(L_COLOR_GREEN))
		return true;

	switch (gamestate.score_result.error.tag) {
	case FfiResult_Err:
		if (R_score_view_draw_err(gamestate.score_result.error))
			return true;
		break;
	case FfiResult_Ok:
		if (R_score_view_draw_score_info(gamestate))
			return true;
		break;
	default:
		break;
	}
	return false;
}

bool R_gamestate_draw(SDL_Window *sdl_window, struct G_GameState gamestate)
{
	if (fabsf(gamestate.scale - scale) >= FLT_EPSILON) {
		G_window_renderer_resize(sdl_window, sdl_renderer,
					 gamestate.window_w, gamestate.window_h,
					 gamestate.scale);
		scale = gamestate.scale;
	}

	R_main_menu_draw(gamestate);

	switch (gamestate.overlayed_menu) {
	case G_OVERLAYED_MENU_NONE:
		break;
	case G_OVERLAYED_MENU_HAND_KEYBOARD:
		if (R_hand_keyboard())
			return true;
		break;
	case G_OVERLAYED_MENU_DORA_KEYBOARD:
		if (R_dora_keyboard())
			return true;
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

#ifdef CHOMBO_DEBUG
	DEBUG_DRAW_POINTER_COORDS(sdl_renderer);
#endif

	SDL_RenderPresent(sdl_renderer);

#ifdef CHOMBO_DEBUG
	return true;
#else
	return false;
#endif
}
