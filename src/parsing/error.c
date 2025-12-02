#include "cub3d.h"

void exit_failure(t_game *game, char *msg)
{
    clean_game(game);
    ft_putendl_fd("Error", 2);
    ft_putendl_fd(msg, 2);
    exit(EXIT_FAILURE);
}