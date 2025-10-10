#include "cub3d.h"

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
