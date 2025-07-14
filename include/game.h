#ifndef GAME_H
#define GAME_H

#include "raylib.h"

struct game {
	int player_id;
	Camera2D camera;
};

struct game *game_init();

void game_loop(struct game *game);

void game_shutdown(struct game *game);

#endif