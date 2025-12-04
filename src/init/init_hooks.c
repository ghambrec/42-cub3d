#include "cub3d.h"

void	init_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_resize_hook(game->mlx, &resize_hook, game);
	mlx_loop_hook(game->mlx, &loop_hook, game);
	mlx_set_mouse_pos(game->mlx, GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGTH / 2);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
}
