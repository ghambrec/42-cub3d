#include "cub3d.h"

void	clean_game(t_game *game)
{
	if (game->map.map_string)
		free(game->map.map_string);
	if (game->map.map2d)
	{
		ft_str2d_free(game->map.map2d);
		ft_str2d_free(game->map.map2d_copy);
	}
	if (game->mlx)
		mlx_terminate(game->mlx);
}
