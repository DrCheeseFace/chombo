#include "l_letter.h"
#include "util.h"
#include <SDL3_ttf/SDL_ttf.h>
#include <stdio.h>

#define FONT_EDOSZ_TTF "static/edosz.ttf"

TTF_Font *font;
TTF_TextEngine *text_engine;
SDL_Color L_COLORS[L_COLOR_COUNT] = {
	{ UINT8_MAX, UINT8_MAX, UINT8_MAX, UINT8_MAX }, //white
	{ 0, 0, 0, 0 }, //black
	{ 255, 0, 0, 255 }, //red
	{ 0, 255, 0, 255 }, //green
	{ 0, 0, 255, 0 }, //blue
	{ 255, 255, 0, 255 }, // yellow
	{ 255, 0, 255, 255 }, // magenta
	{ 10, 10, 0, 200 }, //transparentish tinge
	{ 10, 20, 10, 250 }, //more greenish black
};

L_Text_Obj L_TEXTS_OBJS[L_TEXT_COUNT] = {
	{ "hold / for help", 40, L_COLOR_WHITE, 0 },
	{ "0-9 ", 80, L_COLOR_WHITE, 0 },
	{ "shift", 80, L_COLOR_WHITE, 0 },
	{ "ctrl", 80, L_COLOR_WHITE, 0 },
	{ "E", 80, L_COLOR_WHITE, 0 },
	{ "S", 80, L_COLOR_WHITE, 0 },
	{ "W", 80, L_COLOR_WHITE, 0 },
	{ "N", 80, L_COLOR_WHITE, 0 },
	{ "C", 80, L_COLOR_WHITE, 0 },
	{ "H", 80, L_COLOR_WHITE, 0 },
	{ "G", 80, L_COLOR_WHITE, 0 },
	{ "r riichi", 80, L_COLOR_WHITE, 0 },
	{ "d double riichi", 80, L_COLOR_WHITE, 0 },
	{ "i ippatsu", 80, L_COLOR_WHITE, 0 },
	{ "t haitei", 80, L_COLOR_WHITE, 0 },
	{ "m chankan", 80, L_COLOR_WHITE, 0 },
	{ "k rinshan kaihou", 80, L_COLOR_WHITE, 0 },
	{ "space toggle pane", 80, L_COLOR_WHITE, 0 },

	{ "Hand", 50, L_COLOR_GREEN, 0 },
	{ "Hand", 50, L_COLOR_WHITE, 0 },
	{ "Valid", 50, L_COLOR_GREEN, 0 },
	{ "Invalid", 50, L_COLOR_YELLOW, 0 },
	{ "Dora", 50, L_COLOR_GREEN, 0 },
	{ "Dora", 50, L_COLOR_WHITE, 0 },

	{ "Seat wind", 50, L_COLOR_WHITE, 0 },
	{ "Seat wind", 50, L_COLOR_GREEN, 0 },
	{ "Prevelant wind", 50, L_COLOR_WHITE, 0 },
	{ "Prevelant wind", 50, L_COLOR_GREEN, 0 },

	{ "t tsumo", 70, L_COLOR_RED, 0 },
	{ "t tsumo", 70, L_COLOR_GREEN, 0 },
	{ "r riichi", 70, L_COLOR_RED, 0 },
	{ "r riichi", 70, L_COLOR_GREEN, 0 },
	{ "d double riichi", 70, L_COLOR_RED, 0 },
	{ "d double riichi", 70, L_COLOR_GREEN, 0 },
	{ "i ippatsu", 70, L_COLOR_RED, 0 },
	{ "i ippatsu", 70, L_COLOR_GREEN, 0 },
	{ "z haitei", 70, L_COLOR_RED, 0 },
	{ "z haitei", 70, L_COLOR_GREEN, 0 },
	{ "m chankan", 70, L_COLOR_RED, 0 },
	{ "m chankan", 70, L_COLOR_GREEN, 0 },
	{ "k rinshan kaihou", 70, L_COLOR_RED, 0 },
	{ "k rinshan kaihou", 70, L_COLOR_GREEN, 0 },
	{ "u tenhou", 70, L_COLOR_RED, 0 },
	{ "u tenhou", 70, L_COLOR_GREEN, 0 },

	{ "open", 100, L_COLOR_GREEN, 0 },
	{ "closed", 100, L_COLOR_YELLOW, 0 },

	{ "honba", 80, L_COLOR_RED, 0 },
	{ "honba", 80, L_COLOR_GREEN, 0 },
	{ "0", 100, L_COLOR_WHITE, 0 },

	{ "ERROR!", 100, L_COLOR_RED, 0 },
	{ "OK", 100, L_COLOR_WHITE, WINDOW_WIDTH / 5 * 4 },
};

SDL_Texture *text_textures[L_TEXT_COUNT];

void L_init(SDL_Renderer *sdl_renderer)
{
	TTF_Init();
	font = TTF_OpenFont(FONT_EDOSZ_TTF, 100);
	text_engine = TTF_CreateSurfaceTextEngine();
	TTF_SetFontWrapAlignment(font, TTF_HORIZONTAL_ALIGN_CENTER);

	for (int i = 0; i < L_TEXT_COUNT; i++) {
		TTF_SetFontSize(font, L_TEXTS_OBJS[i].point_size);
		TTF_Text *ttf_text = TTF_CreateText(text_engine, font,
						    L_TEXTS_OBJS[i].text, 0);
		if (!ttf_text) {
			fprintf(stderr, "Failed to create text obj\n");
		}

		SDL_Surface *text_surface = TTF_RenderText_Solid_Wrapped(
			font, ttf_text->text, 0,
			L_COLORS[L_TEXTS_OBJS[i].color],
			L_TEXTS_OBJS[i].wraplength);

		if (!text_surface) {
			fprintf(stderr, "Failed to render text surface\n");
			TTF_DestroyText(ttf_text);
		}

		SDL_Texture *tex = SDL_CreateTextureFromSurface(sdl_renderer,
								text_surface);

		if (!tex) {
			fprintf(stderr,
				"Failed to create text texture from surface: %s\n",
				SDL_GetError());
			TTF_DestroyText(ttf_text);
			SDL_DestroySurface(text_surface);
		}
		SDL_DestroySurface(text_surface);
		TTF_DestroyText(ttf_text);

		text_textures[i] = tex;
	}
}

bool L_draw(SDL_Renderer *sdl_renderer, L_Text text, SDL_Point point)
{
	SDL_Texture *tex = text_textures[text];
	SDL_FRect rect = {
		.x = point.x, .y = point.y, .w = tex->w, .h = tex->h
	};
	if (!SDL_RenderTexture(sdl_renderer, tex, NULL, &rect)) {
		fprintf(stderr, "Failed to render text texture: %s\n",
			SDL_GetError());
		return true;
	}
	return false;
}

void L_rewrite_text(SDL_Renderer *sdl_renderer, L_Text text_to_change,
		    char *string_to_replace)
{
	L_TEXTS_OBJS[text_to_change].text = string_to_replace;

	TTF_SetFontSize(font, L_TEXTS_OBJS[text_to_change].point_size);
	TTF_SetFontWrapAlignment(font, TTF_HORIZONTAL_ALIGN_CENTER);

	TTF_Text *ttf_text = TTF_CreateText(
		text_engine, font, L_TEXTS_OBJS[text_to_change].text, 0);
	if (!ttf_text) {
		fprintf(stderr, "Failed to create text obj\n");
	}

	SDL_Surface *text_surface = TTF_RenderText_Solid_Wrapped(
		font, ttf_text->text, 0,
		L_COLORS[L_TEXTS_OBJS[text_to_change].color],
		L_TEXTS_OBJS[text_to_change].wraplength);

	if (!text_surface) {
		fprintf(stderr, "Failed to render text surface\n");
		TTF_DestroyText(ttf_text);
	}

	SDL_Texture *tex =
		SDL_CreateTextureFromSurface(sdl_renderer, text_surface);
	if (!tex) {
		fprintf(stderr,
			"Failed to create text texture from surface: %s\n",
			SDL_GetError());
		TTF_DestroyText(ttf_text);
		SDL_DestroySurface(text_surface);
	}

	if (text_textures[text_to_change] != NULL) {
		SDL_DestroyTexture(text_textures[text_to_change]);
	}

	text_textures[text_to_change] = tex;

	SDL_DestroySurface(text_surface);
	TTF_DestroyText(ttf_text);
}

int L_text_width(L_Text text)
{
	return text_textures[text]->w;
}

int L_text_height(L_Text text)
{
	return text_textures[text]->h;
}

void L_destroy(void)
{
	for (int i = 0; i < L_TEXT_COUNT; i++) {
		SDL_DestroyTexture(text_textures[i]);
	}

	TTF_CloseFont(font);
	TTF_DestroySurfaceTextEngine(text_engine);
}
