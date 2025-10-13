#include "cub3d.h"

void	clean_game(t_game *game)
{
	(void)game;
	ft_putendl_fd("TODO --> clean_game.c", STDOUT_FILENO);

	//delete textures hier nicht vergessen

	//mlx terminate hier noch richtig mit einbauen
	mlx_terminate(game->mlx);
}
