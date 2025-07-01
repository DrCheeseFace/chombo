#include "r_renderer.h"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <stdlib.h>
#include <string.h>

SDL_Texture *sdl_texture_frame_buffer;
SDL_Renderer *sdl_renderer;
Uint32 *pixel_buffer;
SDL_PixelFormat *pixel_format;
int screen_width, screen_height;

SDL_Renderer *R_create(SDL_Window *window, int width, int height)
{
	sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
	SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl_renderer);
	sdl_texture_frame_buffer = SDL_CreateTexture(sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
						     SDL_TEXTUREACCESS_STREAMING, width, height);

	pixel_format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

	pixel_buffer = (Uint32 *)malloc(width * height * sizeof(Uint32));
	memset(pixel_buffer, 0, width * height * sizeof(Uint32));

	screen_width = width;
	screen_height = height;

	return sdl_renderer;
}

void R_destroy(SDL_Renderer *sdl_renderer)
{
	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyTexture(sdl_texture_frame_buffer);
	SDL_FreeFormat(pixel_format);
}

void R_some_black_magic_altering_to_pixel_buffer(void)
{
	Uint32 blue_colour = SDL_MapRGBA(pixel_format, 40, 30, 100, 255);
	for (int i = 0; i < screen_width * screen_height; ++i) {
		pixel_buffer[i] = blue_colour;
	}
}

void R_draw(SDL_Renderer *sdl_renderer)
{
	SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl_renderer);

	R_some_black_magic_altering_to_pixel_buffer();

	SDL_UpdateTexture(sdl_texture_frame_buffer, NULL, pixel_buffer,
			  screen_width * sizeof(Uint32));
	SDL_RenderCopy(sdl_renderer, sdl_texture_frame_buffer, NULL, NULL);
	SDL_RenderPresent(sdl_renderer);
}
