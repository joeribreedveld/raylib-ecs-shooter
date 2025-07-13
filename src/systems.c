#include "systems.h"
#include "components.h"
#include "entity.h"
#include "raymath.h"

void render_system()
{
	BeginDrawing();

	ClearBackground(BLACK);

	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i]) {
			continue;
		}

		DrawRectangle((int)positions[i].x, (int)positions[i].y, 16, 16,
			      WHITE);
	}

	EndDrawing();
}

void movement_system(float dt, int screen_width, int screen_height)
{
	for (int i = 0; i < next_entity; i++) {
		if (!has_position[i] || !has_velocity[i]) {
			continue;
		}

		positions[i] = Vector2Add(positions[i],
					  Vector2Scale(velocities[i], dt));
	}
}

void input_system(float speed)
{
	for (int i = 0; i < next_entity; i++) {
		if (!has_velocity[i] || !has_input[i]) {
			continue;
		}

		Vector2 dir = Vector2Zero();

		if (IsKeyDown(KEY_W)) {
			dir.y -= 1;
		}

		if (IsKeyDown(KEY_A)) {
			dir.x -= 1;
		}

		if (IsKeyDown(KEY_S)) {
			dir.y += 1;
		}

		if (IsKeyDown(KEY_D)) {
			dir.x += 1;
		}

		if (dir.x != 0 && dir.y != 0) {
			dir = Vector2Normalize(dir);
		}

		velocities[i] = Vector2Scale(dir, speed);
	}
}