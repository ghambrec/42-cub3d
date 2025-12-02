#include "cub3d.h"

void	map_validation(t_game *game)
{
	map_open(game);
	char_validation(game);
	create_map(game);
	get_map_width_height(game);
	get_player_pos(game);
	floodfill_validation(game);
	if (game->map.ceiling_color == 0 || game->map.floor_color == 0 
		|| game->texture_path.east == NULL || game->texture_path.north == NULL
		|| game->texture_path.south == NULL || game->texture_path.west == NULL)
	{
		exit_failure(game, "Color or Texture is missing");
	}
	return ;
}
