#include "cub3d.h"

void	map_validation(t_game *game)
{
	map_open(&game->map);
	char_validation(game->map.map_string);
	create_map(game);
	get_map_width_height(game);
	get_player_pos(game);
	// printf("Player Position: x=%i, y=%i\n", game->player.pos1D.x, game->player.pos1D.y);
	floodfill_validation(game);
	free(game->map.map_string);
	// printf("Map validation successful\n");
	return ;
}
