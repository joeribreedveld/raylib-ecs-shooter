#include "actors/bullet.h"

#include "ecs/systems/shooting_system.h"
#include "ecs/components/position_component.h"

#include "raymath.h"

void shooting_system(int player_id, Camera2D camera)
{
	if (IsKeyPressed(KEY_SPACE)) {
		if (!has_position[player_id]) {
			return;
		}

		Vector2 pos = positions[player_id];
		Vector2 mouse_world =
			GetScreenToWorld2D(GetMousePosition(), camera);
		Vector2 dir =
			Vector2Normalize(Vector2Subtract(mouse_world, pos));

		if (Vector2LengthSqr(dir) == 0) {
			return;
		}

		bullet_create(pos, dir, BULLET_SPEED, BULLET_LIFETIME,
			      BULLET_DAMAGE, TEAM_PLAYER);
	}
}
