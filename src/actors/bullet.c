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

	positions[id] = pos;
	has_position[id] = true;

	float rad = angle * DEG2RAD;

	Vector2 dir = { cosf(rad), sinf(rad) };

	velocities[id] = Vector2Scale(Vector2Normalize(dir), speed);
	has_velocity[id] = true;

	angles[id] = angle;
	has_angle[id] = true;

	teams[id] = bullet_team;
	has_team[id] = true;

	damages[id] = dmg;
	has_damage[id] = true;

	lifetimes[id] = lifetime;
	has_lifetime[id] = true;

	textures[id] = tex;
	has_texture[id] = true;

	sprite_rotation_offsets[id] = 90.0f;
	has_sprite_rotation_offset[id] = true;

	layers[id] = LAYER_BACKGROUND;

	return id;
}
