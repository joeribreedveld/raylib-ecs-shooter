#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

#include "ecs/components/team_component.h"

int bullet_create(Vector2 pos, Vector2 dir, float speed, float lifetime,
		  int dmg, enum team_type bullet_team);

#endif