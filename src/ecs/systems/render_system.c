#include "ecs/systems/render_system.h"
#include "ecs/components/angle_component.h"
#include "ecs/components/position_component.h"
#include "ecs/components/texture_component.h"
#include "ecs/entity.h"

#include "raylib.h"
#include "raymath.h"

#include <math.h>

void render_system(Camera2D camera, int player_id)
{
	BeginDrawing();

	ClearBackground(BLACK);

	BeginMode2D(camera);

	DrawRectangle(0, 0, 100, 100, PINK);

	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i] || i == player_id || !has_angle[i]) {
			continue;
		}

		DrawTexturePro(textures[i],
			       (Rectangle){ 0, 0, textures[i].width,
					    textures[i].height },
			       (Rectangle){ positions[i].x, positions[i].y,
					    textures[i].width,
					    textures[i].height },
			       (Vector2){ textures[i].width / 2.0f,
					  textures[i].height / 2.0f },
			       angles[i], WHITE);
	}

	if (has_position[player_id] && has_texture[player_id]) {
		/* TODO: Abstract into angle component and add to player */
		Vector2 mouse_world =
			GetScreenToWorld2D(GetMousePosition(), camera);

		Vector2 player_pos = positions[player_id];

		Vector2 dir = Vector2Subtract(mouse_world, player_pos);

		float angle = atan2f(dir.y, dir.x) * RAD2DEG;

		DrawTexturePro(textures[player_id],
			       (Rectangle){ 0, 0, textures[player_id].width,
					    textures[player_id].height },
			       (Rectangle){ (int)positions[player_id].x,
					    (int)positions[player_id].y,
					    textures[player_id].width,
					    textures[player_id].height },
			       (Vector2){ textures[player_id].width / 2.0f,
					  textures[player_id].height / 2.0f },
			       angle, WHITE);
	}

	EndMode2D();

	EndDrawing();
}