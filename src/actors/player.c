#include "actors/player.h"

#include "ecs/components.h"
#include "ecs/entity.h"

#include "raymath.h"

int player_create(Vector2 pos, float speed, Texture2D tex)
{
	int id = create_entity();

	positions[id] = pos;
	speeds[id] = speed;
	textures[id] = tex;
	layers[id] = LAYER_FOREGROUND;

	angles[id] = 0.0f;

	teams[id] = TEAM_PLAYER;

	velocities[id] = Vector2Zero();

	custom_origins[id] = (Vector2){ 16.0f, 21.5f };

	has_velocity[id] = true;
	has_position[id] = true;
	has_speed[id] = true;
	has_input[id] = true;
	has_texture[id] = true;
	has_rounded_drawing[id] = true;
	has_team[id] = true;
	has_shooting[id] = true;
	has_angle[id] = true;
	has_mouse_angle[id] = true;
	has_custom_origin[id] = true;

	return id;
}