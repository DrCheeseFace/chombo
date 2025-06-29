#ifndef R_RENDERER_H
#define R_RENDERER_H

#include <SDL2/SDL.h>

void R_init(SDL_Window *window);

void R_destroy(void);

SDL_Renderer *R_get(void);

void R_sanity_check(void);

#endif // !R_RENDERER_H
