#include "cub3d.h"

// paints the viewing direction from the player
void	paint_direction(t_game *game)
{
	t_vector	vec;
	t_position	pos;

	vec.x = game->player.pos.x + game->player.dir.x;
	vec.y = game->player.pos.y + game->player.dir.y;
	pos.x = vec.x * game->minimap.tile_size + game->minimap.off_x;
	pos.y = vec.y * game->minimap.tile_size + game->minimap.off_y;
	put_pixel_safe(game->img_minimap, pos.x, pos.y, CMM_DIR);

	// plane left
	vec.x = game->player.pos.x + game->player.dir.x - game->player.plane.x;
	vec.y = game->player.pos.y + game->player.dir.y - game->player.plane.y;
	pos.x = vec.x * game->minimap.tile_size + game->minimap.off_x;
	pos.y = vec.y * game->minimap.tile_size + game->minimap.off_y;
	put_pixel_safe(game->img_minimap, pos.x, pos.y, CMM_DIR);
	// plane rigth
	vec.x = game->player.pos.x + game->player.dir.x + game->player.plane.x;
	vec.y = game->player.pos.y + game->player.dir.y + game->player.plane.y;
	pos.x = vec.x * game->minimap.tile_size + game->minimap.off_x;
	pos.y = vec.y * game->minimap.tile_size + game->minimap.off_y;
	put_pixel_safe(game->img_minimap, pos.x, pos.y, CMM_DIR);
}
