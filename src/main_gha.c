#include "cub3d.h"

#define WIDTH 256
#define HEIGHT 256


char *map[] = {
    "11111111",
    "10000001",
    "10010001",
    "10010001",
    "10000001",
    "1000P001",
    "10000001",
    "11111111",
	NULL
};

// malt bei den aktuellen coords ein feld mit TILExTILE size
void	paint_tile(mlx_image_t *img, int mx, int my, uint32_t color)
{
	int x = 0;
	int y = 0;
	int ox;
	int oy = my * MM_TILE;

	while (y < MM_TILE)
	{
		x = 0;
		ox = mx * MM_TILE;
		while (x < MM_TILE)
		{
			mlx_put_pixel(img, ox, oy, color);
			ox++;
			x++;
		}
		oy++;
		y++;
	}
}

int	main(void)
{
	t_game game;

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

	// create image for minimap and calculate how big it has to be
	t_size size;
	size.width = game.mlx->width * 0.25;
	size.height = game.mlx->height * 0.25;
	// mlx_put_pixel(game.img_minimap, size.width-1, size.height-1, RED);
	game.img_minimap = mlx_new_image(game.mlx, size.width, size.height);
	if (!game.img_minimap)
		exit_failure(&game, "failed to create the minimap window (mlx_new_image)");
	if (mlx_image_to_window(game.mlx, game.img_minimap, 0, 0) < 0)
		exit_failure(&game, "failed to load minimap image to window (mlx_image_to_window)");


	int my = 0;
	int mx = 0;
	while (map[my])
	{
		mx = 0;
		while (map[my][mx])
		{
			if (map[my][mx] == MV_WALL)
				paint_tile(game.img_minimap, mx, my, RED);
			if (map[my][mx] == MV_FLOOR || map[my][mx] == MV_PLAYER_NORTH)
				paint_tile(game.img_minimap, mx, my, GREY);
			mx++;
		}
		my++;
	}

		

	
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}




