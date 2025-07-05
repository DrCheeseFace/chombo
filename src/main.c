#include "g_gamestate.h"
#include "w_window.h"
#include "r_renderer.h"
#include "e_event.h"
#include "l_letter.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdint.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 500
#define WINDOW_S 1
#define TARGET_FPS 20

void main_loop(G_GameState *gamestate, SDL_Renderer *sdl_renderer)
{
	SDL_Event event;
	int redraw = 1;
	int quit = 0;
	while (!quit) {
		G_frame_start(gamestate);

		if (redraw) {
			if (R_draw(sdl_renderer, *gamestate) == 0) {
				redraw = 0;
			}
		}

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = 1;
				break;
			} else {
				redraw = E_handle_event(gamestate, event);
			}
		}

		G_frame_end(gamestate);
	}
}

int main(void)
{
	G_GameState *gamestate =
		G_gamestate_create(TARGET_FPS, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_S);
	SDL_Window *sdl_window = W_create(gamestate->window_w, gamestate->window_h);
	SDL_Renderer *sdl_renderer = R_create(sdl_window, gamestate->window_w, gamestate->window_h);

	if (WINDOW_S != 1) {
		W_window_renderer_resize(sdl_window, sdl_renderer, gamestate->window_w,
					 gamestate->window_h, gamestate->scale);
	}

	L_init();

	main_loop(gamestate, sdl_renderer);

	L_destroy();
	R_destroy(sdl_renderer);
	W_destroy(sdl_window);
	G_destroy(gamestate);

	TTF_Quit();
	SDL_Quit();

	return 0;
}
