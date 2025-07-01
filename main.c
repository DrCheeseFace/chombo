#include "lib/g_gamestate.h"
#include "lib/w_window.h"
#include "lib/r_renderer.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdint.h>

#define WINDOW_W 800
#define WINDOW_H 640
#define TARGET_FPS 60

/*event -> alters map/player/gamestate -> calculate magic pixel array -> render dat hoe*/
void main_loop(G_GameState *gamestate, SDL_Renderer *sdl_renderer)
{
	SDL_Event event;
	int quit = 0;
	while (!quit) {
		G_frame_start(gamestate);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
			if (event.type == SDL_KEYDOWN) {
				quit = 0;
			}
		}

		R_draw(sdl_renderer);
		G_frame_end(gamestate);
	}
}

int main(void)
{
	G_GameState *gamestate = G_gamestate_create(TARGET_FPS, WINDOW_W, WINDOW_H);
	SDL_Window *sdl_window = W_create(WINDOW_W, WINDOW_H);
	SDL_Renderer *sdl_renderer = R_create(sdl_window, WINDOW_W, WINDOW_H);

	main_loop(gamestate, sdl_renderer);

	R_destroy(sdl_renderer);
	W_destroy(sdl_window);
	G_destroy(gamestate);
	return 0;
}
