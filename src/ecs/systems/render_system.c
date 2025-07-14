#include "ecs/systems/render_system.h"
#include "ecs/components/position_component.h"
#include "ecs/entity.h"

#include "config.h"

#include "raylib.h"

void render_system()
{
	BeginDrawing();

	ClearBackground(BLACK);

	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i]) {
			continue;
		}

		/* NOTE: This doesn't draw over center */
		DrawRectangle((int)positions[i].x, (int)positions[i].y,
			      (int)SPRITE_DRAW_SIZE, (int)SPRITE_DRAW_SIZE,
			      WHITE);
	}

	EndDrawing();
}