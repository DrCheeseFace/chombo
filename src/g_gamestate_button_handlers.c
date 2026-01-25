#include "g_gamestate_button_handlers.h"
#include "g_gamestate.h"

#include <mr_utils.h>
#include <stdint.h>

void G_on_click_toggle_tsumo(struct G_GameState *gamestate, unused void *args)
{
	gamestate->conditions.tsumo = !gamestate->conditions.tsumo;
}

void G_on_click_toggle_riichi(struct G_GameState *gamestate, unused void *args)
{
	gamestate->conditions.riichi = !gamestate->conditions.riichi;
}

void G_on_click_toggle_double_riichi(struct G_GameState *gamestate,
				     unused void *args)
{
	gamestate->conditions.double_riichi =
		!gamestate->conditions.double_riichi;
}

void G_on_click_toggle_ippatsu(struct G_GameState *gamestate, unused void *args)
{
	gamestate->conditions.ippatsu = !gamestate->conditions.ippatsu;
}

void G_on_click_toggle_haitei(struct G_GameState *gamestate, unused void *args)
{
	gamestate->conditions.haitei = !gamestate->conditions.haitei;
}

void G_on_click_toggle_chankan(struct G_GameState *gamestate, unused void *args)
{
	gamestate->conditions.chankan = !gamestate->conditions.chankan;
}

void G_on_click_toggle_rinshan(struct G_GameState *gamestate, unused void *args)
{
	gamestate->conditions.rinshan = !gamestate->conditions.rinshan;
}

void G_on_click_toggle_tenhou(struct G_GameState *gamestate, unused void *args)
{
	gamestate->conditions.tenhou = !gamestate->conditions.tenhou;
}

void G_on_click_select_prevalent_ton(struct G_GameState *gamestate,
				     unused void *args)
{
	gamestate->prevalent_wind = T_TILE_TON;
}

void G_on_click_select_prevalent_nan(struct G_GameState *gamestate,
				     unused void *args)
{
	gamestate->prevalent_wind = T_TILE_NAN;
}

void G_on_click_select_prevalent_shaa(struct G_GameState *gamestate,
				      unused void *args)
{
	gamestate->prevalent_wind = T_TILE_SHAA;
}

void G_on_click_select_prevalent_pei(struct G_GameState *gamestate,
				     unused void *args)
{
	gamestate->prevalent_wind = T_TILE_PEI;
}

void G_on_click_select_seat_ton(struct G_GameState *gamestate,
				unused void *args)
{
	gamestate->seat_wind = T_TILE_TON;
}

void G_on_click_select_seat_nan(struct G_GameState *gamestate,
				unused void *args)
{
	gamestate->seat_wind = T_TILE_NAN;
}

void G_on_click_select_seat_shaa(struct G_GameState *gamestate,
				 unused void *args)
{
	gamestate->seat_wind = T_TILE_SHAA;
}

void G_on_click_select_seat_pei(struct G_GameState *gamestate,
				unused void *args)
{
	gamestate->seat_wind = T_TILE_PEI;
}

void G_on_click_add_hand_tile(struct G_GameState *gamestate, void *args)
{
	G_hand_add_tile(gamestate, (T_Tile)(intptr_t)args);
}

void G_on_click_add_dora_tile(struct G_GameState *gamestate, void *args)
{
	G_dora_add_tile(gamestate, (T_Tile)(intptr_t)args);
}

bool G_destroy_main_menu_button(struct G_GameState *gamestate)
{
	if (gamestate->overlayed_menu != G_OVERLAYED_MENU_NONE) {
		return true;
	}

	return false;
}

void G_on_click_toggle_hand_keyboard(struct G_GameState *gamestate,
				     unused void *args)
{
	if (gamestate->overlayed_menu != G_OVERLAYED_MENU_HAND_KEYBOARD) {
		gamestate->selected_main_menu_option =
			G_SELECTED_MAIN_MENU_OPTION_HAND;
		gamestate->overlayed_menu = G_OVERLAYED_MENU_HAND_KEYBOARD;
	} else {
		G_step_backward_menu(gamestate);
	}
}

void G_on_click_toggle_dora_keyboard(struct G_GameState *gamestate,
				     unused void *args)
{
	if (gamestate->overlayed_menu != G_OVERLAYED_MENU_DORA_KEYBOARD) {
		gamestate->selected_main_menu_option =
			G_SELECTED_MAIN_MENU_OPTION_DORA;
		gamestate->overlayed_menu = G_OVERLAYED_MENU_DORA_KEYBOARD;
	} else {
		G_step_backward_menu(gamestate);
	}
}

bool G_destroy_toggle_hand_dora_keyboard_button(struct G_GameState *gamestate)
{
	return (gamestate->overlayed_menu != G_OVERLAYED_MENU_HAND_KEYBOARD &&
		gamestate->overlayed_menu != G_OVERLAYED_MENU_DORA_KEYBOARD &&
		gamestate->overlayed_menu != G_OVERLAYED_MENU_NONE);
}

bool G_destroy_hand_keyboard_button(struct G_GameState *gamestate)
{
	return gamestate->overlayed_menu != G_OVERLAYED_MENU_HAND_KEYBOARD;
}

bool G_destroy_dora_keyboard_button(struct G_GameState *gamestate)
{
	return gamestate->overlayed_menu != G_OVERLAYED_MENU_DORA_KEYBOARD;
}

void G_on_click_select_handshape(struct G_GameState *gamestate,
				 void *handshape_idx)
{
	gamestate->selector_idx = (int)(intptr_t)handshape_idx;
	G_step_forward_menu(gamestate);
}

bool G_destroy_select_handshape_button(struct G_GameState *gamestate)
{
	return gamestate->overlayed_menu !=
	       G_OVERLAYED_MENU_HANDSHAPES_SELECTOR;
}

void G_on_click_toggle_group_open_closed(struct G_GameState *gamestate,
					 void *group_idx)
{
	gamestate->selector_idx = (int)(intptr_t)group_idx;
	G_group_selector_open_close_toggle(gamestate);
}

bool G_destroy_toggle_group_open_closed(struct G_GameState *gamestate)
{
	return gamestate->overlayed_menu !=
	       G_OVERLAYED_MENU_HANDSHAPE_GROUP_OPEN_CLOSE_SELECTOR;
}
