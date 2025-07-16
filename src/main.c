#include "w_window.h"
#include "r_renderer.h"
#include "e_event.h"
#include "l_letter.h"
#include <SDL3_ttf/SDL_ttf.h>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 1000
#define WINDOW_S 0.5
#define TARGET_FPS 35

void main_loop(G_GameState *gamestate, SDL_Window *sdl_window, SDL_Renderer *sdl_renderer)
{
	SDL_Event event;
	int redraw = 1;
	int quit = 0;
	while (!quit) {
		G_frame_start(gamestate);

		if (redraw) {
			redraw = R_gamestate_draw(sdl_renderer, sdl_window, *gamestate);
		}

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				quit = 1;
				break;
			} else {
				redraw = E_handle_event(gamestate, event) || redraw;
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
		G_window_renderer_resize(sdl_window, sdl_renderer, gamestate->window_w,
					 gamestate->window_h, gamestate->scale);
	}

	L_init(sdl_renderer);

	main_loop(gamestate, sdl_window, sdl_renderer);

	L_destroy();
	R_destroy(sdl_renderer);
	W_destroy(sdl_window);
	G_destroy(gamestate);

	TTF_Quit();
	SDL_Quit();

	return 0;
}
