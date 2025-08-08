#include "g_gamestate.h"
#include "t_tiles.h"

bool E_handle_key_down(struct G_GameState *gamestate,
		       SDL_Renderer *sdl_renderer, SDL_KeyboardEvent key_event)
{
	//global event type shit
	switch (key_event.key) {
	case SDLK_SLASH:
		gamestate->show_help = true;
		return true;
	case SDLK_EQUALS:
		if (key_event.mod | SDL_KMOD_SHIFT) {
			gamestate->scale += 0.1;
			return true;
		}
		break;
	case SDLK_MINUS:
		if (key_event.mod | SDL_KMOD_SHIFT) {
			gamestate->scale -= 0.1;
			return true;
		}
		break;
	case SDLK_ESCAPE:
		G_backtrack_menu(gamestate);
		return true;
	case SDLK_COMMA:
		G_clear_menus_state(gamestate);
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
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_hand_add_tile(gamestate,
							       T_TILE_PIN1);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_hand_add_tile(gamestate,
							       T_TILE_SOU1);
				default:
					return G_hand_add_tile(gamestate,
							       T_TILE_MAN1);
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_dora_add_tile(gamestate,
							       T_TILE_PIN1);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_dora_add_tile(gamestate,
							       T_TILE_SOU1);
				default:
					return G_dora_add_tile(gamestate,
							       T_TILE_MAN1);
				}
			}
			return false;
		case SDLK_2:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_hand_add_tile(gamestate,
							       T_TILE_PIN2);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_hand_add_tile(gamestate,
							       T_TILE_SOU2);
				default:
					return G_hand_add_tile(gamestate,
							       T_TILE_MAN2);
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_dora_add_tile(gamestate,
							       T_TILE_PIN2);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_dora_add_tile(gamestate,
							       T_TILE_SOU2);
				default:
					return G_dora_add_tile(gamestate,
							       T_TILE_MAN2);
				}
			}
			return false;
		case SDLK_3:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_hand_add_tile(gamestate,
							       T_TILE_PIN3);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_hand_add_tile(gamestate,
							       T_TILE_SOU3);
				default:
					return G_hand_add_tile(gamestate,
							       T_TILE_MAN3);
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_dora_add_tile(gamestate,
							       T_TILE_PIN3);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_dora_add_tile(gamestate,
							       T_TILE_SOU3);
				default:
					return G_dora_add_tile(gamestate,
							       T_TILE_MAN3);
				}
			}
			return false;
		case SDLK_4:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_hand_add_tile(gamestate,
							       T_TILE_PIN4);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_hand_add_tile(gamestate,
							       T_TILE_SOU4);
				default:
					return G_hand_add_tile(gamestate,
							       T_TILE_MAN4);
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_dora_add_tile(gamestate,
							       T_TILE_PIN4);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_dora_add_tile(gamestate,
							       T_TILE_SOU4);
				default:
					return G_dora_add_tile(gamestate,
							       T_TILE_MAN4);
				}
			}
			return false;
		case SDLK_5:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_hand_add_tile(gamestate,
							       T_TILE_PIN5);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_hand_add_tile(gamestate,
							       T_TILE_SOU5);
				default:
					return G_hand_add_tile(gamestate,
							       T_TILE_MAN5);
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_dora_add_tile(gamestate,
							       T_TILE_PIN5);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_dora_add_tile(gamestate,
							       T_TILE_SOU5);
				default:
					return G_dora_add_tile(gamestate,
							       T_TILE_MAN5);
				}
			}
			return false;
		case SDLK_6:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_hand_add_tile(gamestate,
							       T_TILE_PIN6);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_hand_add_tile(gamestate,
							       T_TILE_SOU6);
				default:
					return G_hand_add_tile(gamestate,
							       T_TILE_MAN6);
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_dora_add_tile(gamestate,
							       T_TILE_PIN6);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_dora_add_tile(gamestate,
							       T_TILE_SOU6);
				default:
					return G_dora_add_tile(gamestate,
							       T_TILE_MAN6);
				}
			}
			return false;
		case SDLK_7:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_hand_add_tile(gamestate,
							       T_TILE_PIN7);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_hand_add_tile(gamestate,
							       T_TILE_SOU7);
				default:
					return G_hand_add_tile(gamestate,
							       T_TILE_MAN7);
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_dora_add_tile(gamestate,
							       T_TILE_PIN7);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_dora_add_tile(gamestate,
							       T_TILE_SOU7);
				default:
					return G_dora_add_tile(gamestate,
							       T_TILE_MAN7);
				}
			}
			return false;
		case SDLK_8:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_hand_add_tile(gamestate,
							       T_TILE_PIN8);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_hand_add_tile(gamestate,
							       T_TILE_SOU8);
				default:
					return G_hand_add_tile(gamestate,
							       T_TILE_MAN8);
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_dora_add_tile(gamestate,
							       T_TILE_PIN8);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_dora_add_tile(gamestate,
							       T_TILE_SOU8);
				default:
					return G_dora_add_tile(gamestate,
							       T_TILE_MAN8);
				}
			}
			return false;
		case SDLK_9:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_hand_add_tile(gamestate,
							       T_TILE_PIN9);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_hand_add_tile(gamestate,
							       T_TILE_SOU9);
				default:
					return G_hand_add_tile(gamestate,
							       T_TILE_MAN9);
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_dora_add_tile(gamestate,
							       T_TILE_PIN9);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_dora_add_tile(gamestate,
							       T_TILE_SOU9);
				default:
					return G_dora_add_tile(gamestate,
							       T_TILE_MAN9);
				}
			}
			return false;
		case SDLK_0:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_hand_add_tile(gamestate,
							       T_TILE_PIN5_D);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_hand_add_tile(gamestate,
							       T_TILE_SOU5_D);
				default:
					return G_hand_add_tile(gamestate,
							       T_TILE_MAN5_D);
				}
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				switch (key_event.mod) {
				case (SDL_KMOD_LSHIFT):
				case (SDL_KMOD_RSHIFT):
					return G_dora_add_tile(gamestate,
							       T_TILE_PIN5_D);
				case (SDL_KMOD_LCTRL):
				case (SDL_KMOD_RCTRL):
					return G_dora_add_tile(gamestate,
							       T_TILE_SOU5_D);
				default:
					return G_dora_add_tile(gamestate,
							       T_TILE_MAN5_D);
				}
			}
			return false;
		case SDLK_E:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				return G_hand_add_tile(gamestate, T_TILE_TON);
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				return G_dora_add_tile(gamestate, T_TILE_TON);
			}
			return false;
		case SDLK_S:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				return G_hand_add_tile(gamestate, T_TILE_NAN);
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				return G_dora_add_tile(gamestate, T_TILE_NAN);
			}
			return false;
		case SDLK_W:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				return G_hand_add_tile(gamestate, T_TILE_SHAA);
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				return G_dora_add_tile(gamestate, T_TILE_SHAA);
			}
			return false;
		case SDLK_N:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				return G_hand_add_tile(gamestate, T_TILE_PEI);
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				return G_dora_add_tile(gamestate, T_TILE_PEI);
			}
			return false;
		case SDLK_C:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				return G_hand_add_tile(gamestate, T_TILE_CHUN);
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				return G_dora_add_tile(gamestate, T_TILE_CHUN);
			}
			return false;
		case SDLK_H:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				return G_hand_add_tile(gamestate, T_TILE_HAKU);
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				return G_dora_add_tile(gamestate, T_TILE_HAKU);
			}
			return false;
		case SDLK_G:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				return G_hand_add_tile(gamestate, T_TILE_HATSU);

			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				return G_dora_add_tile(gamestate, T_TILE_HATSU);
			}
			return false;
		case SDLK_BACKSPACE:
			if (gamestate->selected_main_menu_option ==
			    G_SELECTED_MAIN_MENU_OPTION_HAND) {
				return G_hand_delete_tile(gamestate);
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_DORA) {
				return G_dora_delete_tile(gamestate);
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
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_HONBA) {
				G_increment_honba_counter(gamestate,
							  sdl_renderer);
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
			} else if (gamestate->selected_main_menu_option ==
				   G_SELECTED_MAIN_MENU_OPTION_HONBA) {
				G_decrement_honba_counter(gamestate,
							  sdl_renderer);
				return true;
			}
			return false;

		case SDLK_T:
			gamestate->conditions.tsumo =
				!gamestate->conditions.tsumo;
			return true;
		case SDLK_R:
			gamestate->conditions.riichi =
				!gamestate->conditions.riichi;
			return true;
		case SDLK_D:
			gamestate->conditions.double_riichi =
				!gamestate->conditions.double_riichi;
			return true;
		case SDLK_I:
			gamestate->conditions.ippatsu =
				!gamestate->conditions.ippatsu;
			return true;
		case SDLK_Z:
			gamestate->conditions.haitei =
				!gamestate->conditions.haitei;
			return true;
		case SDLK_M:
			gamestate->conditions.chankan =
				!gamestate->conditions.chankan;
			return true;
		case SDLK_K:
			gamestate->conditions.rinshan =
				!gamestate->conditions.rinshan;
			return true;
		case SDLK_U:
			gamestate->conditions.tenhou =
				!gamestate->conditions.tenhou;
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
			gamestate->selector_idx = 0;
			gamestate->overlayed_menu =
				G_OVERLAYED_MENU_WINNING_TILE_SELECTOR;
			return true;
		default:
			break;
		}
		break;
	case G_OVERLAYED_MENU_WINNING_TILE_SELECTOR:
		switch (key_event.key) {
		case SDLK_LEFT:
			G_winning_tile_selector_decrement(gamestate);
			return true;
		case SDLK_RIGHT:
			G_winning_tile_selector_increment(gamestate);
			return true;
		case SDLK_RETURN:
			G_winning_tile_set(gamestate);
			gamestate->selector_idx = 0;
			gamestate->show_score_err =
				!G_calculate_score(gamestate);
			gamestate->overlayed_menu = G_OVERLAYED_MENU_SCORE_VIEW;
			return true;
		default:
			break;
		}
		break;
	case G_OVERLAYED_MENU_SCORE_VIEW:
		switch (key_event.key) {
		default:
			break;
		}
		break;
	case G_OVERLAYED_MENU_COUNT:
		break;
	default:
		break;
	}

	return false;
}

bool E_handle_event(struct G_GameState *gamestate, SDL_Renderer *sdl_renderer,
		    SDL_Event event)
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
		redraw = E_handle_key_down(gamestate, sdl_renderer, event.key);
		if (redraw) {
			G_calculate_handshapes(gamestate);
			return true;
		}
		return redraw;
	default:
		return false;
	}
}
