#ifndef L_LETTER_H
#define L_LETTER_H

#include <SDL3/SDL.h>

typedef enum {
	L_COLOR_WHITE = 0,
	L_COLOR_BLACK,
	L_COLOR_RED,
	L_COLOR_GREEN,
	L_COLOR_BLUE,
	L_COLOR_BACKDROP,
	L_COLOR_MENU_BACKDROP,
	L_COLOR_COUNT
} L_Colors;
extern SDL_Color L_COLORS[L_COLOR_COUNT];

typedef struct {
	const char *text;
	int point_size;
	L_Colors color;
} L_Text_Obj;

typedef enum {
	L_TEXT_BOTTOM_HELP,
	L_TEXT_HELP_1_9,
	L_TEXT_HELP_SHIFT,
	L_TEXT_HELP_CTRL,
	L_TEXT_HELP_E,
	L_TEXT_HELP_S,
	L_TEXT_HELP_W,
	L_TEXT_HELP_N,
	L_TEXT_HELP_C,
	L_TEXT_HELP_H,
	L_TEXT_HELP_G,
	L_TEXT_HELP_RIICHI,
	L_TEXT_HELP_DOUBLE_RIICHI,
	L_TEXT_HELP_IPPATSU,
	L_TEXT_HELP_HAITEI,
	L_TEXT_HELP_CHANKAN,
	L_TEXT_HELP_RINSHAN,
	L_TEXT_HELP_SPACE_TOGGLE,
	L_TEXT_COUNT,
} L_Texts;

void L_init(SDL_Renderer *sdl_renderer);

// returns 0 if successful
int L_draw(SDL_Renderer *sdl_renderer, L_Texts text, SDL_Point point);

void L_destroy(void);

#endif // !
