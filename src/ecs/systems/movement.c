#include "movement.h"
#include "ecs/components.h"
#include "ecs/entity.h"
#include "config.h"
#include "raymath.h"

void movement_system(float dt, int screen_width, int screen_height)
{
	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i] || !has_velocity[i]) {
			continue;
		}

		positions[i] = Vector2Add(positions[i],
					  Vector2Scale(velocities[i], dt));
	}
}
