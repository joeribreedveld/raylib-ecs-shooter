#include "raylib.h"
#include "raymath.h"
#include "systems.h"
#include "entity.h"
#include "components.h"

int main()
{
	const int screen_width = 640;
	const int screen_height = 480;

	const float speed = 200.0f;

	InitWindow(screen_width, screen_height, "Top Down Shooter");

	SetTargetFPS(144);

	int e = create_entity();

	/* Position */
	positions[e] = Vector2Zero();

	has_position[e] = true;

	/* Velocity */
	velocities[e] = Vector2Zero();

	has_velocity[e] = true;

	has_input[e] = true;

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();

		input_system(speed);

		movement_system(dt, screen_width, screen_height);

		render_system();
	}

	CloseWindow();
}