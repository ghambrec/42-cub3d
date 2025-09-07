/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:12:43 by rstumpf           #+#    #+#             */
/*   Updated: 2025/08/27 17:45:14 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player_pos(t_game *game)
{
	size_t	i;
	int		y;

	i = 0;
	y = 0;
	while (game->map.map2d[y])
	{
		i = 0;
		while (i < ft_strlen(game->map.map2d[y]))
		{
			if (game->map.map2d[y][i] == 'N' || game->map.map2d[y][i] == 'E'
				|| game->map.map2d[y][i] == 'S' || game->map.map2d[y][i] == 'W')
			{
				game->player.pos.x = i;
				game->player.pos.y = y;
				return ;
			}
			i++;
		}
		y++;
	}
	return ;
}

void	create_map(t_game *game)
{
	game->map.map2d = ft_split(game->map.map_string, '\n');
	game->map.map2d_copy = ft_split(game->map.map_string, '\n');
}

void	map_open(t_map_info *map_info)
{
	int		fd;
	char	*temp;
	char	*line;

	fd = open(map_info->map_name, O_RDONLY);
	map_info->map_string = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin_gnl(map_info->map_string, line);
		free(line);
		free(map_info->map_string);
		map_info->map_string = ft_strdup(temp);
		free(temp);
	}
	close(fd);
	return ;
}

void	get_map_width_height(t_game *game)
{
	int y = 0;
	int max_width = 0;

	while (game->map.map2d[y])
	{
		int len = ft_strlen(game->map.map2d[y]);
		if (len > max_width)
			max_width = len;
		y++;
	}
	game->map.width = max_width;
	game->map.height = y;
}
