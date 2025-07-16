#include "actors/bullet.h"

#include "ecs/systems/shooting_system.h"
#include "ecs/components/angle_component.h"
#include "ecs/components/mouse_angle_component.h"
#include "ecs/components/position_component.h"
#include "ecs/components/shooting_component.h"
#include "ecs/components/team_component.h"
#include "ecs/entity.h"

#include "raymath.h"

void shooting_system(Camera2D camera, Texture2D bullet_tex)
{
	for (int i = 0; i < next_entity; i++) {
		if (!has_shooting[i] || !has_team[i] || !has_angle[i] ||
		    !has_mouse_angle[i]) {
			continue;
		}

		if (!IsKeyPressed(KEY_SPACE)) {
			continue;
		}

		Vector2 muzzle_offset = { 14.0f, 10.0f };

		float rad = angles[i] * DEG2RAD;

		Vector2 rotated_offset = { muzzle_offset.x * cosf(rad) -
						   muzzle_offset.y * sinf(rad),
					   muzzle_offset.x * sinf(rad) +
						   muzzle_offset.y *
							   cosf(rad) };

		Vector2 spawn_pos = Vector2Add(positions[i], rotated_offset);

		bullet_create(spawn_pos, BULLET_SPEED, BULLET_LIFETIME,
			      BULLET_DAMAGE, teams[i], bullet_tex, angles[i]);
	}
}
