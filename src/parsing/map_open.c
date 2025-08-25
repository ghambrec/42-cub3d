/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:12:43 by rstumpf           #+#    #+#             */
/*   Updated: 2025/08/25 17:17:05 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_open(t_map_info *map_info)
{
	int		fd;
	char	*temp;
	char	*line;

	fd = open(map_info->map_name, O_RDONLY);
	map_info->map_string = ft_strjoin("", "");
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
}
