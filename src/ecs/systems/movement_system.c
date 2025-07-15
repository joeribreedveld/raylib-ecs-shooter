#include "ecs/systems/movement_system.h"
#include "ecs/components/position_component.h"
#include "ecs/components/velocity_component.h"
#include "ecs/entity.h"

#include "raymath.h"

void movement_system(float dt)
{
	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i] || !has_velocity[i]) {
			continue;
		}

		positions[i] = Vector2Add(positions[i],
					  Vector2Scale(velocities[i], dt));
	}
}
