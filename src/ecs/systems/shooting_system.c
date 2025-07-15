#include "actors/bullet.h"

#include "ecs/systems/shooting_system.h"
#include "ecs/components/position_component.h"

#include "raymath.h"

void shooting_system(int player_id, Camera2D camera, Texture2D bullet_tex)
{
	if (IsKeyPressed(KEY_SPACE)) {
		if (!has_position[player_id]) {
			return;
		}

		Vector2 player_pos = positions[player_id];

		Vector2 mouse_world =
			GetScreenToWorld2D(GetMousePosition(), camera);

		Vector2 dir = Vector2Normalize(
			Vector2Subtract(mouse_world, player_pos));

		float angle = atan2f(dir.y, dir.x) * RAD2DEG + 90.0f;

		if (Vector2LengthSqr(dir) == 0) {
			return;
		}

		Vector2 muzzle_offset = { 10.0f, -14.0f };

		float angle_rad = angle * DEG2RAD;

		Vector2 rotated_offset = {
			muzzle_offset.x * cosf(angle_rad) -
				muzzle_offset.y * sinf(angle_rad),
			muzzle_offset.x * sinf(angle_rad) +
				muzzle_offset.y * cosf(angle_rad)
		};

		Vector2 spawn_pos = Vector2Add(player_pos, rotated_offset);

		bullet_create(spawn_pos, dir, BULLET_SPEED, BULLET_LIFETIME,
			      BULLET_DAMAGE, TEAM_PLAYER, bullet_tex, angle);
	}
}
