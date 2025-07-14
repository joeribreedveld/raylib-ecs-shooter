
#include "ecs/components/input_component.h"
#include "ecs/components/speed_component.h"
#include "ecs/components/velocity_component.h"
#include "ecs/entity.h"

#include "raymath.h"

void input_system()
{
	for (int i = 0; i < next_entity; i++) {
		if (!has_velocity[i] || !has_input[i] || !has_speed[i]) {
			continue;
		}

		Vector2 dir = Vector2Zero();

		if (IsKeyDown(KEY_W)) {
			dir.y -= 1;
		}

		if (IsKeyDown(KEY_A)) {
			dir.x -= 1;
		}

		if (IsKeyDown(KEY_S)) {
			dir.y += 1;
		}

		if (IsKeyDown(KEY_D)) {
			dir.x += 1;
		}

		if (dir.x != 0 && dir.y != 0) {
			dir = Vector2Normalize(dir);
		}

		velocities[i] = Vector2Scale(dir, speeds[i]);
	}
}