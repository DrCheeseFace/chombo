#include "l_letter.h"

#include <stdio.h>

void DEBUG_DRAW_POINTER_COORDS(SDL_Renderer *sdl_renderer)
{
	char coords[128];
	float x, y;
	SDL_GetMouseState(&x, &y);
	SDL_RenderCoordinatesFromWindow(sdl_renderer, x, y, &x, &y);
	sprintf(coords, "(%.2f, %.2f)", x, y);

	L_rewrite_text(sdl_renderer, L_TEXT_DEBUG_COORDS, coords);

	L_draw_text(L_TEXT_DEBUG_COORDS, (struct SDL_Point){ -1, -1 });
}

bool is_pointer_within_bounds(SDL_Renderer *sdl_renderer,
			      SDL_MouseButtonEvent button_event, SDL_FRect rect)
{
	float x, y;
	SDL_RenderCoordinatesFromWindow(sdl_renderer, button_event.x,
					button_event.y, &x, &y);
	return SDL_PointInRectFloat(&(SDL_FPoint){ x, y }, &rect);
}
