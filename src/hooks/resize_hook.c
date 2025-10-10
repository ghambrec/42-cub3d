#include "cub3d.h"


void	resize_hook(int32_t width, int32_t height, void *param)
{
	// TODO: resize game window (bisher geht nur die minimap)
	// TODO: min size festlegen


	t_game *game;

	(void)width;
	(void)height;
	game = (t_game *)param;
	create_minimap(game);
}
