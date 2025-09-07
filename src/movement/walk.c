#include "cub3d.h"

// dont walk in a wall
bool	able_to_walk(t_game *game, int x, int y)
{
	if (game->map.map2d[y][x] == '1')
		return (false);
	return (true);
}

// W
void	walk_north(t_game *game)
{
	t_position2D	new_pos;

	new_pos.x = game->player.pos.x + game->player.dir.x * MV_SPEED;
	new_pos.y = game->player.pos.y + game->player.dir.y * MV_SPEED;
	if (able_to_walk(game, (int)new_pos.x, (int)game->player.pos.y))
		game->player.pos.x = new_pos.x;
	if (able_to_walk(game, (int)game->player.pos.x, (int)new_pos.y))
		game->player.pos.y = new_pos.y;
}

// A
void	walk_west(t_game *game)
{
	t_position2D	new_pos;

	new_pos.x = game->player.pos.x + game->player.dir.y * MV_SPEED;
	new_pos.y = game->player.pos.y - game->player.dir.x * MV_SPEED;
	if (able_to_walk(game, (int)new_pos.x, (int)game->player.pos.y))
		game->player.pos.x = new_pos.x;
	if (able_to_walk(game, (int)game->player.pos.x, (int)new_pos.y))
		game->player.pos.y = new_pos.y;
}

// S
void	walk_south(t_game *game)
{
	t_position2D	new_pos;

	new_pos.x = game->player.pos.x - game->player.dir.x * MV_SPEED;
	new_pos.y = game->player.pos.y - game->player.dir.y * MV_SPEED;
	if (able_to_walk(game, (int)new_pos.x, (int)game->player.pos.y))
		game->player.pos.x = new_pos.x;
	if (able_to_walk(game, (int)game->player.pos.x, (int)new_pos.y))
		game->player.pos.y = new_pos.y;
}

// D
void	walk_east(t_game *game)
{
	t_position2D	new_pos;

	new_pos.x = game->player.pos.x - game->player.dir.y * MV_SPEED;
	new_pos.y = game->player.pos.y + game->player.dir.x * MV_SPEED;
	if (able_to_walk(game, (int)new_pos.x, (int)game->player.pos.y))
		game->player.pos.x = new_pos.x;
	if (able_to_walk(game, (int)game->player.pos.x, (int)new_pos.y))
		game->player.pos.y = new_pos.y;
}
