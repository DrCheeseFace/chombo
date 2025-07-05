#ifndef L_LETTER_H
#define L_LETTER_H

#include <SDL2/SDL.h>

typedef enum {
	L_WHITE = 0,
	L_BLACK,
	L_RED,
	L_GREEN,
	L_BLUE,
	L_BACKDROP,
	L_MENU_BACKDROP,
	L_COUNT
} L_Colors;

extern SDL_Color L_colors[L_COUNT];

void L_init(void);

// returns 0 if successful
int L_draw(SDL_Renderer *sdl_renderer, const char *text, SDL_Color color, SDL_Point rect,
	   int fontsize);

void L_destroy(void);

#endif // !
