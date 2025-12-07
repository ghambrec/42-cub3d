/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:12:42 by rstumpf          #+#    #+#             */
/*   Updated: 2025/12/08 15:12:42 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '1' || *line == '0'
		|| *line == 'N' || *line == 'S'
		|| *line == 'E' || *line == 'W')
		return (1);
	return (0);
}

static void	process_texture_line(char *line, t_game *game, bool map_started)
{
	if (map_started)
		game->texture_path.map_started_to_early = true;
	copy_texture_paths(line, game);
}

static void	process_map_line(char *line, t_game *game)
{
	char	*temp;

	temp = ft_strjoin(game->map.map_string, line);
	free(game->map.map_string);
	game->map.map_string = ft_strdup(temp);
	free(temp);
}

void	create_map_string(t_game *game, int fd)
{
	char	*line;
	bool	map_started;

	map_started = false;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		if (is_map_line(line))
			map_started = true;
		if (is_texture_line(line))
		{
			process_texture_line(line, game, map_started);
			free(line);
			continue ;
		}
		process_map_line(line, game);
		free(line);
	}
}
