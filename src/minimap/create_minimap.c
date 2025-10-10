#include "cub3d.h"

// calculates sizes and offset for the minimap
static void	calculate_sizes(t_game *game)
{
	t_minimap *minimap;
	int	tile_w;
	int	tile_h;
	int	used_w;
	int	used_h;

	minimap = &game->minimap;
	minimap->width = (uint32_t)game->mlx->width / MM_SIZE;
	minimap->height = (uint32_t)game->mlx->height / MM_SIZE;
	tile_w = minimap->width / game->map.max_width;
	tile_h = minimap->height / game->map.max_height;
	if (tile_w < tile_h)
		minimap->tile_size = tile_w;
	else
		minimap->tile_size = tile_h;
	used_w = minimap->tile_size * game->map.max_width;
	used_h = minimap->tile_size * game->map.max_height;
	minimap->off_x = (minimap->width - used_w) / 2;
	minimap->off_y = (minimap->height - used_h) / 2;
}

// creates the minimap image and calls functions to paint into it
void	create_minimap(t_game *game)
{
	calculate_sizes(game);
	if (!game->img_minimap)
	{
		game->img_minimap = mlx_new_image(game->mlx, game->minimap.width, game->minimap.height);
		if (!game->img_minimap)
			exit_failure(game, "failed to create minimap image (mlx_new_image)");
		if (mlx_image_to_window(game->mlx, game->img_minimap, 0, 0) < 0)
			exit_failure(game, "failed to load minimap image to window (mlx_image_to_window)");
	}
	paint_background(game);
	paint_minimap(game);
	paint_player(game);
	// paint_direction(game);
}
