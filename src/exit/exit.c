#include "cub3d.h"

void	exit_success(t_game *game)
{
	if (game)
		clean_game(game);
	exit(EXIT_SUCCESS);
}
