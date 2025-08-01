#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

#include "ecs/components.h"

int bullet_create(Vector2 pos, float speed, float lifetime, int dmg,
		  enum team_type bullet_team, Texture2D tex, float angle);

#endif