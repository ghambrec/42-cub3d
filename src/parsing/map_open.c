/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:12:43 by rstumpf           #+#    #+#             */
/*   Updated: 2025/09/08 13:52:53 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int len_y;
	int	len_x;
	int max_width;

	len_y = 0;
	max_width = 0;
	while (game->map.map2d[len_y])
	{
		len_x = ft_strlen(game->map.map2d[len_y]);
		if (len_x > max_width)
			max_width = len_x;
		len_y++;
	}
	game->map.max_width = max_width;
	game->map.max_height = len_y;
}
