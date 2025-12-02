#include "cub3d.h"

void    parse_rgbs(char *string, t_game *game)
{
    if (string[0] == 'F' && string[1] == ' ')
	{
        if (game->map.floor_color != 0)
            exit_failure(game, "dublicates not allowed");
		game->map.floor_color = parse_color(string, game);
		return ;
	}
	if (string[0] == 'C' && string[1] == ' ')
	{
		if (game->map.ceiling_color != 0)
            exit_failure(game, "dublicates not allowed");
		game->map.ceiling_color = parse_color(string, game);
		return ;
	}
}

static void check_dublicate(char *string, t_game *game)
{
    if (string != NULL)
        exit_failure(game, "dublicates not allowed");
}

void    parse_textures(char *string, char *path, t_game *game)
{
    if (string[0] == 'N' && string[1] == 'O')
    {
        check_dublicate(game->texture_path.north, game);
		game->texture_path.north = ft_strdup(path);
    }
	else if (string[0] == 'S' && string[1] == 'O')
    {
        check_dublicate(game->texture_path.south, game);
		game->texture_path.south = ft_strdup(path);
    }
	else if (string[0] == 'W' && string[1] == 'E')
    {
        check_dublicate(game->texture_path.west, game);
		game->texture_path.west = ft_strdup(path);
    }
	else if (string[0] == 'E' && string[1] == 'A')
    {
        check_dublicate(game->texture_path.east, game);
		game->texture_path.east = ft_strdup(path);
    }
}
