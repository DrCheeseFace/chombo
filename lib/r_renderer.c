#include "r_renderer.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

SDL_Texture *sdl_texture_frame_buffer;
SDL_Renderer *sdl_renderer;
Uint32 *pixel_buffer;
int screen_width, screen_height;

SDL_Renderer *R_create(SDL_Window *window, int width, int height)
{
	sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
	SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
	SDL_RenderClear(sdl_renderer);
	sdl_texture_frame_buffer = SDL_CreateTexture(sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
						     SDL_TEXTUREACCESS_STREAMING, width, height);

	pixel_buffer = (Uint32 *)malloc(width * height * sizeof(Uint32));

	screen_width = width;
	screen_height = height;

	return sdl_renderer;
}

void R_destroy(SDL_Renderer *sdl_renderer)
{
	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyTexture(sdl_texture_frame_buffer);
}

void R_some_black_magic_altering_to_pixel_buffer(void)
{
	for (int i = 0; i < screen_width * screen_height; ++i) {
		pixel_buffer[i] = pixel_buffer[i] + 100;
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
