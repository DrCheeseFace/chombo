#include "l_letter.h"
#include "r_renderer.h"
#include "util.h"
#include <SDL3_ttf/SDL_ttf.h>
#include <stdio.h>

#define FONT_EDOSZ_TTF "assets/edosz.ttf"

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
	{ "hold / for help", 40, L_COLOR_WHITE, 0,
	  TTF_HORIZONTAL_ALIGN_CENTER },
	{ "0-9 ", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "shift", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "ctrl", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "E", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "S", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "W", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "N", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "C", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "H", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "G", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "- arrow keys\n  navigate menu", 80, L_COLOR_WHITE, 0,
	  TTF_HORIZONTAL_ALIGN_LEFT },
	{ "- space toggle pane", 80, L_COLOR_WHITE, 0,
	  TTF_HORIZONTAL_ALIGN_CENTER },
	{ "- escape backtrack", 80, L_COLOR_WHITE, 0,
	  TTF_HORIZONTAL_ALIGN_CENTER },
	{ "- enter continue", 80, L_COLOR_WHITE, 0,
	  TTF_HORIZONTAL_ALIGN_CENTER },
	{ "- , clear state", 80, L_COLOR_WHITE, 0,
	  TTF_HORIZONTAL_ALIGN_CENTER },

	{ "Hand", 50, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Hand", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Valid", 50, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Invalid", 50, L_COLOR_YELLOW, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Dora", 50, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Dora", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },

	{ "Seat wind", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Seat wind", 50, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Prevelant wind", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Prevelant wind", 50, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },

	{ "t tsumo", 70, L_COLOR_RED, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "t tsumo", 70, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "r riichi", 70, L_COLOR_RED, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "r riichi", 70, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "d double riichi", 70, L_COLOR_RED, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "d double riichi", 70, L_COLOR_GREEN, 0,
	  TTF_HORIZONTAL_ALIGN_CENTER },
	{ "i ippatsu", 70, L_COLOR_RED, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "i ippatsu", 70, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "z haitei", 70, L_COLOR_RED, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "z haitei", 70, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "m chankan", 70, L_COLOR_RED, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "m chankan", 70, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "k rinshan kaihou", 70, L_COLOR_RED, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "k rinshan kaihou", 70, L_COLOR_GREEN, 0,
	  TTF_HORIZONTAL_ALIGN_CENTER },
	{ "u tenhou", 70, L_COLOR_RED, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "u tenhou", 70, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },

	{ "open", 100, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "closed", 100, L_COLOR_YELLOW, 0, TTF_HORIZONTAL_ALIGN_CENTER },

	{ "honba", 80, L_COLOR_RED, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "honba", 80, L_COLOR_GREEN, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "0", 100, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },

	{ "ERROR!", 100, L_COLOR_RED, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "OK", 100, L_COLOR_WHITE, WINDOW_WIDTH / 5 * 4,
	  TTF_HORIZONTAL_ALIGN_CENTER },

	{ "Yaku", 100, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Yakuman", 100, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Fu", 100, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },

	{ "Han - ", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "0", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "/Fu - ", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "0", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Honba - ", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "0", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Dora - ", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "0", 50, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },

	{ "Dealer ron", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Dealer tsumo", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Non Dealer ron", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
	{ "Non Dealer tsumo", 80, L_COLOR_WHITE, 0,
	  TTF_HORIZONTAL_ALIGN_CENTER },

	{ "0", 80, L_COLOR_WHITE, 0, TTF_HORIZONTAL_ALIGN_CENTER },
};

SDL_Texture *text_textures[L_TEXT_COUNT];

void L_init(SDL_Renderer *sdl_renderer)
{
	TTF_Init();
	font = TTF_OpenFont(FONT_EDOSZ_TTF, 100);
	text_engine = TTF_CreateSurfaceTextEngine();

	for (int i = 0; i < L_TEXT_COUNT; i++) {
		TTF_SetFontSize(font, L_TEXTS_OBJS[i].point_size);
		TTF_SetFontWrapAlignment(font, L_TEXTS_OBJS[i].align);
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

bool L_draw_text(L_Text text, SDL_Point point)
{
	SDL_Texture *tex = text_textures[text];
	if (R_draw(tex, point)) {
		return true;
	}
	return false;
}

void L_rewrite_text(SDL_Renderer *sdl_renderer, L_Text text_to_change,
		    char *string_to_replace)
{
	L_TEXTS_OBJS[text_to_change].text = string_to_replace;

	TTF_SetFontSize(font, L_TEXTS_OBJS[text_to_change].point_size);
	TTF_SetFontWrapAlignment(font, L_TEXTS_OBJS[text_to_change].align);

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

SDL_Texture *L_texture_from_text_obj(SDL_Renderer *sdl_renderer,
				     L_Text_Obj text_obj)
{
	TTF_SetFontSize(font, text_obj.point_size);
	TTF_SetFontWrapAlignment(font, text_obj.align);

	TTF_Text *ttf_text =
		TTF_CreateText(text_engine, font, text_obj.text, 0);
	if (!ttf_text) {
		fprintf(stderr, "Failed to create text obj\n");
		return NULL;
	}

	SDL_Surface *text_surface =
		TTF_RenderText_Solid_Wrapped(font, ttf_text->text, 0,
					     L_COLORS[text_obj.color],
					     text_obj.wraplength);
	if (!text_surface) {
		fprintf(stderr, "Failed to render text surface\n");
		TTF_DestroyText(ttf_text);
		return NULL;
	}

	SDL_Texture *tex =
		SDL_CreateTextureFromSurface(sdl_renderer, text_surface);
	if (!tex) {
		fprintf(stderr,
			"Failed to create text texture from surface: %s\n",
			SDL_GetError());
		TTF_DestroyText(ttf_text);
		SDL_DestroySurface(text_surface);
		return NULL;
	}

	SDL_DestroySurface(text_surface);
	TTF_DestroyText(ttf_text);

	return tex;
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
