#ifndef G_GAMESTATE_BUTTON_HANDLERS_H
#define G_GAMESTATE_BUTTON_HANDLERS_H

#include "g_gamestate.h"

#define HAND_TILE_LIST                                                         \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(CHUN)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(HATSU)                             \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(HAKU)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(MAN1)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(MAN2)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(MAN3)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(MAN4)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(MAN5)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(MAN5_D)                            \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(MAN6)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(MAN7)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(MAN8)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(MAN9)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PIN1)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PIN2)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PIN3)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PIN4)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PIN5)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PIN5_D)                            \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PIN6)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PIN7)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PIN8)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PIN9)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SOU1)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SOU2)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SOU3)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SOU4)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SOU5)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SOU5_D)                            \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SOU6)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SOU7)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SOU8)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SOU9)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(TON)                               \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(NAN)                               \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(SHAA)                              \
	DEFINE_ON_CLICK_ADD_HAND_TILE_FUNCS(PEI)

#define DORA_TILE_LIST                                                         \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(CHUN)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(HATSU)                             \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(HAKU)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(MAN1)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(MAN2)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(MAN3)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(MAN4)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(MAN5)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(MAN5_D)                            \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(MAN6)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(MAN7)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(MAN8)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(MAN9)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PIN1)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PIN2)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PIN3)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PIN4)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PIN5)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PIN5_D)                            \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PIN6)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PIN7)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PIN8)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PIN9)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SOU1)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SOU2)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SOU3)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SOU4)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SOU5)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SOU5_D)                            \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SOU6)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SOU7)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SOU8)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SOU9)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(TON)                               \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(NAN)                               \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(SHAA)                              \
	DEFINE_ON_CLICK_ADD_DORA_TILE_FUNCS(PEI)

void G_on_click_toggle_tsumo(struct G_GameState *gamestate);
void G_on_click_toggle_riichi(struct G_GameState *gamestate);
void G_on_click_toggle_double_riichi(struct G_GameState *gamestate);
void G_on_click_toggle_ippatsu(struct G_GameState *gamestate);
void G_on_click_toggle_haitei(struct G_GameState *gamestate);
void G_on_click_toggle_chankan(struct G_GameState *gamestate);
void G_on_click_toggle_rinshan(struct G_GameState *gamestate);
void G_on_click_toggle_tenhou(struct G_GameState *gamestate);
void G_on_click_select_prevalent_ton(struct G_GameState *gamestate);
void G_on_click_select_prevalent_nan(struct G_GameState *gamestate);
void G_on_click_select_prevalent_shaa(struct G_GameState *gamestate);
void G_on_click_select_prevalent_pei(struct G_GameState *gamestate);
void G_on_click_select_seat_ton(struct G_GameState *gamestate);
void G_on_click_select_seat_nan(struct G_GameState *gamestate);
void G_on_click_select_seat_shaa(struct G_GameState *gamestate);
void G_on_click_select_seat_pei(struct G_GameState *gamestate);
void G_on_click_honba_up(struct G_GameState *gamestate);
void G_on_click_honba_down(struct G_GameState *gamestate);
bool G_destroy_main_menu_button(struct G_GameState *gamestate);

void G_on_click_toggle_hand_keyboard(struct G_GameState *gamestate);
void G_on_click_toggle_dora_keyboard(struct G_GameState *gamestate);
bool G_destroy_toggle_hand_dora_keyboard_button(struct G_GameState *gamestate);

extern void (*on_click_add_hand_tile_funcs[T_TILE_COUNT])(struct G_GameState *);
extern void (*on_click_add_dora_tile_funcs[T_TILE_COUNT])(struct G_GameState *);
bool G_destroy_hand_keyboard_button(struct G_GameState *gamestate);
bool G_destroy_dora_keyboard_button(struct G_GameState *gamestate);

#endif // !G_GAMESTATE_BUTTON_HANDLERS_H
