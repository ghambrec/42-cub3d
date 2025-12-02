#include "cub3d.h"

void	clean_game(t_game *game)
{
	if (game->map.map_string)
		free(game->map.map_string);
	if (game->map.map2d)
	{
		ft_str2d_free(game->map.map2d);
		ft_str2d_free(game->map.map2d_copy);
		free(game->texture_path.east);
		free(game->texture_path.north);
		free(game->texture_path.west);
		free(game->texture_path.south);
	}
	if (game->mlx)
		mlx_terminate(game->mlx);
}
