#include "l_letter.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_ttf.h>
#include <string.h>

#define FONT_EDOSZ_TTF "static/edosz.ttf"
#define FONT_ULTRA_REGULAR_TTF "static/Ultra-Regular.ttf"

TTF_Font *font;
SDL_Color L_colors[L_COUNT] = {
	{ UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX }, //white
	{ 0, 0, 0, 0 }, //black
	{ 255, 0, 0, 0 }, //red
	{ 0, 255, 0, 0 }, //green
	{ 0, 0, 255, 0 } //blue
};

void L_init(void)
{
	TTF_Init();
	font = TTF_OpenFont(FONT_EDOSZ_TTF, 100);
}

int L_draw(SDL_Renderer *sdl_renderer, const char *text, SDL_Color color, SDL_Point point,
	   int fontsize)
{
	TTF_SetFontSize(font, fontsize);
	SDL_Rect rect = { .x = point.x, .y = point.y };
	TTF_SizeText(font, text, &rect.w, &rect.h);
	SDL_Surface *text_surface = TTF_RenderText_Solid(font, text, color);
	if (!text_surface) {
		fprintf(stderr, "Failed to render text surface\n");
		return 1;
	}
	SDL_Texture *tex = SDL_CreateTextureFromSurface(sdl_renderer, text_surface);
	if (!tex) {
		fprintf(stderr, "Failed to create text texture from surface: %s\n", SDL_GetError());
		return 1;
	}

	int e = SDL_RenderCopy(sdl_renderer, tex, NULL, &rect);
	if (e < 0) {
		fprintf(stderr, "Failed to render copy: %s\n", SDL_GetError());
		return 1;
	}

	SDL_FreeSurface(text_surface);
	SDL_DestroyTexture(tex);
	return 0;
}

void L_destroy(void)
{
	TTF_CloseFont(font);
}
