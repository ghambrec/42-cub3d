#include "cub3d.h"

void	init_mlx(t_game *game)
{
	// mlx init
	game->mlx = mlx_init(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGTH, "cub3d", true);
	if (!game->mlx)
		exit_failure(game, "failed to init the mlx (mlx_init)");
}
