#include "cub3d.h"

void	render_game(t_game *game)
{
	if (!game->img_game)
	{
		game->img_game = mlx_new_image(game->mlx, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGTH);
		if (!game->img_game)
			exit_failure(game, "failed to create the game window (mlx_new_image)");
		if (mlx_image_to_window(game->mlx, game->img_game, 0, 0) < 0)
			exit_failure(game, "failed to load game image to window (mlx_image_to_window)");
	}
	create_minimap(game);
	fill_ceil_floor(game);
	raycasting(game);
}

int	main(int argc, char **argv)
{
	t_game game;

	init_game(&game);
	arg_validation(argv, argc);
	game.map.map_name = argv[1];
	map_validation(&game);

	init_mlx(&game);
	render_game(&game);
	init_hooks(&game);
	mlx_loop(game.mlx);
	exit_success(&game);
	return (EXIT_SUCCESS);
}
