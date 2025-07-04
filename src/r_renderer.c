#include "g_gamestate.h"
#include "t_tiles.h"
#include "l_letter.h"

SDL_Renderer *sdl_renderer;
int screen_width, screen_height;

SDL_Renderer *R_create(SDL_Window *window, int width, int height)
{
	sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
	SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl_renderer);

	screen_width = width;
	screen_height = height;

	return sdl_renderer;
}

void R_destroy(SDL_Renderer *sdl_renderer)
{
	SDL_DestroyRenderer(sdl_renderer);
}

void R_draw(SDL_Renderer *sdl_renderer, G_GameState gamestate)
{
	SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl_renderer);
	SDL_Rect tile_rect = { .w = 150, .h = 200, .x = 10, .y = 10 };
	T_tile_draw(sdl_renderer, gamestate.tile, &tile_rect);

	SDL_Point text_pos = { .x = 200, .y = 10 };
	L_draw(sdl_renderer, "like a what?", L_colors[L_WHITE], text_pos, 40);

	text_pos.y += 40;
	L_draw(sdl_renderer, "DRAGON!", L_colors[L_WHITE], text_pos, 100);

	text_pos.y += 100;
	L_draw(sdl_renderer, "red&", L_colors[L_RED], text_pos, 70);

	text_pos.y += 70;
	L_draw(sdl_renderer, "green&", L_colors[L_GREEN], text_pos, 70);

	text_pos.y += 70;
	L_draw(sdl_renderer, "blue&", L_colors[L_BLUE], text_pos, 70);

	SDL_RenderPresent(sdl_renderer);
}
