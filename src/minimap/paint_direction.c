#include "cub3d.h"

// paints the viewing direction from the player
void	paint_direction(t_game *game)
{
	t_position2D	pos2D;
	t_position		pos;

	pos2D.x = game->player.pos.x + game->player.dir.x;
	pos2D.y = game->player.pos.y + game->player.dir.y;
	pos.x = pos2D.x * game->minimap.tile_size + game->minimap.off_x;
	pos.y = pos2D.y * game->minimap.tile_size + game->minimap.off_y;
	put_pixel_safe(game->img_minimap, pos.x, pos.y, CMM_DIR);
}
