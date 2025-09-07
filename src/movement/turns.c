#include "cub3d.h"

void	turn_left(t_game *game)
{
	t_position2D	old_dir;

	old_dir = game->player.dir;
	game->player.dir.x = old_dir.x * cos(-MV_ANGLE) - old_dir.y * sin(-MV_ANGLE);
	game->player.dir.y = old_dir.x * sin(-MV_ANGLE) + old_dir.y * cos(-MV_ANGLE);
}

void	turn_right(t_game *game)
{
	t_position2D	old_dir;

	old_dir = game->player.dir;
	game->player.dir.x = old_dir.x * cos(MV_ANGLE) - old_dir.y * sin(MV_ANGLE);
	game->player.dir.y = old_dir.x * sin(MV_ANGLE) + old_dir.y * cos(MV_ANGLE);
}
