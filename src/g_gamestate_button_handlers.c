#include "g_gamestate_button_handlers.h"

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

bool G_destroy_main_menu_button(struct G_GameState *gamestate)
{
	if (gamestate->overlayed_menu != G_OVERLAYED_MENU_NONE) {
		return true;
	}

	return false;
}
