#include "ecs/components/damage_component.h"
#include "ecs/components/input_component.h"
#include "ecs/components/lifetime_component.h"
#include "ecs/components/position_component.h"
#include "ecs/components/speed_component.h"
#include "ecs/components/team_component.h"
#include "ecs/components/velocity_component.h"
#include "ecs/entity.h"

int next_entity = 0;

int create_entity()
{
	return next_entity++;
}

/* TODO: Free flag and reuse entity spots */
void destroy_entity(int id)
{
	has_position[id] = false;
	has_velocity[id] = false;
	has_input[id] = false;
	has_speed[id] = false;
	has_lifetime[id] = false;
	has_damage[id] = false;
	has_team[id] = false;

	positions[id] = (Vector2){ 0.0f, 0.0f };
	velocities[id] = (Vector2){ 0.0f, 0.0f };
	speeds[id] = 0.0f;
	lifetimes[id] = 0.0f;
	teams[id] = TEAM_NONE;
	damages[id] = 0;
}

void reset_entities()
{
	next_entity = 0;
}