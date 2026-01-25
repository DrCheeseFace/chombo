#ifndef G_GAMESTATE_BUTTON_HANDLERS_H
#define G_GAMESTATE_BUTTON_HANDLERS_H

#include "g_gamestate.h"

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

#endif // !G_GAMESTATE_BUTTON_HANDLERS_H
