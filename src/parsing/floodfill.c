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
		exit_failure(game, "Map is not surrounded by Walls");
	if (game->map.map2d[y][x] == 'E' || game->map.map2d[y][x] == 'N' || game->map.map2d[y][x] == 'S'
		|| game->map.map2d[y][x] == 'W')
	{
		game->player.player_count++;
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
		i = 0;
		while (i < ft_strlen(game->map.map2d_copy[y]))
		{
			if (game->map.map2d_copy[y][i] == '0')
				flood_fill(i, y, game);
			i++;
		}
		y++;
	}
	if (game->player.player_count != 0)
		exit_failure(game, "Invalid number of players");
	return (1);
}
