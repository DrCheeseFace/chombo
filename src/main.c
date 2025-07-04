#include "g_gamestate.h"
#include "w_window.h"
#include "r_renderer.h"
#include "e_event.h"
#include "l_letter.h"
#include <stdint.h>

#define WINDOW_W 800
#define WINDOW_H 640
#define TARGET_FPS 60

void main_loop(G_GameState *gamestate, SDL_Renderer *sdl_renderer)
{
	SDL_Event event;
	int redraw = 1;
	int quit = 0;
	while (!quit) {
		G_frame_start(gamestate);

		if (redraw) {
			R_draw(sdl_renderer, *gamestate);
			redraw = 0;
		}

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			} else {
				redraw = E_handle_event(gamestate, event);
			}
		}

		G_frame_end(gamestate);
	}
}

int main(void)
{
	G_GameState *gamestate = G_gamestate_create(TARGET_FPS, WINDOW_W, WINDOW_H);
	SDL_Window *sdl_window = W_create(WINDOW_W, WINDOW_H);
	SDL_Renderer *sdl_renderer = R_create(sdl_window, WINDOW_W, WINDOW_H);
	L_init();

	main_loop(gamestate, sdl_renderer);

	L_destroy();
	R_destroy(sdl_renderer);
	W_destroy(sdl_window);
	G_destroy(gamestate);
	return 0;
}
