#include "l_letter.h"
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdio.h>
#include <string.h>

#define FONT_EDOSZ_TTF "static/edosz.ttf"
#define FONT_ULTRA_REGULAR_TTF "static/Ultra-Regular.ttf"

TTF_Font *font;
TTF_TextEngine *text_engine;
SDL_Color L_COLORS[L_COLOR_COUNT] = {
	{ UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX }, //white
	{ 0, 0, 0, 0 }, //black
	{ 255, 0, 0, 0 }, //red
	{ 0, 255, 0, 0 }, //green
	{ 0, 0, 255, 0 }, //blue
	{ 0, 10, 0, 255 }, //greenish black
	{ 10, 20, 10, 255 } //more greenish black
};

L_Text_Obj L_TEXTS_OBJS[L_TEXT_COUNT] = {
	{ "hold / for help", 40, L_COLOR_WHITE },
	{ "1-9 ", 80, L_COLOR_WHITE },
	{ "shift", 80, L_COLOR_WHITE },
	{ "ctrl", 80, L_COLOR_WHITE },
	{ "E", 80, L_COLOR_WHITE },
	{ "S", 80, L_COLOR_WHITE },
	{ "W", 80, L_COLOR_WHITE },
	{ "N", 80, L_COLOR_WHITE },
	{ "C", 80, L_COLOR_WHITE },
	{ "H", 80, L_COLOR_WHITE },
	{ "G", 80, L_COLOR_WHITE },
	{ "r riichi", 80, L_COLOR_WHITE },
	{ "d double riichi", 80, L_COLOR_WHITE },
	{ "i ippatsu", 80, L_COLOR_WHITE },
	{ "h haitei", 80, L_COLOR_WHITE },
	{ "p chankan", 80, L_COLOR_WHITE },
	{ "k rinshan kaihou", 80, L_COLOR_WHITE },
	{ "space toggle pane", 80, L_COLOR_WHITE },
	{ "Hand", 50, L_COLOR_GREEN },
	{ "Hand", 50, L_COLOR_WHITE },
	{ "Dora", 50, L_COLOR_GREEN },
	{ "Dora", 50, L_COLOR_WHITE },
};
SDL_Texture *text_textures[L_TEXT_COUNT];

void L_init(SDL_Renderer *sdl_renderer)
{
	TTF_Init();
	font = TTF_OpenFont(FONT_EDOSZ_TTF, 100);
	text_engine = TTF_CreateSurfaceTextEngine();

	for (int i = 0; i < L_TEXT_COUNT; i++) {
		TTF_SetFontSize(font, L_TEXTS_OBJS[i].point_size);
		TTF_Text *ttf_text = TTF_CreateText(text_engine, font, L_TEXTS_OBJS[i].text, 0);
		if (!ttf_text) {
			fprintf(stderr, "Failed to create text obj\n");
		}
		SDL_Surface *text_surface = TTF_RenderText_Solid(font, ttf_text->text, 0,
								 L_COLORS[L_TEXTS_OBJS[i].color]);
		if (!text_surface) {
			fprintf(stderr, "Failed to render text surface\n");
			TTF_DestroyText(ttf_text);
		}

		SDL_Texture *tex = SDL_CreateTextureFromSurface(sdl_renderer, text_surface);
		if (!tex) {
			fprintf(stderr, "Failed to create text texture from surface: %s\n",
				SDL_GetError());
			TTF_DestroyText(ttf_text);
			SDL_DestroySurface(text_surface);
		}
		SDL_DestroySurface(text_surface);
		TTF_DestroyText(ttf_text);

		text_textures[i] = tex;
	}
}

int L_draw(SDL_Renderer *sdl_renderer, L_Texts text, SDL_Point point)
{
	SDL_Texture *tex = text_textures[text];
	SDL_FRect rect = { .x = point.x, .y = point.y, .w = tex->w, .h = tex->h };
	if (!SDL_RenderTexture(sdl_renderer, tex, NULL, &rect)) {
		fprintf(stderr, "Failed to render text texture: %s\n", SDL_GetError());
		return 1;
	}
	return 0;
}

void L_destroy(void)
{
	for (int i = 0; i < L_TEXT_COUNT; i++) {
		SDL_DestroyTexture(text_textures[i]);
	}

	TTF_CloseFont(font);
	TTF_DestroySurfaceTextEngine(text_engine);
}
