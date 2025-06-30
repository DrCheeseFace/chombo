#ifndef W_WINDOW_H
#define W_WINDOW_H

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

SDL_Window *W_create(int width, int height);

void W_destroy(SDL_Window *sdl_window);

#endif
