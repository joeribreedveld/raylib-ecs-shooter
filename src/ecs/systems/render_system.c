#include "ecs/systems/render_system.h"
#include "ecs/components.h"
#include "ecs/entity.h"

#include "raylib.h"

#include <math.h>

void render_system(Camera2D camera)
{
	BeginDrawing();

	/* TODO: Draw map with grass background from tileset */
	ClearBackground(BLACK);

	BeginMode2D(camera);

	DrawRectangle(0, 0, 100, 100, PINK);

	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i] || !has_angle[i]) {
			continue;
		}

		float rotation = angles[i];

		Rectangle dest = { positions[i].x, positions[i].y,
				   textures[i].width, textures[i].height };

		if (has_sprite_rotation_offset[i]) {
			rotation += sprite_rotation_offsets[i];
		}

		if (has_rounded_drawing[i]) {
			dest.x = (int)roundf(dest.x);
			dest.y = (int)roundf(dest.y);
		}

		DrawTexturePro(textures[i],
			       (Rectangle){ 0, 0, textures[i].width,
					    textures[i].height },
			       dest,
			       (Vector2){ textures[i].width / 2.0f,
					  textures[i].height / 2.0f },
			       rotation, WHITE);
	}

	EndMode2D();

	EndDrawing();
}