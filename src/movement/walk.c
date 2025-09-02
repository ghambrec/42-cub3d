#include "cub3d.h"

// W
void	walk_north(t_game *game)
{
	t_position2D	new_pos;

	new_pos.x = game->player.pos.x + game->player.dir.x * MV_SPEED;
	new_pos.y = game->player.pos.y + game->player.dir.y * MV_SPEED;
	game->player.pos = new_pos;
}

// A
void	walk_west(t_game *game)
{
	t_position2D	new_pos;

	new_pos.x = game->player.pos.x + game->player.dir.y * MV_SPEED;
	new_pos.y = game->player.pos.y - game->player.dir.x * MV_SPEED;
	game->player.pos = new_pos;
}

// S
void	walk_south(t_game *game)
{
	t_position2D	new_pos;

	new_pos.x = game->player.pos.x - game->player.dir.x * MV_SPEED;
	new_pos.y = game->player.pos.y - game->player.dir.y * MV_SPEED;
	game->player.pos = new_pos;
}

// D
void	walk_east(t_game *game)
{
	t_position2D	new_pos;

	new_pos.x = game->player.pos.x - game->player.dir.y * MV_SPEED;
	new_pos.y = game->player.pos.y + game->player.dir.x * MV_SPEED;
	game->player.pos = new_pos;
}
