#include "actors/bullet.h"

#include "ecs/components/angle_component.h"
#include "ecs/components/damage_component.h"
#include "ecs/components/lifetime_component.h"
#include "ecs/components/position_component.h"
#include "ecs/components/team_component.h"
#include "ecs/components/texture_component.h"
#include "ecs/components/velocity_component.h"
#include "ecs/entity.h"

#include "raymath.h"

int bullet_create(Vector2 pos, float speed, float lifetime, int dmg,
		  enum team_type bullet_team, Texture2D tex, float angle)
{
	int b = create_entity();

	float rad = angle * DEG2RAD;

	Vector2 dir = { cosf(rad), sinf(rad) };

	velocities[b] = Vector2Scale(Vector2Normalize(dir), speed);

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

	return b;
}