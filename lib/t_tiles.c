#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_surface.h>
#include <stdlib.h>
#include "t_tiles.h"
#include "util.h"

const char *T_TILE_PATHS[] = {
	"static/Back.bmp",	"static/Blank.bmp", "static/Front.bmp",	    "static/Chun.bmp",
	"static/Haku.bmp",	"static/Hatsu.bmp", "static/Man1.bmp",	    "static/Man2.bmp",
	"static/Man3.bmp",	"static/Man4.bmp",  "static/Man5-Dora.bmp", "static/Man5.bmp",
	"static/Man6.bmp",	"static/Man7.bmp",  "static/Man8.bmp",	    "static/Man9.bmp",
	"static/Pin1.bmp",	"static/Pin2.bmp",  "static/Pin3.bmp",	    "static/Pin4.bmp",
	"static/Pin5-Dora.bmp", "static/Pin5.bmp",  "static/Pin6.bmp",	    "static/Pin7.bmp",
	"static/Pin8.bmp",	"static/Pin9.bmp",  "static/Sou1.bmp",	    "static/Sou2.bmp",
	"static/Sou3.bmp",	"static/Sou4.bmp",  "static/Sou5-Dora.bmp", "static/Sou5.bmp",
	"static/Sou6.bmp",	"static/Sou7.bmp",  "static/Sou8.bmp",	    "static/Sou9.bmp",
	"static/Ton.bmp",	"static/Nan.bmp",   "static/Pei.bmp",	    "static/Shaa.bmp"
};

void T_tile_draw(SDL_Renderer *sdl_renderer, T_TILE tile, int width, int height, int x, int y)
{
	SDL_Rect *tile_rect = malloc(sizeof(SDL_Rect));
	tile_rect->w = width;
	tile_rect->h = height;
	tile_rect->x = x;
	tile_rect->y = y;

	// render front of tile no face
	SDL_Surface *bmp = SDL_LoadBMP(T_TILE_PATHS[T_FRONT]);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(sdl_renderer, bmp);
	SDL_RenderCopy(sdl_renderer, tex, NULL, tile_rect);

	// render face of tile
	bmp = SDL_LoadBMP(T_TILE_PATHS[tile]);
	tex = SDL_CreateTextureFromSurface(sdl_renderer, bmp);
	SDL_RenderCopy(sdl_renderer, tex, NULL, tile_rect);

	SDL_FreeSurface(bmp);
	SDL_DestroyTexture(tex);
	free(tile_rect);
}
