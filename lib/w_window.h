#ifndef W_WINDOW_H
#define W_WINDOW_H

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

void W_init(int width, int height);

void W_destroy(void);

SDL_Window *W_get(void);

#endif
