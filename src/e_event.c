#include "g_gamestate.h"

int E_handle_key_down(G_GameState *gamestate, SDL_KeyboardEvent key_event)
{
	if (key_event.key == SDLK_SLASH) {
		gamestate->show_help = 1;
		return 1;
	} else if (key_event.key == SDLK_EQUALS) {
		if (key_event.mod == SDL_KMOD_LSHIFT ||
		    key_event.mod == SDL_KMOD_RSHIFT) {
			gamestate->scale += 0.1;
			return 1;
		}
	} else if (key_event.key == SDLK_MINUS) {
		if (key_event.mod == SDL_KMOD_LSHIFT ||
		    key_event.mod == SDL_KMOD_RSHIFT) {
			gamestate->scale -= 0.1;
			return 1;
		}
	}

	switch (gamestate->overlayed_menu) {
	case G_OVERLAYED_MENU_NONE:
		switch (key_event.key) {
		case SDLK_1:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_PIN1;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_SOU1;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_MAN1;
				}
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_PIN1;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_SOU1;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_MAN1;
				}
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_2:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_PIN2;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_SOU2;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_MAN2;
				}
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_PIN2;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_SOU2;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_MAN2;
				}
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_3:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_PIN3;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_SOU3;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_MAN3;
				}
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_PIN3;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_SOU3;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_MAN3;
				}
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_4:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_PIN4;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_SOU4;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_MAN4;
				}
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_PIN4;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_SOU4;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_MAN4;
				}
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_5:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_PIN5;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_SOU5;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_MAN5;
				}
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_PIN5;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_SOU5;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_MAN5;
				}
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_6:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_PIN6;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_SOU6;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_MAN6;
				}
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_PIN6;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_SOU6;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_MAN6;
				}
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_7:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_PIN7;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_SOU7;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_MAN7;
				}
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_PIN7;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_SOU7;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_MAN7;
				}
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_8:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_PIN8;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_SOU8;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_MAN8;
				}
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_PIN8;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_SOU8;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_MAN8;
				}
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_9:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_PIN9;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_SOU9;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_MAN9;
				}
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_PIN9;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_SOU9;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_MAN9;
				}
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_0:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_PIN5_D;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_SOU5_D;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_MAN5_D;
				}
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_PIN5_D;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_SOU5_D;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_MAN5_D;
				}
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_E:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_TON;
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_TON;
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_S:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_NAN;
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_NAN;
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_W:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_SHAA;
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_SHAA;
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_N:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_PEI;
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_PEI;
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_C:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_CHUN;
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_CHUN;
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_H:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_HAKU;
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_HAKU;
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_G:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return 0;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_HATSU;
				gamestate->hand_tiles_len++;
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return 0;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_HATSU;
				gamestate->dora_tiles_len++;
				return 1;
			}
			return 0;
		case SDLK_BACKSPACE:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len > 0) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len - 1] =
						T_BACK;
					gamestate->hand_tiles_len--;
					return 1;
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len > 0) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len - 1] =
						T_BACK;
					gamestate->dora_tiles_len--;
					return 1;
				}
			}
			return 0;
		case SDLK_UP:
			G_decrement_main_menu_selector(gamestate);
			return 1;
		case SDLK_DOWN:
			G_increment_main_menu_selector(gamestate);
			return 1;
		case SDLK_RIGHT:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_SEAT_WIND) {
				G_increment_seat_wind(gamestate);
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_PREVALENT_WIND) {
				G_decrement_prevelant_wind(gamestate);
				return 1;
			}
			return 0;
		case SDLK_LEFT:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_SEAT_WIND) {
				G_decrement_seat_wind(gamestate);
				return 1;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_PREVALENT_WIND) {
				G_increment_prevelant_wind(gamestate);
				return 1;
			}
			return 0;

		case SDLK_R:
			gamestate->riichi = !gamestate->riichi;
			return 1;
		case SDLK_D:
			gamestate->double_riichi = !gamestate->double_riichi;
			return 1;
		case SDLK_I:
			gamestate->ippatsu = !gamestate->ippatsu;
			return 1;
		case SDLK_T:
			gamestate->haitei = !gamestate->haitei;
			return 1;
		case SDLK_M:
			gamestate->chankan = !gamestate->chankan;
			return 1;
		case SDLK_K:
			gamestate->rinshan = !gamestate->rinshan;
			return 1;
		case SDLK_RETURN:
			if (G_calculate_handshapes(gamestate)) {
				gamestate->overlayed_menu =
					G_OVERLAYED_MENU_HANDSHAPES_SELECTOR;
				return 1;
			}
			return 0;
		default:
			return 0;
		}
	case G_OVERLAYED_MENU_HANDSHAPES_SELECTOR:
		switch (key_event.key) {
		case SDLK_UP:
			G_increment_handshape_selector(gamestate);
			return 1;
		case SDLK_DOWN:
			G_decrement_handshape_selector(gamestate);
			return 1;
		case SDLK_ESCAPE:
			gamestate->overlayed_menu = G_OVERLAYED_MENU_NONE;
			return 1;
		default:
			return 0;
		}
	case G_OVERLAYED_MENU_COUNT:
		break;
	default:
		break;
	}

	return 0;
}

int E_handle_event(G_GameState *gamestate, SDL_Event event)
{
	int redraw;
	switch (event.type) {
	case SDL_EVENT_KEY_UP:
		gamestate->show_help = 0;
		return 1;
	case SDL_EVENT_KEY_DOWN:
		redraw = E_handle_key_down(gamestate, event.key);
		if (redraw) {
			G_calculate_handshapes(gamestate);
			return 1;
		}
		return redraw;
	default:
		return 0;
	}
}
