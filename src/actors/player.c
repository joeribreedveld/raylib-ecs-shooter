#include "actors/player.h"

#include "ecs/components.h"
#include "ecs/entity.h"

#include "raymath.h"

int player_create(Vector2 pos, float speed, Texture2D tex)
{
	int id = create_entity();

	positions[id] = pos;
	has_position[id] = true;

	velocities[id] = Vector2Zero();
	has_velocity[id] = true;

	speeds[id] = speed;
	has_speed[id] = true;

	angles[id] = 0.0f;
	has_angle[id] = true;
	has_mouse_angle[id] = true;

	teams[id] = TEAM_PLAYER;
	has_team[id] = true;

	textures[id] = tex;
	has_texture[id] = true;

	custom_origins[id] = (Vector2){ 16.0f, 21.5f };
	has_custom_origin[id] = true;

	layers[id] = LAYER_FOREGROUND;

	has_input[id] = true;
	has_shooting[id] = true;
	has_rounded_drawing[id] = true;
	has_map_clamp[id] = true;

	return id;
}