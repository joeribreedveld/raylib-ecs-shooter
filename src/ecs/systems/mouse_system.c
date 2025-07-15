#include "ecs/components/angle_component.h"
#include "ecs/components/mouse_angle_component.h"
#include "ecs/components/position_component.h"
#include "ecs/entity.h"

#include "raymath.h"

void mouse_system(Camera2D camera)
{
	for (int i = 0; i < next_entity; i++) {
		if (!has_angle[i] || !has_mouse_angle[i]) {
			continue;
		}

		Vector2 mouse_world =
			GetScreenToWorld2D(GetMousePosition(), camera);

		Vector2 pos = positions[i];

		Vector2 dir = Vector2Subtract(mouse_world, pos);

		float angle = atan2f(dir.y, dir.x) * RAD2DEG;

		angles[i] = angle;
	}
}