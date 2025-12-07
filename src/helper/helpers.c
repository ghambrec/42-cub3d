/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:24:22 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/07 12:58:55 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print2d(char **str2d)
{
	int	i;

	i = 0;
	while (str2d[i])
	{
		printf("%s\n", str2d[i]);
		i++;
	}
	printf("\n");
}

// HEIGTH durch 2, obere haelfte ceil untere floor
void	fill_ceil_floor(t_game *game)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	*color;

	y = 0;
	while (y < GAME_SCREEN_HEIGTH)
	{
		if (y >= GAME_SCREEN_HEIGTH / 2)
			color = game->map.floor_color;
		else
			color = game->map.ceiling_color;
		x = 0;
		while (x < GAME_SCREEN_WIDTH)
		{
			mlx_put_pixel(game->img_game, x, y, *color);
			x++;
		}
		y++;
	}
}
