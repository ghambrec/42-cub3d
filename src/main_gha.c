#include "cub3d.h"

#define WIDTH 256
#define HEIGHT 256


char *map[] = {
    "1111111111",
    "1000000111",
    "1001000111",
    "1001000111",
    "1000P00111",
    "1111111111",
	NULL
};




int	main(void)
{
	t_game game;
	game.img_game = NULL;
	game.img_minimap = NULL;
	game.map_max_width = 10;
	game.map_max_height = 6;
	game.map = map;
	game.player.x = 4.5;
	game.player.y = 4.5;
	// spieler schaut nach norden (oben)
	game.player.dir_x = 0;
	game.player.dir_y = -1;


	// create mlx window
	game.mlx = mlx_init(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGTH, "cub3d", true);
	if (!game.mlx)
		exit_failure(&game, "failed to init the mlx (mlx_init)");

	// create image for game
	game.img_game = mlx_new_image(game.mlx, GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGTH);
	if (!game.img_game)
		exit_failure(&game, "failed to create the game window (mlx_new_image)");
	if (mlx_image_to_window(game.mlx, game.img_game, 0, 0) < 0)
		exit_failure(&game, "failed to load game image to window (mlx_image_to_window)");


	create_minimap(&game);
	




		

	mlx_key_hook(game.mlx, &key_hook, &game);
	mlx_resize_hook(game.mlx, &resize_hook, &game);
	mlx_loop_hook(game.mlx, &loop_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}




