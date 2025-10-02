/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:13:19 by rstumpf           #+#    #+#             */
/*   Updated: 2025/10/02 13:47:30 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	flood_fill(int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->map.max_width || y >= game->map.max_height)
	{
		ft_putstr_fd("Map is invalid! Not closed/surrounded by walls\n", 2);
		clean_game(game);
		exit(EXIT_FAILURE);
	}
	if (game->map.map2d_copy[y][x] == '1')
		return (0);
	game->map.map2d_copy[y][x] = '1';
	flood_fill(x + 1, y, game);
	flood_fill(x - 1, y, game);
	flood_fill(x, y + 1, game);
	flood_fill(x, y - 1, game);
	return (0);
}

int	floodfill_validation(t_game *game)
{
	size_t		i;
	int			y;

	flood_fill(game->player.pos1D.x, game->player.pos1D.y, game);
	i = 0;
	y = 0;
	while (game->map.map2d_copy[y] != NULL)
	{
		while (i < ft_strlen(game->map.map2d_copy[y]))
		{
			if (game->map.map2d_copy[y][i] == '0')
				flood_fill(y, i, game);
			i++;
			}
		y++;
	}
	// printf("Map 2D Copy after Floodfill:\n");
	// ft_print2d(game->map.map2d_copy);
	ft_str2d_free(game->map.map2d_copy);
	return (1);
}
