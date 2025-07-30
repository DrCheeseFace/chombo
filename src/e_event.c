#include "g_gamestate.h"

bool E_handle_key_down(struct G_GameState *gamestate,
		       SDL_KeyboardEvent key_event)
{
	//global event type shit
	switch (key_event.key) {
	case SDLK_SLASH:
		gamestate->show_help = true;
		return true;
	case SDLK_EQUALS:
		if (key_event.mod == SDL_KMOD_LSHIFT ||
		    key_event.mod == SDL_KMOD_RSHIFT) {
			gamestate->scale += 0.1;
			return true;
		}
		break;
	case SDLK_MINUS:
		if (key_event.mod == SDL_KMOD_LSHIFT ||
		    key_event.mod == SDL_KMOD_RSHIFT) {
			gamestate->scale -= 0.1;
			return true;
		}
		break;
	case SDLK_ESCAPE:
		G_backtrack_menu(gamestate);
		return true;
	default:
		break;
	}

	//overlay menu specific event type shit
	switch (gamestate->overlayed_menu) {
	case G_OVERLAYED_MENU_NONE:
		switch (key_event.key) {
		case SDLK_1:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_PIN1;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_SOU1;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_MAN1;
				}
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_PIN1;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_SOU1;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_MAN1;
				}
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_2:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_PIN2;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_SOU2;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_MAN2;
				}
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_PIN2;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_SOU2;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_MAN2;
				}
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_3:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_PIN3;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_SOU3;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_MAN3;
				}
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_PIN3;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_SOU3;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_MAN3;
				}
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_4:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_PIN4;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_SOU4;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_MAN4;
				}
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_PIN4;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_SOU4;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_MAN4;
				}
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_5:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_PIN5;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_SOU5;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_MAN5;
				}
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_PIN5;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_SOU5;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_MAN5;
				}
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_6:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_PIN6;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_SOU6;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_MAN6;
				}
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_PIN6;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_SOU6;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_MAN6;
				}
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_7:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_PIN7;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_SOU7;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_MAN7;
				}
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_PIN7;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_SOU7;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_MAN7;
				}
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_8:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_PIN8;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_SOU8;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_MAN8;
				}
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_PIN8;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_SOU8;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_MAN8;
				}
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_9:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_PIN9;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_SOU9;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_MAN9;
				}
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_PIN9;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_SOU9;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_MAN9;
				}
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_0:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_PIN5_D;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_SOU5_D;
				} else {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len] =
						T_TILE_MAN5_D;
				}
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				if (key_event.mod == SDL_KMOD_LSHIFT ||
				    key_event.mod == SDL_KMOD_RSHIFT) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_PIN5_D;
				} else if (key_event.mod == SDL_KMOD_LCTRL ||
					   key_event.mod == SDL_KMOD_RCTRL) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_SOU5_D;
				} else {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len] =
						T_TILE_MAN5_D;
				}
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_E:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_TILE_TON;
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_TILE_TON;
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_S:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_TILE_NAN;
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_TILE_NAN;
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_W:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_TILE_SHAA;
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_TILE_SHAA;
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_N:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_TILE_PEI;
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_TILE_PEI;
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_C:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_TILE_CHUN;
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_TILE_CHUN;
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_H:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_TILE_HAKU;
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_TILE_HAKU;
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_G:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len ==
				    MAX_HAND_TILE_COUNT) {
					return false;
				}
				gamestate->hand_tiles[gamestate->hand_tiles_len] =
					T_TILE_HATSU;
				gamestate->hand_tiles_len++;
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len ==
				    MAX_DORA_TILE_COUNT) {
					return false;
				}
				gamestate->dora_tiles[gamestate->dora_tiles_len] =
					T_TILE_HATSU;
				gamestate->dora_tiles_len++;
				return true;
			}
			return false;
		case SDLK_BACKSPACE:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				if (gamestate->hand_tiles_len > 0) {
					gamestate->hand_tiles
						[gamestate->hand_tiles_len - 1] =
						T_TILE_BACK;
					gamestate->hand_tiles_len--;
					return true;
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				if (gamestate->dora_tiles_len > 0) {
					gamestate->dora_tiles
						[gamestate->dora_tiles_len - 1] =
						T_TILE_BACK;
					gamestate->dora_tiles_len--;
					return true;
				}
			}
			return false;
		case SDLK_UP:
			G_decrement_main_menu_selector(gamestate);
			return true;
		case SDLK_DOWN:
			G_increment_main_menu_selector(gamestate);
			return true;
		case SDLK_RIGHT:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_SEAT_WIND) {
				G_increment_seat_wind(gamestate);
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_PREVALENT_WIND) {
				G_decrement_prevelant_wind(gamestate);
				return true;
			}
			return false;
		case SDLK_LEFT:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_SEAT_WIND) {
				G_decrement_seat_wind(gamestate);
				return true;
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_PREVALENT_WIND) {
				G_increment_prevelant_wind(gamestate);
				return true;
			}
			return false;

		case SDLK_R:
			gamestate->riichi = !gamestate->riichi;
			return true;
		case SDLK_D:
			gamestate->double_riichi = !gamestate->double_riichi;
			return true;
		case SDLK_I:
			gamestate->ippatsu = !gamestate->ippatsu;
			return true;
		case SDLK_T:
			gamestate->haitei = !gamestate->haitei;
			return true;
		case SDLK_M:
			gamestate->chankan = !gamestate->chankan;
			return true;
		case SDLK_K:
			gamestate->rinshan = !gamestate->rinshan;
			return true;
		case SDLK_RETURN:
			if (G_calculate_handshapes(gamestate)) {
				G_selected_handshape_set(gamestate);
				gamestate->selector_idx = 0;
				if (gamestate->handshapes.hands_len == 1) {
					if (gamestate->handshapes.hands[0]
						    .group_count >= 7) {
						gamestate->overlayed_menu =
							G_OVERLAYED_MENU_WINNING_TILE_SELECTOR;
					} else {
						gamestate->overlayed_menu =
							G_OVERLAYED_MENU_HANDSHAPE_GROUP_OPEN_CLOSE_SELECTOR;
					}
				} else {
					gamestate->overlayed_menu =
						G_OVERLAYED_MENU_HANDSHAPES_SELECTOR;
				}
				return true;
			}
			return false;
		default:
			return false;
		}
	case G_OVERLAYED_MENU_HANDSHAPES_SELECTOR:
		switch (key_event.key) {
		case SDLK_UP:
			G_increment_handshape_selector(gamestate);
			return true;
		case SDLK_DOWN:
			G_decrement_handshape_selector(gamestate);
			return true;
		case SDLK_RETURN:
			G_selected_handshape_set(gamestate);
			gamestate->selector_idx = 0;
			if (gamestate->selected_handshape.group_count >= 7) {
				gamestate->overlayed_menu =
					G_OVERLAYED_MENU_WINNING_TILE_SELECTOR;
			} else {
				gamestate->overlayed_menu =
					G_OVERLAYED_MENU_HANDSHAPE_GROUP_OPEN_CLOSE_SELECTOR;
			}
			return true;
		default:
			return false;
		}
	case G_OVERLAYED_MENU_HANDSHAPE_GROUP_OPEN_CLOSE_SELECTOR:
		switch (key_event.key) {
		case SDLK_UP:
			G_group_selector_increment(gamestate);
			return true;
		case SDLK_DOWN:
			G_group_selector_decrement(gamestate);
			return true;
		case SDLK_SPACE:
			G_group_selector_open_close_toggle(gamestate);
			return true;
		case SDLK_RETURN:
			gamestate->overlayed_menu =
				G_OVERLAYED_MENU_WINNING_TILE_SELECTOR;
			return true;
		default:
			break;
		}
	case G_OVERLAYED_MENU_WINNING_TILE_SELECTOR:
		break;
	case G_OVERLAYED_MENU_COUNT:
		break;
	default:
		break;
	}

	return false;
}

bool E_handle_event(struct G_GameState *gamestate, SDL_Event event)
{
	int redraw;
	switch (event.type) {
	case SDL_EVENT_KEY_UP:
		if (event.key.key == SDLK_SLASH) {
			gamestate->show_help = false;
			return true;
		}
		return false;
	case SDL_EVENT_KEY_DOWN:
		redraw = E_handle_key_down(gamestate, event.key);
		if (redraw) {
			G_calculate_handshapes(gamestate);
			return true;
		}
		return redraw;
	default:
		return false;
	}
}
