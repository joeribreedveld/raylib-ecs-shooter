#ifndef GAME_H
#define GAME_H

#include "raylib.h"

struct game {
	Camera2D camera;
	Texture2D player_tex;
	Texture2D bullet_tex;
	int camera_target;
};

struct game *game_init();

void game_loop(struct game *game);

void game_shutdown(struct game *game);

#endif