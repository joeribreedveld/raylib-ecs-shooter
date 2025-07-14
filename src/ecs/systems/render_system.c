#include "ecs/systems/render_system.h"
#include "ecs/components/position_component.h"
#include "ecs/entity.h"

#include "config.h"

#include "raylib.h"

void render_system(Camera2D camera)
{
	BeginDrawing();

	ClearBackground(BLACK);

	BeginMode2D(camera);

	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i]) {
			continue;
		}

		DrawRectangle(0, 0, 100, 100, PINK);

		DrawRectangle((int)positions[i].x - (int)SPRITE_DRAW_SIZE / 2,
			      (int)positions[i].y - (int)SPRITE_DRAW_SIZE / 2,
			      (int)SPRITE_DRAW_SIZE, (int)SPRITE_DRAW_SIZE,
			      GREEN);
	}

	EndMode2D();

	EndDrawing();
}