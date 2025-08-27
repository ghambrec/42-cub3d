#include "cub3d.h"

void	exit_success(t_game *game)
{
	if (game)
		clean_game(game);
	exit(EXIT_SUCCESS);
}

void	exit_failure(t_game *game, char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	if (game)
		clean_game(game);
	exit(EXIT_FAILURE);
}
