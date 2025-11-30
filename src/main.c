#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game game;

	init_game(&game);
	arg_validation(argv, argc);
	game.map.map_name = argv[1];
	map_validation(&game);

	printf("%s", game.map.floor_color);
	printf("%s", game.map.ceiling_color);
	printf("%s", game.texture_path.east);
	printf("%s", game.texture_path.north);
	printf("%s", game.texture_path.west);
	printf("%s", game.texture_path.south);
	
	init_mlx(&game);
	//render_game(&game);
	//init_hooks(&game);
	//mlx_loop(game.mlx);
	//exit_success(&game);
	return (EXIT_SUCCESS);
}
