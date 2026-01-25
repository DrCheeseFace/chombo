#include "g_gamestate_button_handlers.h"
#include "src/g_gamestate.h"
#include <stdint.h>

void G_on_click_toggle_tsumo(struct G_GameState *gamestate)
{
	gamestate->conditions.tsumo = !gamestate->conditions.tsumo;
}

void G_on_click_toggle_riichi(struct G_GameState *gamestate)
{
	gamestate->conditions.riichi = !gamestate->conditions.riichi;
}

void G_on_click_toggle_double_riichi(struct G_GameState *gamestate)
{
	gamestate->conditions.double_riichi =
		!gamestate->conditions.double_riichi;
}

void G_on_click_toggle_ippatsu(struct G_GameState *gamestate)
{
	gamestate->conditions.ippatsu = !gamestate->conditions.ippatsu;
}

void G_on_click_toggle_haitei(struct G_GameState *gamestate)
{
	gamestate->conditions.haitei = !gamestate->conditions.haitei;
}

void G_on_click_toggle_chankan(struct G_GameState *gamestate)
{
	gamestate->conditions.chankan = !gamestate->conditions.chankan;
}

void G_on_click_toggle_rinshan(struct G_GameState *gamestate)
{
	gamestate->conditions.rinshan = !gamestate->conditions.rinshan;
}

void G_on_click_toggle_tenhou(struct G_GameState *gamestate)
{
	gamestate->conditions.tenhou = !gamestate->conditions.tenhou;
}

void G_on_click_select_prevalent_ton(struct G_GameState *gamestate)
{
	gamestate->prevalent_wind = T_TILE_TON;
}

void G_on_click_select_prevalent_nan(struct G_GameState *gamestate)
{
	gamestate->prevalent_wind = T_TILE_NAN;
}

void G_on_click_select_prevalent_shaa(struct G_GameState *gamestate)
{
	gamestate->prevalent_wind = T_TILE_SHAA;
}

void G_on_click_select_prevalent_pei(struct G_GameState *gamestate)
{
	gamestate->prevalent_wind = T_TILE_PEI;
}

void G_on_click_select_seat_ton(struct G_GameState *gamestate)
{
	gamestate->seat_wind = T_TILE_TON;
}

void G_on_click_select_seat_nan(struct G_GameState *gamestate)
{
	gamestate->seat_wind = T_TILE_NAN;
}

void G_on_click_select_seat_shaa(struct G_GameState *gamestate)
{
	gamestate->seat_wind = T_TILE_SHAA;
}

void G_on_click_select_seat_pei(struct G_GameState *gamestate)
{
	gamestate->seat_wind = T_TILE_PEI;
}

bool G_destroy_main_menu_button(struct G_GameState *gamestate)
{
	if (gamestate->overlayed_menu != G_OVERLAYED_MENU_NONE) {
		return true;
	}

	return false;
}
