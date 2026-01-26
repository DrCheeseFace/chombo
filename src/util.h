#ifndef UTIL_H
#define UTIL_H

#include <SDL3/SDL.h>

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 1000
#define WINDOW_SCALE (float)0.5
#define TARGET_FPS 35

#define MAX_ALLOCATED_TEXTURES 20

#define PLACEHOLDER_TEXT "ERR"

#define SCORE_SPACER "/"

bool is_pointer_within_bounds(SDL_Renderer *sdl_renderer,
			      SDL_MouseButtonEvent button_event,
			      SDL_FRect rect);

void DEBUG_DRAW_POINTER_COORDS(SDL_Renderer *sdl_renderer);

#endif // !UTIL_H
