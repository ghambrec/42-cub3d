/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:31:07 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/05 11:31:12 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// paints the whole minimap image in WALL color
void	paint_background(t_game *game)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < game->minimap.height)
	{
		j = 0;
		while (j < game->minimap.width)
		{
			put_pixel_safe(game->img_minimap, j, i, get_tile_color(MV_WALL));
			j++;
		}
		i++;
	}
}
