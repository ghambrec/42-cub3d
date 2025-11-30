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

void	map_open(t_game *game)
{
	int		fd;
	char	*temp;
	char	*line;

	fd = open(game->map.map_name, O_RDONLY);
	game->map.map_string = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_texture_line(line))
		{
			copy_texture_paths(line, game);
			continue ;
		}
		temp = ft_strjoin_gnl(game->map.map_string, line);
		free(line);
		free(game->map.map_string);
		game->map.map_string = ft_strdup(temp);
		free(temp);
	}
	close(fd);
	return ;
}

void	copy_texture_paths(char *texture_path_string, t_game *game)
{
	char	*dot;
	char	*path;
	int		len;

	if (texture_path_string[0] == 'F' && texture_path_string[1] == ' ')
	{
		game->map.floor_color = ft_substr(texture_path_string, 2, 
			ft_strlen(texture_path_string) - 3);
		return ;
	}
	if (texture_path_string[0] == 'C' && texture_path_string[1] == ' ')
	{
		game->map.ceiling_color = ft_substr(texture_path_string, 2, 
			ft_strlen(texture_path_string) - 3);
		return ;
	}
	dot = ft_strchr(texture_path_string, '.');
	if (dot == NULL)
		return ;
	len = 0;
	while (dot[len] && dot[len] != '\n')
		len++;
	path = ft_substr(dot, 0, len);
	if (texture_path_string[0] == 'N' && texture_path_string[1] == 'O')
		game->texture_path.north = path;
	else if (texture_path_string[0] == 'S' && texture_path_string[1] == 'O')
		game->texture_path.south = path;
	else if (texture_path_string[0] == 'W' && texture_path_string[1] == 'E')
		game->texture_path.west = path;
	else if (texture_path_string[0] == 'E' && texture_path_string[1] == 'A')
		game->texture_path.east = path;
	else
		free(path);
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
