#include "cub3d.h"

static void	get_player_dir(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
	}
	if (dir == 'E')
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
	}
	if (dir == 'S')
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
	}
	if (dir == 'W')
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
	}
	game->player.plane.x = -game->player.dir.y * GAME_FOV;
	game->player.plane.y = game->player.dir.x * GAME_FOV;
}

void	get_player_pos(t_game *game)
{
	size_t	i;
	int		y;

	i = 0;
	y = 0;
	while (game->map.map2d[y])
	{
		i = 0;
		while (i < ft_strlen(game->map.map2d[y]))
		{
			if (game->map.map2d[y][i] == 'N' || game->map.map2d[y][i] == 'E'
				|| game->map.map2d[y][i] == 'S' || game->map.map2d[y][i] == 'W')
			{
				game->player.pos1D.x = i;
				game->player.pos1D.y = y;
				game->player.pos.x = i + 0.5;
				game->player.pos.y = y + 0.5;
				get_player_dir(game, game->map.map2d[y][i]);
				game->map.map2d[y][i] = 'P';
				return ;
			}
			i++;
		}
		y++;
	}
}
