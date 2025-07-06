#include "l_letter.h"
#include <SDL3_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string.h>

#define FONT_EDOSZ_TTF "static/edosz.ttf"
#define FONT_ULTRA_REGULAR_TTF "static/Ultra-Regular.ttf"

TTF_Font *font;
TTF_TextEngine *text_engine;
SDL_Color L_colors[L_COUNT] = {
	{ UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX }, //white
	{ 0, 0, 0, 0 }, //black
	{ 255, 0, 0, 0 }, //red
	{ 0, 255, 0, 0 }, //green
	{ 0, 0, 255, 0 }, //blue
	{ 0, 10, 0, 255 }, //greenish black
	{ 10, 20, 10, 255 } //more greenish black
};

void L_init(void)
{
	TTF_Init();
	font = TTF_OpenFont(FONT_EDOSZ_TTF, 100);
	text_engine = TTF_CreateSurfaceTextEngine();
}

int L_draw(SDL_Renderer *sdl_renderer, const char *text, SDL_Color color, SDL_Point point,
	   int fontsize)
{
	TTF_SetFontSize(font, fontsize);
	TTF_Text *ttf_text = TTF_CreateText(text_engine, font, text, 0);
	if (ttf_text == NULL) {
		fprintf(stderr, "Failed to create text obj\n");
		return 1;
	}
	SDL_Surface *text_surface = TTF_RenderText_Solid(font, ttf_text->text, 0, color);
	if (text_surface == NULL) {
		fprintf(stderr, "Failed to render text surface\n");
		TTF_DestroyText(ttf_text);
		return 1;
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(sdl_renderer, text_surface);
	if (tex == NULL) {
		fprintf(stderr, "Failed to create text texture from surface: %s\n", SDL_GetError());
		TTF_DestroyText(ttf_text);
		SDL_DestroySurface(text_surface);
		return 1;
	}

	SDL_FRect rect = { .x = point.x, .y = point.y, .w = text_surface->w, .h = text_surface->h };

	if (!SDL_RenderTexture(sdl_renderer, tex, NULL, &rect)) {
		fprintf(stderr, "Failed to render copy: %s\n", SDL_GetError());
		TTF_DestroyText(ttf_text);
		SDL_DestroySurface(text_surface);
		SDL_DestroyTexture(tex);
		return 1;
	}

	TTF_DestroyText(ttf_text);
	SDL_DestroySurface(text_surface);
	SDL_DestroyTexture(tex);
	return 0;
}

void L_destroy(void)
{
	TTF_CloseFont(font);
	TTF_DestroySurfaceTextEngine(text_engine);
}
