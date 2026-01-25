#include "g_gamestate_button_handlers.h"
#include "src/g_gamestate.h"
#include <stdint.h>

#define DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(name)                              \
	void G_add_hand_tile_##name(struct G_GameState *gamestate)             \
	{                                                                      \
		G_hand_add_tile(gamestate, T_TILE_##name);                     \
	}
HAND_TILE_LIST
#undef DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS

#define DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(name)                              \
	void G_add_dora_tile_##name(struct G_GameState *gamestate)             \
	{                                                                      \
		G_dora_add_tile(gamestate, T_TILE_##name);                     \
	}
DORA_TILE_LIST
#undef DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS

void (*on_click_add_hand_tile_funcs[T_TILE_COUNT])(struct G_GameState *) = {
	[T_TILE_CHUN] = G_add_hand_tile_CHUN,
	[T_TILE_HATSU] = G_add_hand_tile_HATSU,
	[T_TILE_HAKU] = G_add_hand_tile_HAKU,
	[T_TILE_MAN1] = G_add_hand_tile_MAN1,
	[T_TILE_MAN2] = G_add_hand_tile_MAN2,
	[T_TILE_MAN3] = G_add_hand_tile_MAN3,
	[T_TILE_MAN4] = G_add_hand_tile_MAN4,
	[T_TILE_MAN5] = G_add_hand_tile_MAN5,
	[T_TILE_MAN5_D] = G_add_hand_tile_MAN5_D,
	[T_TILE_MAN6] = G_add_hand_tile_MAN6,
	[T_TILE_MAN7] = G_add_hand_tile_MAN7,
	[T_TILE_MAN8] = G_add_hand_tile_MAN8,
	[T_TILE_MAN9] = G_add_hand_tile_MAN9,
	[T_TILE_PIN1] = G_add_hand_tile_PIN1,
	[T_TILE_PIN2] = G_add_hand_tile_PIN2,
	[T_TILE_PIN3] = G_add_hand_tile_PIN3,
	[T_TILE_PIN4] = G_add_hand_tile_PIN4,
	[T_TILE_PIN5] = G_add_hand_tile_PIN5,
	[T_TILE_PIN5_D] = G_add_hand_tile_PIN5_D,
	[T_TILE_PIN6] = G_add_hand_tile_PIN6,
	[T_TILE_PIN7] = G_add_hand_tile_PIN7,
	[T_TILE_PIN8] = G_add_hand_tile_PIN8,
	[T_TILE_PIN9] = G_add_hand_tile_PIN9,
	[T_TILE_SOU1] = G_add_hand_tile_SOU1,
	[T_TILE_SOU2] = G_add_hand_tile_SOU2,
	[T_TILE_SOU3] = G_add_hand_tile_SOU3,
	[T_TILE_SOU4] = G_add_hand_tile_SOU4,
	[T_TILE_SOU5] = G_add_hand_tile_SOU5,
	[T_TILE_SOU5_D] = G_add_hand_tile_SOU5_D,
	[T_TILE_SOU6] = G_add_hand_tile_SOU6,
	[T_TILE_SOU7] = G_add_hand_tile_SOU7,
	[T_TILE_SOU8] = G_add_hand_tile_SOU8,
	[T_TILE_SOU9] = G_add_hand_tile_SOU9,
	[T_TILE_TON] = G_add_hand_tile_TON,
	[T_TILE_NAN] = G_add_hand_tile_NAN,
	[T_TILE_SHAA] = G_add_hand_tile_SHAA,
	[T_TILE_PEI] = G_add_hand_tile_PEI,
};

void (*on_click_add_dora_tile_funcs[T_TILE_COUNT])(struct G_GameState *) = {
	[T_TILE_CHUN] = G_add_dora_tile_CHUN,
	[T_TILE_HATSU] = G_add_dora_tile_HATSU,
	[T_TILE_HAKU] = G_add_dora_tile_HAKU,
	[T_TILE_MAN1] = G_add_dora_tile_MAN1,
	[T_TILE_MAN2] = G_add_dora_tile_MAN2,
	[T_TILE_MAN3] = G_add_dora_tile_MAN3,
	[T_TILE_MAN4] = G_add_dora_tile_MAN4,
	[T_TILE_MAN5] = G_add_dora_tile_MAN5,
	[T_TILE_MAN5_D] = G_add_dora_tile_MAN5_D,
	[T_TILE_MAN6] = G_add_dora_tile_MAN6,
	[T_TILE_MAN7] = G_add_dora_tile_MAN7,
	[T_TILE_MAN8] = G_add_dora_tile_MAN8,
	[T_TILE_MAN9] = G_add_dora_tile_MAN9,
	[T_TILE_PIN1] = G_add_dora_tile_PIN1,
	[T_TILE_PIN2] = G_add_dora_tile_PIN2,
	[T_TILE_PIN3] = G_add_dora_tile_PIN3,
	[T_TILE_PIN4] = G_add_dora_tile_PIN4,
	[T_TILE_PIN5] = G_add_dora_tile_PIN5,
	[T_TILE_PIN5_D] = G_add_dora_tile_PIN5_D,
	[T_TILE_PIN6] = G_add_dora_tile_PIN6,
	[T_TILE_PIN7] = G_add_dora_tile_PIN7,
	[T_TILE_PIN8] = G_add_dora_tile_PIN8,
	[T_TILE_PIN9] = G_add_dora_tile_PIN9,
	[T_TILE_SOU1] = G_add_dora_tile_SOU1,
	[T_TILE_SOU2] = G_add_dora_tile_SOU2,
	[T_TILE_SOU3] = G_add_dora_tile_SOU3,
	[T_TILE_SOU4] = G_add_dora_tile_SOU4,
	[T_TILE_SOU5] = G_add_dora_tile_SOU5,
	[T_TILE_SOU5_D] = G_add_dora_tile_SOU5_D,
	[T_TILE_SOU6] = G_add_dora_tile_SOU6,
	[T_TILE_SOU7] = G_add_dora_tile_SOU7,
	[T_TILE_SOU8] = G_add_dora_tile_SOU8,
	[T_TILE_SOU9] = G_add_dora_tile_SOU9,
	[T_TILE_TON] = G_add_dora_tile_TON,
	[T_TILE_NAN] = G_add_dora_tile_NAN,
	[T_TILE_SHAA] = G_add_dora_tile_SHAA,
	[T_TILE_PEI] = G_add_dora_tile_PEI,
};

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

void G_on_click_toggle_hand_keyboard(struct G_GameState *gamestate)
{
	if (gamestate->overlayed_menu != G_OVERLAYED_MENU_HAND_KEYBOARD) {
		gamestate->selected_main_menu_option =
			G_SELECTED_MAIN_MENU_OPTION_HAND;
		gamestate->overlayed_menu = G_OVERLAYED_MENU_HAND_KEYBOARD;
	} else {
		G_step_backward_menu(gamestate);
	}
}

void G_on_click_toggle_dora_keyboard(struct G_GameState *gamestate)
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
