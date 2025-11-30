#include "cub3d.h"

void	clean_game(t_game *game)
{
	(void)game;
	ft_putendl_fd("TODO --> clean_game.c", STDOUT_FILENO);
	free(game->map.map_string);
	ft_str2d_free(game->map.map2d);
	mlx_terminate(game->mlx);
}
