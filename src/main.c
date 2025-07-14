
#include "game.h"

int main()
{
	struct game *game = game_init();

	game_loop(game);

	game_shutdown(game);
}