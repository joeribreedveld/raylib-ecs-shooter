#include "ecs/systems/render_system.h"
#include "ecs/components.h"
#include "utils/render_layer.h"

#include "raylib.h"

/* #include "map.h" */

void render_system(Camera2D camera)
{
	BeginDrawing();

	ClearBackground(BLACK);

	BeginMode2D(camera);

	// map_draw();

	DrawRectangle(0, 0, 100, 100, PINK);

	render_layer(LAYER_NONE);
	render_layer(LAYER_BACKGROUND);
	render_layer(LAYER_FOREGROUND);

	EndMode2D();

	EndDrawing();
}