#include "cub3d.h"

void	loop_hook(void *param)
{
	t_game *game;

	game = (t_game *)param;

	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		turn_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		turn_right(game);
	create_minimap(game);
}
