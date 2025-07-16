#include "actors/bullet.h"

#include "ecs/components.h"
#include "ecs/entity.h"

#include "raymath.h"

int bullet_create(Vector2 pos, float speed, float lifetime, int dmg,
		  enum team_type bullet_team, Texture2D tex, float angle)
{
	int id = create_entity();

	if (id == -1) {
		return -1;
	}

	float rad = angle * DEG2RAD;

	Vector2 dir = { cosf(rad), sinf(rad) };

	velocities[id] = Vector2Scale(Vector2Normalize(dir), speed);

	sprite_rotation_offsets[id] = 90.0f;

	layers[id] = LAYER_BACKGROUND;

	positions[id] = pos;
	teams[id] = bullet_team;
	damages[id] = dmg;
	lifetimes[id] = lifetime;
	textures[id] = tex;
	angles[id] = angle;

	has_velocity[id] = true;
	has_position[id] = true;
	has_damage[id] = true;
	has_lifetime[id] = true;
	has_team[id] = true;
	has_texture[id] = true;
	has_angle[id] = true;
	has_sprite_rotation_offset[id] = true;

	return id;
}