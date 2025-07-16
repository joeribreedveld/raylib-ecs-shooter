#include "actors/bullet.h"

#include "ecs/components.h"
#include "ecs/entity.h"

#include "raymath.h"

int bullet_create(Vector2 pos, float speed, float lifetime, int dmg,
		  enum team_type bullet_team, Texture2D tex, float angle)
{
	int b = create_entity();

	float rad = angle * DEG2RAD;

	Vector2 dir = { cosf(rad), sinf(rad) };

	velocities[b] = Vector2Scale(Vector2Normalize(dir), speed);

	sprite_rotation_offsets[b] = 90.0f;

	positions[b] = pos;
	teams[b] = bullet_team;
	damages[b] = dmg;
	lifetimes[b] = lifetime;
	textures[b] = tex;
	angles[b] = angle;

	has_velocity[b] = true;
	has_position[b] = true;
	has_damage[b] = true;
	has_lifetime[b] = true;
	has_team[b] = true;
	has_texture[b] = true;
	has_angle[b] = true;
	has_sprite_rotation_offset[b] = true;

	return b;
}