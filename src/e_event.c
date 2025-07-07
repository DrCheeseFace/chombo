#include "g_gamestate.h"

int E_handle_key_down(G_GameState *gamestate, SDL_KeyboardEvent key_event)
{
	switch (key_event.key) {
	case SDLK_SLASH:
		gamestate->show_help = 1;
		return 1;
	case SDLK_EQUALS:
		if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
			gamestate->scale += 0.1;
			return 1;
		}
		return 0;
	case SDLK_MINUS:
		if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
			gamestate->scale -= 0.1;
			return 1;
		}
		return 0;
	case SDLK_1:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_PIN1;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_SOU1;
			} else {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_MAN1;
			}
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_PIN1;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_SOU1;
			} else {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_MAN1;
			}
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_2:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_PIN2;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_SOU2;
			} else {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_MAN2;
			}
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_PIN2;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_SOU2;
			} else {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_MAN2;
			}
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_3:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_PIN3;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_SOU3;
			} else {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_MAN3;
			}
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_PIN3;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_SOU3;
			} else {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_MAN3;
			}
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_4:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_PIN4;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_SOU4;
			} else {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_MAN4;
			}
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_PIN4;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_SOU4;
			} else {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_MAN4;
			}
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_5:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_PIN5;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_SOU5;
			} else {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_MAN5;
			}
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_PIN5;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_SOU5;
			} else {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_MAN5;
			}
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_6:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_PIN6;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_SOU6;
			} else {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_MAN6;
			}
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_PIN6;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_SOU6;
			} else {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_MAN6;
			}
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_7:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_PIN7;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_SOU7;
			} else {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_MAN7;
			}
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_PIN7;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_SOU7;
			} else {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_MAN7;
			}
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_8:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_PIN8;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_SOU8;
			} else {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_MAN8;
			}
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_PIN8;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_SOU8;
			} else {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_MAN8;
			}
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_9:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_PIN9;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_SOU9;
			} else {
				gamestate->hand_tiles[gamestate->hand_tiles_len] = T_MAN9;
			}
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			if (key_event.mod == SDL_KMOD_LSHIFT || key_event.mod == SDL_KMOD_RSHIFT) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_PIN9;
			} else if (key_event.mod == SDL_KMOD_LCTRL ||
				   key_event.mod == SDL_KMOD_RCTRL) {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_SOU9;
			} else {
				gamestate->dora_tiles[gamestate->dora_tiles_len] = T_MAN9;
			}
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_E:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			gamestate->hand_tiles[gamestate->hand_tiles_len] = T_TON;
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			gamestate->dora_tiles[gamestate->dora_tiles_len] = T_TON;
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_S:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			gamestate->hand_tiles[gamestate->hand_tiles_len] = T_NAN;
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			gamestate->dora_tiles[gamestate->dora_tiles_len] = T_NAN;
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_W:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			gamestate->hand_tiles[gamestate->hand_tiles_len] = T_SHAA;
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			gamestate->dora_tiles[gamestate->dora_tiles_len] = T_SHAA;
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_N:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			gamestate->hand_tiles[gamestate->hand_tiles_len] = T_PEI;
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			gamestate->dora_tiles[gamestate->dora_tiles_len] = T_PEI;
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_C:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			gamestate->hand_tiles[gamestate->hand_tiles_len] = T_CHUN;
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			gamestate->dora_tiles[gamestate->dora_tiles_len] = T_CHUN;
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_H:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			gamestate->hand_tiles[gamestate->hand_tiles_len] = T_HAKU;
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			gamestate->dora_tiles[gamestate->dora_tiles_len] = T_HAKU;
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_G:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len == MAX_HAND_TILE_COUNT) {
				return 0;
			}
			gamestate->hand_tiles[gamestate->hand_tiles_len] = T_HATSU;
			gamestate->hand_tiles_len++;
		} else {
			if (gamestate->dora_tiles_len == MAX_DORA_TILE_COUNT) {
				return 0;
			}
			gamestate->dora_tiles[gamestate->dora_tiles_len] = T_HATSU;
			gamestate->dora_tiles_len++;
		}
		return 1;
	case SDLK_BACKSPACE:
		if (gamestate->toggle_hand_dora_focus == 0) {
			if (gamestate->hand_tiles_len > 0) {
				gamestate->hand_tiles[gamestate->hand_tiles_len - 1] = T_BACK;
				gamestate->hand_tiles_len--;
				return 1;
			}
		} else {
			if (gamestate->dora_tiles_len > 0) {
				gamestate->dora_tiles[gamestate->dora_tiles_len - 1] = T_BACK;
				gamestate->dora_tiles_len--;
				return 1;
			}
		}
		return 0;
	case SDLK_SPACE:
		gamestate->toggle_hand_dora_focus = !gamestate->toggle_hand_dora_focus;
		return 1;
	default:
		return 0;
	}
}

int E_handle_event(G_GameState *gamestate, SDL_Event event)
{
	switch (event.type) {
	case SDL_EVENT_KEY_UP:
		gamestate->show_help = 0;
		return 1;
	case SDL_EVENT_KEY_DOWN:
		return E_handle_key_down(gamestate, event.key);
	default:
		return 0;
	}
}
