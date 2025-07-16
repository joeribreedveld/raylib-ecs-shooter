#include "ecs/systems/render_system.h"
#include "ecs/components.h"
#include "ecs/entity.h"

#include "raylib.h"

void render_system(Camera2D camera, int player_id)
{
	BeginDrawing();

	/* TODO: Draw map with grass background from tileset */
	ClearBackground(BLACK);

	BeginMode2D(camera);

	DrawRectangle(0, 0, 100, 100, PINK);

	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i] || i == player_id || !has_angle[i]) {
			continue;
		}

		float rotation = angles[i] + 90.0f;

		/* TODO: Seperately init arguments */
		DrawTexturePro(textures[i],
			       (Rectangle){ 0, 0, textures[i].width,
					    textures[i].height },
			       (Rectangle){ positions[i].x, positions[i].y,
					    textures[i].width,
					    textures[i].height },
			       (Vector2){ textures[i].width / 2.0f,
					  textures[i].height / 2.0f },
			       rotation, WHITE);
	}

	if (has_position[player_id] && has_texture[player_id]) {
		/* TODO: Seperately init arguments */
		DrawTexturePro(textures[player_id],
			       (Rectangle){ 0, 0, textures[player_id].width,
					    textures[player_id].height },
			       (Rectangle){ (int)positions[player_id].x,
					    (int)positions[player_id].y,
					    textures[player_id].width,
					    textures[player_id].height },
			       (Vector2){ textures[player_id].width / 2.0f,
					  textures[player_id].height / 2.0f },
			       angles[player_id], WHITE);
	}

	EndMode2D();

	EndDrawing();
}