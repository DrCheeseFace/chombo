#ifndef G_GAMESTATE_H
#define G_GAMESTATE_H
#include <stdint.h>

typedef struct {
	int window_w;
	int window_h;
	double target_fps;
	double target_frametime_ms;
} G_GameState;

G_GameState *G_gamestate_create(int target_fps, int window_width, int window_height);

void G_frame_start(void);
void G_frame_end(G_GameState *gamestate);
void G_destroy(G_GameState *gamestate);

#endif // !G_GAMESTATE_H
