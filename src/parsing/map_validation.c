#include "cub3d.h"

void	map_validation(t_game *game)
{
	map_open(game);
	char_validation(game->map.map_string);
	create_map(game);
	get_map_width_height(game);
	get_player_pos(game);
	if (floodfill_validation(game) == 0)
	{
		clean_game(game);
		exit(EXIT_FAILURE);
	}
	if (game->map.ceiling_color == 0 || game->map.floor_color == 0 
		|| game->texture_path.east == NULL || game->texture_path.north == NULL
		|| game->texture_path.south == NULL || game->texture_path.west == NULL)
	{
		ft_putendl_fd("Error Texture or Color is missing!", 2);
		clean_game(game);
		exit(EXIT_FAILURE);
	}
	return ;
}
