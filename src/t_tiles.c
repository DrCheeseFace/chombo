#include <stdlib.h>
#include "t_tiles.h"

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

int T_tile_draw(SDL_Renderer *sdl_renderer, T_Tile tile, SDL_Point *point, int scale)
{
	// render front of tile no face
	SDL_Surface *bmp_front = SDL_LoadBMP(T_TILE_PATHS[T_FRONT]);
	if (!bmp_front) {
		fprintf(stderr, "Failed to load front BMP: %s\n", SDL_GetError());
		return 1;
	}
	SDL_Texture *tex_front = SDL_CreateTextureFromSurface(sdl_renderer, bmp_front);
	if (!tex_front) {
		fprintf(stderr, "Failed to create front texture: %s\n", SDL_GetError());
		SDL_FreeSurface(bmp_front);
		return 1;
	}
	SDL_Rect tile_rect = { point->x, point->y, scale * 4, scale * 5 };
	SDL_RenderCopy(sdl_renderer, tex_front, NULL, &tile_rect);

	SDL_FreeSurface(bmp_front);
	SDL_DestroyTexture(tex_front);

	// render face of tile
	SDL_Surface *bmp_face = SDL_LoadBMP(T_TILE_PATHS[tile]);
	if (!bmp_face) {
		fprintf(stderr, "Failed to load face BMP: %s\n", SDL_GetError());
		return 1;
	}
	SDL_Texture *tex_face = SDL_CreateTextureFromSurface(sdl_renderer, bmp_face);
	if (!tex_face) {
		fprintf(stderr, "Failed to create face texture: %s\n", SDL_GetError());
		SDL_FreeSurface(bmp_face);
		return 1;
	}
	SDL_RenderCopy(sdl_renderer, tex_face, NULL, &tile_rect);

	SDL_FreeSurface(bmp_face);
	SDL_DestroyTexture(tex_face);
	return 0;
}
