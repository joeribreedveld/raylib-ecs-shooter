#include "player.h"
#include "ecs/components.h"
#include "ecs/entity.h"
#include "raymath.h"

void player_create(Vector2 pos, float speed)
{
	int p = create_entity();

	positions[p] = pos;

	has_position[p] = true;

	velocities[p] = Vector2Zero();

	has_velocity[p] = true;

	speeds[p] = speed;

	has_speed[p] = true;

	has_input[p] = true;
}