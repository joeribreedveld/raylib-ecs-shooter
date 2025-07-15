#include "actors/bullet.h"

#include "ecs/components/damage_component.h"
#include "ecs/components/lifetime_component.h"
#include "ecs/components/position_component.h"
#include "ecs/components/team_component.h"
#include "ecs/components/velocity_component.h"
#include "ecs/entity.h"

#include "raymath.h"

int bullet_create(Vector2 pos, Vector2 dir, float speed, float lifetime,
		  int dmg, enum team_type bullet_team)
{
	int b = create_entity();

	velocities[b] = Vector2Scale(Vector2Normalize(dir), speed);

	positions[b] = pos;
	teams[b] = bullet_team;
	damages[b] = dmg;
	lifetimes[b] = lifetime;

	has_velocity[b] = true;
	has_position[b] = true;
	has_damage[b] = true;
	has_lifetime[b] = true;
	has_team[b] = true;

	return b;
}