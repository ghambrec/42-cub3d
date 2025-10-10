#include "cub3d.h"

void	handle_resize(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_minimap);
	game->img_minimap = NULL;
	mlx_delete_image(game->mlx, game->img_game);
	game->img_game = NULL;
	render_game(game);
}

void	resize_hook(int32_t width, int32_t height, void *param)
{
	// TODO: resize game window (bisher geht nur die minimap)
	// TODO: min size festlegen
	t_game *game;

	(void)width;
	(void)height;
	game = (t_game *)param;
	handle_resize(game);
}
