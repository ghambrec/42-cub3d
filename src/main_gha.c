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

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.action == MLX_RELEASE)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_success(game);
}

uint32_t	get_color(char mapval)
{
	if (mapval == MV_WALL)
		return (CMM_WALL);
	if (mapval == MV_FLOOR)
		return (CMM_FLOOR);
	return (BLACK);
}

// malt bei den aktuellen coords ein feld mit TILExTILE size
void	paint_tile(t_game *game, int mx, int my, char mapval)
{
	int x = 0;
	int y = 0;
	int ox;
	int oy = game->minimap.off_y + my * game->minimap.tile_size;

	while (y < game->minimap.tile_size)
	{
		x = 0;
		ox = game->minimap.off_x + mx * game->minimap.tile_size;
		while (x < game->minimap.tile_size)
		{
			mlx_put_pixel(game->img_minimap, ox, oy, get_color(mapval));
			ox++;
			x++;
		}
		oy++;
		y++;
	}
}

void	paint_white(t_game *game, t_size *size)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < size->height)
	{
		j = 0;
		while (j < size->width)
		{
			mlx_put_pixel(game->img_minimap, j, i, get_color(MV_WALL));
			j++;
		}
		i++;
	}
}

void	create_minimap(t_game *game)
{
	t_size size;

	if (!game->img_minimap)
	{
		size.width = (uint32_t)game->mlx->width * 0.25;
		size.height = (uint32_t)game->mlx->height * 0.25;

		game->img_minimap = mlx_new_image(game->mlx, size.width, size.height);
		if (!game->img_minimap)
			exit_failure(game, "failed to create minimap image (mlx_new_image)");
		if (mlx_image_to_window(game->mlx, game->img_minimap, 0, 0) < 0)
			exit_failure(game, "failed to load minimap image to window (mlx_image_to_window)");

		paint_white(game, &size); // ganzen minimap bereich weis malen

		// tile size berechnen -> auslagern
		int tile_w = size.width / game->map_max_width;
		int tile_h = size.height / game->map_max_height;
		if (tile_w < tile_h)
			game->minimap.tile_size = tile_w;
		else
			game->minimap.tile_size = tile_h;
		// ft_putendl_fd(ft_itoa(tile), STDOUT_FILENO);
		// ende tile size berechnen

		// berechne wie viel platz ingesamt gebraucht wird zum zentrieren
		int used_w = game->minimap.tile_size * game->map_max_width;
		int used_h = game->minimap.tile_size * game->map_max_height;
		// ft_putendl_fd(ft_itoa(used_w), STDOUT_FILENO);
		// ft_putendl_fd(ft_itoa(used_h), STDOUT_FILENO);
		game->minimap.off_x = (size.width - used_w) / 2;
		game->minimap.off_y = (size.height - used_h) / 2;
		// ft_putendl_fd(ft_itoa(offx), STDOUT_FILENO);
		// ft_putendl_fd(ft_itoa(offy), STDOUT_FILENO);
		// ende zentrierungsrechnung

		// malen der minimap
		int	my;
		int	mx;

		my = 0;
		while (map[my])
		{
			mx = 0;
			while (map[my][mx])
			{
				paint_tile(game, mx, my, map[my][mx]);
				mx++;
			}
			my++;
		}
		// ende malen minimap
	}
}

int	main(void)
{
	t_game game;
	game.img_game = NULL;
	game.img_minimap = NULL;
	game.map_max_width = 48;
	game.map_max_height = 32;

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
	




		

	mlx_key_hook(game.mlx, &keyhook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}




