#include "ecs/components.h"
#include "ecs/entity.h"

int next_entity = 0;

int free_list[MAX_ENTITIES];
int free_list_top = -1;

int create_entity()
{
	if (free_list_top >= 0) {
		return free_list[free_list_top--];
	}

	if (next_entity >= MAX_ENTITIES) {
		return -1;
	}

	return next_entity++;
}

void clear_entity(int id)
{
	positions[id] = (Vector2){ 0 };
	has_position[id] = false;

	velocities[id] = (Vector2){ 0 };
	has_velocity[id] = false;

	custom_origins[id] = (Vector2){ 0 };
	has_custom_origin[id] = false;

	textures[id] = (Texture2D){ 0 };
	has_texture[id] = false;

	angles[id] = 0.0f;
	has_angle[id] = false;

	speeds[id] = 0.0f;
	has_speed[id] = false;

	lifetimes[id] = 0.0f;
	has_lifetime[id] = false;

	sprite_rotation_offsets[id] = 0.0f;
	has_sprite_rotation_offset[id] = false;

	damages[id] = 0;
	has_damage[id] = false;

	teams[id] = TEAM_NONE;
	has_team[id] = false;

	has_input[id] = false;
	has_mouse_angle[id] = false;
	has_shooting[id] = false;
	has_rounded_drawing[id] = false;
}

void destroy_entity(int id)
{
	clear_entity(id);

	free_list[++free_list_top] = id;
}
