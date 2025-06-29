#include "lib/w_window.h"
#include "lib/r_renderer.h"

int main(void) {
	W_init(100, 100);
	SDL_Window *sdl_window = W_get();
	R_init(sdl_window);
	R_sanity_check();
	R_destroy();
	W_destroy();
	return 0;
}
