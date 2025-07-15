#include "actors/player.h"

#include "ecs/components/angle_component.h"
#include "ecs/components/input_component.h"
#include "ecs/components/position_component.h"
#include "ecs/components/speed_component.h"
#include "ecs/components/texture_component.h"
#include "ecs/components/velocity_component.h"
#include "ecs/entity.h"

#include "raymath.h"

int player_create(Vector2 pos, float speed, Texture2D tex)
{
	int p = create_entity();

	positions[p] = pos;
	speeds[p] = speed;
	textures[p] = tex;
	angles[p] = 0.0f;

	velocities[p] = Vector2Zero();

	has_velocity[p] = true;
	has_position[p] = true;
	has_speed[p] = true;
	has_input[p] = true;
	has_texture[p] = true;
	has_angle[p] = true;

	return p;
}