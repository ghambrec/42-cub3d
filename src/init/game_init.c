#include "cub3d.h"

void	game_init(t_game *game)
{
	game->map.map2d = NULL;
	game->map.map2d_copy = NULL;
	game->map.map_name = NULL;
	game->map.map_string = NULL;

	game->img_game = NULL;
	game->img_minimap = NULL;
}
