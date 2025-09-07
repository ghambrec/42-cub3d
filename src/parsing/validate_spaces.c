#include "cub3d.h"

void validate_spaces(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map.map2d[y])
    {
        x = 0;
        while (game->map.map2d[y][x])
        {
            if (game->map.map2d[y][x] == ' ')
            {

                if ((x > 0 && game->map.map2d[y][x - 1] == '0') ||
                    (x < game->map.width - 1 && game->map.map2d[y][x + 1] == '0') ||
                    (y > 0 && game->map.map2d[y - 1][x] == '0') ||
                    (y < game->map.height - 1 && game->map.map2d[y + 1][x] == '0'))
                {
                    ft_putstr_fd("Map is invalid! Space should not touch any 0\n", 2);
                    clean_game(game);
                    exit(EXIT_FAILURE);
                }
            }
            x++;
        }
        y++;
    }
}