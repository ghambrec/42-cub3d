#include "cub3d.h"

// player pos = (tile_size * player_pos) + offset
void	paint_player(t_game *game)
{
	t_position	pos;
	int			size;
	int			radius;
	int			x;
	int			y;

	pos.x = (game->player.pos.x * game->minimap.tile_size) + game->minimap.off_x;
	pos.y = (game->player.pos.y * game->minimap.tile_size) + game->minimap.off_y;
	size = game->minimap.tile_size / MM_PLAYER_SIZE;
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
