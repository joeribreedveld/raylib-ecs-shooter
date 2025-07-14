#ifndef CONFIG_H
#define CONFIG_H

#include "raylib.h"

#define SPRITE_SIZE 64
#define SPRITE_SCALE 0.25f
#define SPRITE_DRAW_SIZE (SPRITE_SIZE * SPRITE_SCALE)

#define MAX_ENTITIES 1024

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#define PLAYER_SPEED 200.0f

static inline Vector2 screen_center(void)
{
	return (Vector2){ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
}

#endif