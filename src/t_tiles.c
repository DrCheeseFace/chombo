#include <stdio.h>
#include "t_tiles.h"

const char *T_TILE_NOTATION[T_COUNT] = { "-1", "-1", "-1",

					 "rd", "wd", "gd",

					 "1m", "2m", "3m", "4m", "0m", "5m", "6m", "7m", "8m", "9m",

					 "1p", "2p", "3p", "4p", "0p", "5p", "6p", "7p", "8p", "9p",

					 "1s", "2s", "3s", "4s", "0s", "5s", "6s", "7s", "8s", "9s",

					 "Ew", "Sw", "Nw", "Ww" };

const char *T_TILE_PATHS[T_COUNT] = {
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

SDL_Texture *T_TILE_TEXTURES[T_COUNT];

void T_tiles_init(SDL_Renderer *sdl_renderer)
{
	for (int i = 0; i < T_COUNT; i++) {
		SDL_Surface *bmp = SDL_LoadBMP(T_TILE_PATHS[i]);
		if (!bmp) {
			fprintf(stderr, "Failed to load tile BMP: %s\n", SDL_GetError());
		}
		SDL_Texture *tex_front = SDL_CreateTextureFromSurface(sdl_renderer, bmp);
		if (!tex_front) {
			fprintf(stderr, "Failed to create tile texture: %s\n", SDL_GetError());
		}
		SDL_DestroySurface(bmp);
		T_TILE_TEXTURES[i] = tex_front;
	}
}

void T_tiles_destroy(void)
{
	for (int i = 0; i < T_COUNT; i++) {
		SDL_DestroyTexture(T_TILE_TEXTURES[i]);
	}
}

int T_tile_draw(SDL_Renderer *sdl_renderer, T_Tile tile, SDL_Point point, int scale)
{
	// render front of tile no face
	SDL_FRect tile_rect = { point.x, point.y, scale * 4, scale * 5.5 };
	SDL_RenderTexture(sdl_renderer, T_TILE_TEXTURES[T_FRONT], NULL, &tile_rect);

	// render face of tile
	SDL_RenderTexture(sdl_renderer, T_TILE_TEXTURES[tile], NULL, &tile_rect);

	return 0;
}
