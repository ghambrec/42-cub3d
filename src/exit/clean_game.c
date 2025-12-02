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
	if (game->textures[T_NORTH])
		mlx_delete_texture(game->textures[T_NORTH]);
	if (game->textures[T_EAST])
		mlx_delete_texture(game->textures[T_EAST]);
	if (game->textures[T_SOUTH])
		mlx_delete_texture(game->textures[T_SOUTH]);
	if (game->textures[T_WEST])
		mlx_delete_texture(game->textures[T_WEST]);
	if (game->mlx)
		mlx_terminate(game->mlx);
}
