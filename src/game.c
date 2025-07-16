#include "actors/player.h"

#include "camera.h"
#include "game.h"
#include "config.h"

#include "raymath.h"

#include "ecs/systems/lifetime_system.h"
#include "ecs/systems/shooting_system.h"
#include "ecs/systems/mouse_system.h"
#include "ecs/components.h"
#include "ecs/systems/input_system.h"
#include "ecs/systems/movement_system.h"
#include "ecs/systems/render_system.h"

#include <stdlib.h>

struct game *game_init()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "ECS Shooter");

	SetTargetFPS(144);

	struct game *game = malloc(sizeof(struct game));

	/* TODO: Manage textures abstract and more modular */
	game->player_tex = LoadTexture("assets/player.png");
	game->bullet_tex = LoadTexture("assets/bullet.png");

	/* TODO: Only use player_id for camera not for ECS (from other todo) */
	game->player_id =
		player_create(Vector2Zero(), PLAYER_SPEED, game->player_tex);

	game->camera = camera_create(positions[game->player_id]);

	return game;
}

void game_loop(struct game *game)
{
	while (!WindowShouldClose()) {
		float dt = GetFrameTime();

		input_system();

		/* TODO: Don't make systems depend on singular hardcoded entities */
		shooting_system(game->camera, game->bullet_tex);

		lifetime_system(dt);

		movement_system(dt);

		camera_follow(&game->camera, positions[game->player_id]);

		mouse_system(game->camera);

		/* TODO: Render also shouldn't need single entity */
		render_system(game->camera, game->player_id);
	}
}

void game_shutdown(struct game *game)
{
	UnloadTexture(game->player_tex);
	UnloadTexture(game->bullet_tex);

	free(game);

	CloseWindow();
}
