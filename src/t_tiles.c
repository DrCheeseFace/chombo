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
	"assets/Back.bmp",	"assets/Blank.bmp",	"assets/Front.bmp",
	"assets/Chun.bmp",	"assets/Hatsu.bmp",	"assets/Haku.bmp",
	"assets/Man1.bmp",	"assets/Man2.bmp",	"assets/Man3.bmp",
	"assets/Man4.bmp",	"assets/Man5.bmp",	"assets/Man5-Dora.bmp",
	"assets/Man6.bmp",	"assets/Man7.bmp",	"assets/Man8.bmp",
	"assets/Man9.bmp",	"assets/Pin1.bmp",	"assets/Pin2.bmp",
	"assets/Pin3.bmp",	"assets/Pin4.bmp",	"assets/Pin5.bmp",
	"assets/Pin5-Dora.bmp", "assets/Pin6.bmp",	"assets/Pin7.bmp",
	"assets/Pin8.bmp",	"assets/Pin9.bmp",	"assets/Sou1.bmp",
	"assets/Sou2.bmp",	"assets/Sou3.bmp",	"assets/Sou4.bmp",
	"assets/Sou5.bmp",	"assets/Sou5-Dora.bmp", "assets/Sou6.bmp",
	"assets/Sou7.bmp",	"assets/Sou8.bmp",	"assets/Sou9.bmp",
	"assets/Ton.bmp",	"assets/Nan.bmp",	"assets/Shaa.bmp",
	"assets/Pei.bmp",
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
	SDL_FRect tile_rect = { point.x, point.y, scale * T_TILE_WIDTH_RATIO,
				scale * T_TILE_HEIGHT_RATIO };
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

// rickerty mf right here
bool T_ttile_to_mtile(T_Tile tile, Tile *mtile)
{
	if (tile >= T_TILE_MAN1 && tile <= T_TILE_MAN9) {
		mtile->tag = Tile_Man;
		mtile->man = tile - T_TILE_MAN1;
	} else if (tile >= T_TILE_PIN1 && tile <= T_TILE_PIN9) {
		mtile->tag = Tile_Pin;
		mtile->pin = tile - T_TILE_PIN1;
	} else if (tile >= T_TILE_SOU1 && tile <= T_TILE_SOU9) {
		mtile->tag = Tile_Sou;
		mtile->sou = tile - T_TILE_SOU1;
	} else if (tile >= T_TILE_TON && tile <= T_TILE_PEI) {
		mtile->tag = Tile_Wind;
		mtile->wind = tile - T_TILE_TON;
	} else if (tile >= T_TILE_CHUN && tile <= T_TILE_HAKU) {
		mtile->tag = Tile_Dragon;
		mtile->dragon = tile - T_TILE_CHUN;
	} else {
		return true;
	}
	return false;
}
