#include "cub3d.h"

void	resize_hook(int32_t width, int32_t height, void *param)
{
	t_game *game;

	game = (t_game *)param;
	create_minimap(game);
}
