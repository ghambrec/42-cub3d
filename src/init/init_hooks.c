#include "cub3d.h"

void	init_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, &key_hook, game);
	mlx_resize_hook(game->mlx, &resize_hook, game);
	mlx_loop_hook(game->mlx, &loop_hook, game);
}
