#ifndef T_TILES_H
#define T_TILES_H

#include <SDL3/SDL.h>

extern const char *T_TILE_PATHS[];

typedef enum {
	T_BACK = 0,
	T_BLANK,
	T_FRONT,
	T_CHUN,
	T_HAKU,
	T_HATSU,

	T_MAN1,
	T_MAN2,
	T_MAN3,
	T_MAN4,
	T_MAN5_D,
	T_MAN5,
	T_MAN6,
	T_MAN7,
	T_MAN8,
	T_MAN9,

	T_PIN1,
	T_PIN2,
	T_PIN3,
	T_PIN4,
	T_PIN5_D,
	T_PIN5,
	T_PIN6,
	T_PIN7,
	T_PIN8,
	T_PIN9,

	T_SOU1,
	T_SOU2,
	T_SOU3,
	T_SOU4,
	T_SOU5_D,
	T_SOU5,
	T_SOU6,
	T_SOU7,
	T_SOU8,
	T_SOU9,

	T_TON,
	T_NAN,
	T_PEI,
	T_SHAA,
	T_COUNT,
} T_Tile;

// returns 0 if successful
int T_tile_draw(SDL_Renderer *sdl_renderer, T_Tile tile, SDL_Point *point, int scale);

void T_tiles_init(SDL_Renderer *sdl_renderer);

void T_tiles_destroy(void);

#endif // !T_TILES_H
