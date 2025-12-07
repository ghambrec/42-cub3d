/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:12:43 by rstumpf           #+#    #+#             */
/*   Updated: 2025/12/07 13:30:23 by rstumpf          ###   ########.fr       */
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

	fd = 0;
	if (game->map.map_name)
		fd = open(game->map.map_name, O_RDONLY);
	if (fd == -1)
		exit_failure(game, "File doesnt exist!");
	game->map.map_string = ft_strdup("");
	create_map_string(game, fd);
	if (game->texture_path.is_double == true)
		exit_failure(game, "Double Texture Paths are not allowed");
	close(fd);
	return ;
}

void	copy_texture_paths(char *texture_path_string, t_game *game)
{
	char	*dot;
	char	*path;
	int		len;

	parse_rgbs(texture_path_string, game);
	if (texture_path_string[0] == 'F' || texture_path_string[0] == 'C')
		return;
	dot = ft_strchr(texture_path_string, '.');
	if (dot == NULL)
		return;
	len = 0;
	while (dot[len] && dot[len] != '\n')
		len++;
	path = ft_substr(dot, 0, len);
	parse_textures(texture_path_string, path, game);
	free(path);
}


void	get_map_width_height(t_game *game)
{
	int	len_y;
	int	len_x;
	int	max_width;

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
	if (game->map.max_width < 3 || game->map.max_height < 3)
		exit_failure(game, "map is to small");
}

void	create_map_string(t_game *game, int fd)
{
	char	*line;
	char	*temp;
	bool	map_started;

	map_started = false;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return ;
		if (is_map_line(line))
			map_started = true;
		if (is_texture_line(line))
		{
			if (map_started == true)
				exit_failure(game, "Map started before all textures and color are set!");
			copy_texture_paths(line, game);
			free(line);
			continue ;
		}
		temp = ft_strjoin(game->map.map_string, line);
		free(line);
		free(game->map.map_string);
		game->map.map_string = ft_strdup(temp);
		free(temp);
			
	}
}