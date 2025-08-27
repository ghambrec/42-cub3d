#include "cub3d.h"

#define WIDTH 256
#define HEIGHT 256

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

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
			mlx_put_pixel(img, ox + 5, oy + 5, color);
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
	game.mlx = mlx_init(GAME_SCREEN_WIDTH, GAME_SCREEN_HIGH, "cub3d", true);
	if (game.mlx)
		exit_failure(&game, "failed to init the mlx (mlx_init)");

	// create image for minimap
	mlx_image_t* img = mlx_new_image(game.mlx, MM_MIN_SIZE, MM_MIN_SIZE);
	if (!img)
		exit_failure(&game, "failed to create the game window (mlx_new_image)");



	int my = 0;
	int mx = 0;
	while (map[my])
	{
		mx = 0;
		while (map[my][mx])
		{
			if (map[my][mx] == MV_WALL)
				paint_tile(img, mx, my, RED);
			if (map[my][mx] == MV_FLOOR || map[my][mx] == MV_PLAYER_NORTH)
				paint_tile(img, mx, my, GREY);
			mx++;
		}
		my++;
	}

		
	if (mlx_image_to_window(game.mlx, img, 0, 0) < 0)
		ft_error();
	
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}




