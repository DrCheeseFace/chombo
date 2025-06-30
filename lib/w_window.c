#include "w_window.h"

SDL_Window *sdl_window = NULL;

void W_init(int width, int height)
{
	SDL_Init(SDL_INIT_VIDEO);
	sdl_window = SDL_CreateWindow("drdoom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				      width, height, SDL_WINDOW_SHOWN);
}

void W_destroy(void)
{
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
}

SDL_Window *W_get(void)
{
	return sdl_window;
}
