#include "cub3d.h"

// paints on the current coords a tile with tile_size x tile_size
static void	paint_tile(t_game *game, int mx, int my, char mapval)
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
			put_pixel_safe(game->img_minimap, ox, oy, get_tile_color(mapval));
			ox++;
			x++;
		}
		oy++;
		y++;
	}
}

void paint_minimap(t_game *game)
{
	int	my;
	int	mx;

	my = 0;
	while (game->map.map2d[my])
	{
		mx = 0;
		while (game->map.map2d[my][mx])
		{
			paint_tile(game, mx, my, game->map.map2d[my][mx]);
			mx++;
		}
		my++;
	}
}
