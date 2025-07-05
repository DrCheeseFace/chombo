#include "g_gamestate.h"
#include "t_tiles.h"
#include "l_letter.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

SDL_Renderer *sdl_renderer;
int screen_width, screen_height;

SDL_Renderer *R_create(SDL_Window *window, int width, int height)
{
	sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
	SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl_renderer);

	screen_width = width;
	screen_height = height;

	return sdl_renderer;
}

void R_destroy(SDL_Renderer *sdl_renderer)
{
	SDL_DestroyRenderer(sdl_renderer);
}

int R_draw_help(void)
{
	SDL_FRect help_outline = {
		.w = screen_width - 50, .h = screen_height - 50, .x = 25, .y = 25
	};
	if (SDL_SetRenderDrawColor(sdl_renderer, L_colors[L_WHITE].r, L_colors[L_WHITE].g,
				   L_colors[L_WHITE].b, L_colors[L_WHITE].a) != 0)
		return 1;

	if (SDL_RenderFillRectF(sdl_renderer, &help_outline) != 0)
		return 1;
	if (SDL_SetRenderDrawColor(sdl_renderer, L_colors[L_MENU_BACKDROP].r,
				   L_colors[L_MENU_BACKDROP].g, L_colors[L_MENU_BACKDROP].b,
				   L_colors[L_MENU_BACKDROP].a) != 0) {
		return 1;
	}

	SDL_FRect help_background = {
		.w = screen_width - 55, .h = screen_height - 55, .x = 27.5, .y = 27.5
	};
	if (SDL_RenderFillRectF(sdl_renderer, &help_background) != 0)
		return 1;

	if (L_draw(sdl_renderer, "1-9 ", L_colors[L_WHITE], (struct SDL_Point){ 80, 140 }, 80) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_MAN1, &(struct SDL_Point){ 280, 150 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, "shift", L_colors[L_WHITE], (struct SDL_Point){ 80, 240 }, 80) !=
	    0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_PIN1, &(struct SDL_Point){ 280, 250 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, "ctrl", L_colors[L_WHITE], (struct SDL_Point){ 80, 340 }, 80) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_SOU1, &(struct SDL_Point){ 280, 350 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, "E", L_colors[L_WHITE], (struct SDL_Point){ 80, 440 }, 80) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_TON, &(struct SDL_Point){ 280, 450 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, "S", L_colors[L_WHITE], (struct SDL_Point){ 80, 540 }, 80) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_NAN, &(struct SDL_Point){ 280, 550 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, "W", L_colors[L_WHITE], (struct SDL_Point){ 80, 640 }, 80) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_SHAA, &(struct SDL_Point){ 280, 650 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, "N", L_colors[L_WHITE], (struct SDL_Point){ 80, 740 }, 80) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_PEI, &(struct SDL_Point){ 280, 750 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, "C", L_colors[L_WHITE], (struct SDL_Point){ 420, 140 }, 80) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_CHUN, &(struct SDL_Point){ 500, 150 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, "H", L_colors[L_WHITE], (struct SDL_Point){ 420, 240 }, 80) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_HAKU, &(struct SDL_Point){ 500, 250 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, "G", L_colors[L_WHITE], (struct SDL_Point){ 420, 340 }, 80) != 0)
		return 1;
	if (T_tile_draw(sdl_renderer, T_HATSU, &(struct SDL_Point){ 500, 350 }, 16) != 0)
		return 1;

	if (L_draw(sdl_renderer, "r riichi", L_colors[L_WHITE], (struct SDL_Point){ 760, 140 },
		   80) != 0)
		return 1;
	if (L_draw(sdl_renderer, "d double riichi", L_colors[L_WHITE],
		   (struct SDL_Point){ 760, 240 }, 80) != 0)
		return 1;
	if (L_draw(sdl_renderer, "i ippatsu", L_colors[L_WHITE], (struct SDL_Point){ 760, 340 },
		   80) != 0)
		return 1;
	if (L_draw(sdl_renderer, "h haitei", L_colors[L_WHITE], (struct SDL_Point){ 760, 440 },
		   80) != 0)
		return 1;
	if (L_draw(sdl_renderer, "p chankan", L_colors[L_WHITE], (struct SDL_Point){ 760, 540 },
		   80) != 0)
		return 1;
	if (L_draw(sdl_renderer, "k rinshan kaihou", L_colors[L_WHITE],
		   (struct SDL_Point){ 760, 640 }, 80) != 0)
		return 1;
	if (L_draw(sdl_renderer, "space toggle pane", L_colors[L_WHITE],
		   (struct SDL_Point){ 760, 740 }, 80) != 0)
		return 1;

	return 0;
}

int R_gamestate_draw(SDL_Renderer *sdl_renderer, G_GameState gamestate)
{
	if (SDL_SetRenderDrawColor(sdl_renderer, L_colors[L_BACKDROP].r, L_colors[L_BACKDROP].g,
				   L_colors[L_BACKDROP].b, L_colors[L_BACKDROP].a) != 0) {
		fprintf(stderr, "Failed to set render draw color: %s\n", SDL_GetError());
		return 1;
	}

	if (SDL_RenderClear(sdl_renderer) != 0) {
		fprintf(stderr, "Failed to clear renderer: %s\n", SDL_GetError());
		return 1;
	}

	if (gamestate.show_help) {
		if (R_draw_help() != 0) {
			return 1;
		}
	} else {
		if (L_draw(sdl_renderer, "hold ? for help", L_colors[L_WHITE],
			   (struct SDL_Point){ 4, screen_height - 50 }, 40) != 0)
			return 1;
	}

	SDL_RenderPresent(sdl_renderer);
	return 0;
}
