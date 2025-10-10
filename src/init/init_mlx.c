#include "cub3d.h"

void	init_mlx(t_game *game)
{
	// mlx init
	game->mlx = mlx_init(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGTH, "cub3d", true);
	if (!game->mlx)
		exit_failure(game, "failed to init the mlx (mlx_init)");

	// game window
	game->img_game = mlx_new_image(game->mlx, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGTH);
	if (!game->img_game)
		exit_failure(game, "failed to create the game window (mlx_new_image)");
	if (mlx_image_to_window(game->mlx, game->img_game, 0, 0) < 0)
		exit_failure(game, "failed to load game image to window (mlx_image_to_window)");


}
