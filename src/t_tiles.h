#ifndef T_TILES_H
#define T_TILES_H

#include "mahc.h"
#include <SDL3/SDL.h>

extern const char *T_TILE_PATHS[];

typedef enum {
	T_TILE_BACK = 0,
	T_TILE_BLANK,
	T_TILE_FRONT,

	T_TILE_CHUN,
	T_TILE_HATSU,
	T_TILE_HAKU,

	T_TILE_MAN1,
	T_TILE_MAN2,
	T_TILE_MAN3,
	T_TILE_MAN4,
	T_TILE_MAN5,
	T_TILE_MAN5_D,
	T_TILE_MAN6,
	T_TILE_MAN7,
	T_TILE_MAN8,
	T_TILE_MAN9,

	T_TILE_PIN1,
	T_TILE_PIN2,
	T_TILE_PIN3,
	T_TILE_PIN4,
	T_TILE_PIN5,
	T_TILE_PIN5_D,
	T_TILE_PIN6,
	T_TILE_PIN7,
	T_TILE_PIN8,
	T_TILE_PIN9,

	T_TILE_SOU1,
	T_TILE_SOU2,
	T_TILE_SOU3,
	T_TILE_SOU4,
	T_TILE_SOU5,
	T_TILE_SOU5_D,
	T_TILE_SOU6,
	T_TILE_SOU7,
	T_TILE_SOU8,
	T_TILE_SOU9,

	T_TILE_TON,
	T_TILE_NAN,
	T_TILE_SHAA,
	T_TILE_PEI,

	T_TILE_COUNT,
} T_Tile;

extern const char *T_TILE_NOTATION[T_TILE_COUNT];

// returns true if failed and requires a redraw
bool T_tile_draw(SDL_Renderer *sdl_renderer, T_Tile tile, SDL_Point point,
		 int scale);

T_Tile T_mtile_to_ttile(Tile tile);

void T_tiles_init(SDL_Renderer *sdl_renderer);

void T_tiles_destroy(void);

#endif // !T_TILES_H
