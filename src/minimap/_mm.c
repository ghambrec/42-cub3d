#include "cub3d.h"

uint32_t	get_color(char mapval)
{
	if (mapval == MV_WALL)
		return (CMM_WALL);
	if (mapval == MV_FLOOR)
		return (CMM_FLOOR);
	if (mapval == MV_PLAYER)
		return (CMM_FLOOR);
	return (CMM_WALL);
}

// paints on the current coords a tile with tile_size
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

void	paint_background(t_game *game)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < game->minimap.height)
	{
		j = 0;
		while (j < game->minimap.width)
		{
			mlx_put_pixel(game->img_minimap, j, i, get_color(MV_WALL));
			j++;
		}
		i++;
	}
}

static void	calculate_sizes(t_game *game)
{
	t_minimap *minimap;
	int	tile_w;
	int	tile_h;
	int	used_w;
	int	used_h;

	minimap = &game->minimap;
	minimap->width = (uint32_t)game->mlx->width * 0.25;
	minimap->height = (uint32_t)game->mlx->height * 0.25;
	tile_w = minimap->width / game->map_max_width;
	tile_h = minimap->height / game->map_max_height;
	if (tile_w < tile_h)
		minimap->tile_size = tile_w;
	else
		minimap->tile_size = tile_h;
	used_w = minimap->tile_size * game->map_max_width;
	used_h = minimap->tile_size * game->map_max_height;
	minimap->off_x = (minimap->width - used_w) / 2;
	minimap->off_y = (minimap->height - used_h) / 2;
}

void paint_minimap(t_game *game)
{
	int	my;
	int	mx;

	my = 0;
	while (game->map[my])
	{
		mx = 0;
		while (game->map[my][mx])
		{
			paint_tile(game, mx, my, game->map[my][mx]);
			mx++;
		}
		my++;
	}
}

// player pos = (tile_size * player_pos) + offset
void paint_player(t_game *game)
{
	t_position	pos;
	int			size;
	int			radius;
	int			x;
	int			y;

	pos.x = (game->player.x * game->minimap.tile_size) + game->minimap.off_x;
	pos.y = (game->player.y * game->minimap.tile_size) + game->minimap.off_y;
	size = game->minimap.tile_size / 4;
	radius = size / 2;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			mlx_put_pixel(game->img_minimap, pos.x - radius + x, pos.y - radius + y, CMM_PLAYER);
			x++;
		}
		y++;
	}
}

void	create_minimap(t_game *game)
{
	calculate_sizes(game);
	mlx_delete_image(game->mlx, game->img_minimap);
	game->img_minimap = mlx_new_image(game->mlx, game->minimap.width, game->minimap.height);
	if (!game->img_minimap)
		exit_failure(game, "failed to create minimap image (mlx_new_image)");
	if (mlx_image_to_window(game->mlx, game->img_minimap, 0, 0) < 0)
		exit_failure(game, "failed to load minimap image to window (mlx_image_to_window)");
	paint_background(game);
	paint_minimap(game);
	paint_player(game);
}
