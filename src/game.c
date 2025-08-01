#include "actors/enemy.h"
#include "actors/player.h"

#include "camera.h"
#include "game.h"
#include "map.h"
#include "config.h"

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

	map_load("assets/map.json", "assets/spritesheet.png");

	/* TODO: Manage textures abstract and more modular */
	game->player_tex = LoadTexture("assets/player.png");
	game->bullet_tex = LoadTexture("assets/bullet.png");
	game->enemy_tex = LoadTexture("assets/enemy.png");

	Vector2 player_pos = { 512, 512 };

	int player_id =
		player_create(player_pos, PLAYER_SPEED, game->player_tex);

	enemy_create((Vector2){ -100, -100 }, PLAYER_SPEED, game->enemy_tex);

	game->camera_target = player_id;

	game->camera = camera_create(positions[player_id]);

	return game;
}

void game_loop(struct game *game)
{
	while (!WindowShouldClose()) {
		float dt = GetFrameTime();

		input_system();

		shooting_system(game->camera, game->bullet_tex);

		lifetime_system(dt);

		movement_system(dt);

		camera_follow(&game->camera, positions[game->camera_target]);

		mouse_system(game->camera);

		render_system(game->camera);
	}
}

void game_shutdown(struct game *game)
{
	UnloadTexture(game->player_tex);
	UnloadTexture(game->bullet_tex);

	free(game);

	CloseWindow();
}
