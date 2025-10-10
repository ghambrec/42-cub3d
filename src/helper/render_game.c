#include "cub3d.h"

void	render_game(t_game *game)
{
	create_minimap(game);
	raycasting(game);
}