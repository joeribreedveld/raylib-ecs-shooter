#include "actors/player.h"

#include "ecs/systems/input_system.h"
#include "ecs/systems/movement_system.h"
#include "ecs/systems/render_system.h"

#include "raylib.h"

int main()
{
	const int screen_width = 640;
	const int screen_height = 480;

	const Vector2 screen_center =
		(Vector2){ screen_width / 2.0f, screen_height / 2.0f };

	const float player_speed = 200.0f;

	InitWindow(screen_width, screen_height, "Top Down Shooter");

	SetTargetFPS(144);

	player_create(screen_center, player_speed);

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();

		input_system();

		movement_system(dt, screen_width, screen_height);

		render_system();
	}

	CloseWindow();
}