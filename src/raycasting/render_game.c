#include "cub3d.h"

// HEIGTH durch 2, obere haelfte ceil untere floor
static void	fill_ceil_floor(t_game *game)
{
	uint32_t x;
	uint32_t y;
	uint32_t color;

	y = 0;
	while (y < GAME_SCREEN_HEIGTH)
	{
		if (y >= GAME_SCREEN_HEIGTH / 2)
			color = FLOOR;
		else
			color = CEIL;
		x = 0;
		while (x < GAME_SCREEN_WIDTH)
		{
			mlx_put_pixel(game->img_game, x, y, color);
			x++;
		}
		y++;
	}
}

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
