#include "ecs/systems/render_system.h"
#include "ecs/components.h"
#include "utils/render_layer.h"

#include "raylib.h"

void render_system(Camera2D camera)
{
	BeginDrawing();

	/* TODO: Draw map with grass background from tileset */
	ClearBackground(BLACK);

	BeginMode2D(camera);

	DrawRectangle(0, 0, 100, 100, PINK);

	render_layer(LAYER_NONE);
	render_layer(LAYER_BACKGROUND);
	render_layer(LAYER_FOREGROUND);

	EndMode2D();

	EndDrawing();
}