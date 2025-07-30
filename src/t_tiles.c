#include "t_tiles.h"
#include <stdio.h>

const char *T_TILE_NOTATION[T_TILE_COUNT] = {
	"-1", "-1", "-1",

	"rd", "gd", "wd",

	"1m", "2m", "3m", "4m", "5m", "0m", "6m", "7m", "8m", "9m",

	"1p", "2p", "3p", "4p", "5p", "0p", "6p", "7p", "8p", "9p",

	"1s", "2s", "3s", "4s", "5s", "0s", "6s", "7s", "8s", "9s",

	"Ew", "Sw", "Ww", "Nw"
};

const char *T_TILE_PATHS[T_TILE_COUNT] = {
	"static/Back.bmp",	"static/Blank.bmp",	"static/Front.bmp",
	"static/Chun.bmp",	"static/Hatsu.bmp",	"static/Haku.bmp",
	"static/Man1.bmp",	"static/Man2.bmp",	"static/Man3.bmp",
	"static/Man4.bmp",	"static/Man5.bmp",	"static/Man5-Dora.bmp",
	"static/Man6.bmp",	"static/Man7.bmp",	"static/Man8.bmp",
	"static/Man9.bmp",	"static/Pin1.bmp",	"static/Pin2.bmp",
	"static/Pin3.bmp",	"static/Pin4.bmp",	"static/Pin5.bmp",
	"static/Pin5-Dora.bmp", "static/Pin6.bmp",	"static/Pin7.bmp",
	"static/Pin8.bmp",	"static/Pin9.bmp",	"static/Sou1.bmp",
	"static/Sou2.bmp",	"static/Sou3.bmp",	"static/Sou4.bmp",
	"static/Sou5.bmp",	"static/Sou5-Dora.bmp", "static/Sou6.bmp",
	"static/Sou7.bmp",	"static/Sou8.bmp",	"static/Sou9.bmp",
	"static/Ton.bmp",	"static/Nan.bmp",	"static/Shaa.bmp",
	"static/Pei.bmp",
};

SDL_Texture *T_TILE_TEXTURES[T_TILE_COUNT];

void T_tiles_init(SDL_Renderer *sdl_renderer)
{
	for (int i = 0; i < T_TILE_COUNT; i++) {
		SDL_Surface *bmp = SDL_LoadBMP(T_TILE_PATHS[i]);
		if (!bmp) {
			fprintf(stderr, "Failed to load tile BMP: %s\n",
				SDL_GetError());
		}
		SDL_Texture *tex_front =
			SDL_CreateTextureFromSurface(sdl_renderer, bmp);
		if (!tex_front) {
			fprintf(stderr, "Failed to create tile texture: %s\n",
				SDL_GetError());
		}
		SDL_DestroySurface(bmp);
		T_TILE_TEXTURES[i] = tex_front;
	}
}

void T_tiles_destroy(void)
{
	for (int i = 0; i < T_TILE_COUNT; i++) {
		SDL_DestroyTexture(T_TILE_TEXTURES[i]);
	}
}

bool T_tile_draw(SDL_Renderer *sdl_renderer, T_Tile tile, SDL_Point point,
		 int scale)
{
	// render front of tile no face
	SDL_FRect tile_rect = { point.x, point.y, scale * 4, scale * 5.5 };
	SDL_RenderTexture(sdl_renderer, T_TILE_TEXTURES[T_TILE_FRONT], NULL,
			  &tile_rect);

	// render face of tile
	SDL_RenderTexture(sdl_renderer, T_TILE_TEXTURES[tile], NULL,
			  &tile_rect);

	return false;
}

// rickerty mf right here
T_Tile T_mtile_to_ttile(Tile tile)
{
	switch (tile.tag) {
	case Tile_Man:
		return T_TILE_MAN1 + tile.man;
	case Tile_Pin:
		return T_TILE_PIN1 + tile.pin;
	case Tile_Sou:
		return T_TILE_SOU1 + tile.sou;
	case Tile_Wind:
		return T_TILE_TON + tile.wind;
	case Tile_Dragon:
		return T_TILE_CHUN + tile.dragon;
	default:
		return T_TILE_BLANK;
	}
}
