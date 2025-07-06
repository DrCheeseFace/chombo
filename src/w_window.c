#include "w_window.h"

SDL_Window *W_create(int width, int height)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *sdl_window = SDL_CreateWindow("chombo", width, height, 0);
	return sdl_window;
}

void W_destroy(SDL_Window *sdl_window)
{
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
}
