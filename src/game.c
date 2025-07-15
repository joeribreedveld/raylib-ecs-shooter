#include "actors/player.h"

#include "camera.h"
#include "game.h"
#include "config.h"

#include "raymath.h"

#include "ecs/systems/lifetime_system.h"
#include "ecs/systems/shooting_system.h"
#include "ecs/components/position_component.h"
#include "ecs/systems/input_system.h"
#include "ecs/systems/movement_system.h"
#include "ecs/systems/render_system.h"

#include <stdlib.h>

struct game *game_init()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Top Down Shooter");

	SetTargetFPS(144);

	struct game *game = malloc(sizeof(struct game));

	game->player_tex = LoadTexture("assets/player.png");
	game->bullet_tex = LoadTexture("assets/bullet.png");

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

		shooting_system(game->player_id, game->camera,
				game->bullet_tex);

		lifetime_system(dt);

		movement_system(dt, SCREEN_WIDTH, SCREEN_HEIGHT);

		camera_follow(&game->camera, positions[game->player_id]);

		render_system(game->camera, game->player_id);
	}
}

void game_shutdown(struct game *game)
{
	UnloadTexture(game->player_tex);
	free(game);

	CloseWindow();
}
