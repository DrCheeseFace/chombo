#include "r_renderer.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

SDL_Renderer *sdl_renderer = NULL;

void R_init(SDL_Window *window) {
	SDL_Renderer *sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
	SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl_renderer);
}

void R_destroy(void) {
	SDL_DestroyRenderer(sdl_renderer);
}

void R_sanity_check(void) {
	SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
	SDL_RenderDrawPoint(sdl_renderer, 50, 50);
	SDL_RenderPresent(sdl_renderer);
	SDL_Delay(1000);
}

SDL_Renderer *R_get(void) {
	return sdl_renderer;
}
