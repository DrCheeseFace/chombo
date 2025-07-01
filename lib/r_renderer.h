#ifndef R_RENDERER_H
#define R_RENDERER_H

#include <SDL2/SDL.h>

SDL_Renderer *R_create(SDL_Window *window, int width, int height);

void R_destroy(SDL_Renderer *sdl_renderer);

// BAD BOY! STOP THAT
SDL_Renderer *R_get(SDL_Renderer *sdl_renderer);

void R_draw(SDL_Renderer *sdl_renderer);

void R_sanity_check(SDL_Renderer *sdl_renderer);

#endif // !R_RENDERER_H
