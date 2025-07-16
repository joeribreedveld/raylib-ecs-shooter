#include "actors/player.h"

#include "ecs/components.h"
#include "ecs/entity.h"

#include "raymath.h"

int player_create(Vector2 pos, float speed, Texture2D tex)
{
	int p = create_entity();

	positions[p] = pos;
	speeds[p] = speed;
	textures[p] = tex;
	teams[p] = TEAM_PLAYER;
	angles[p] = 0.0f;

	velocities[p] = Vector2Zero();

	has_velocity[p] = true;
	has_position[p] = true;
	has_speed[p] = true;
	has_input[p] = true;
	has_texture[p] = true;
	has_team[p] = true;
	has_shooting[p] = true;
	has_angle[p] = true;
	has_mouse_angle[p] = true;

	return p;
}