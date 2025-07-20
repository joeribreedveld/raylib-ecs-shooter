#include "ecs/systems/movement_system.h"
#include "ecs/components.h"
#include "ecs/entity.h"

#include "raymath.h"

void movement_system(float dt)
{
	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i] || !has_velocity[i]) {
			continue;
		}

		Vector2 min = { 16, 16 };
		Vector2 max = { 1008, 1008 };

		positions[i] = Vector2Clamp(
			Vector2Add(positions[i],
				   Vector2Scale(velocities[i], dt)),
			min, max);
	}
}
