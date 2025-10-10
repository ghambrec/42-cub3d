#include "cub3d.h"

void	loop_hook(void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		turn_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		turn_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		walk_north(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		walk_west(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		walk_south(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		walk_east(game);
	render_game(game);
}
