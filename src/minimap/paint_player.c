/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:32:15 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/05 11:33:30 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// player pos = (tile_size * player_pos) + offset
void	paint_player(t_game *gme)
{
	t_position	pos;
	int			size;
	int			radius;
	int			x;
	int			y;

	if (!gme->minimap.mm_exist)
		return ;
	pos.x = (gme->player.pos.x * gme->minimap.tile_size) + gme->minimap.off_x;
	pos.y = (gme->player.pos.y * gme->minimap.tile_size) + gme->minimap.off_y;
	size = gme->minimap.tile_size / MM_PLAYER_SIZE;
	radius = size / 2;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			put_pixel_safe(gme->img_minimap, \
pos.x - radius + x, pos.y - radius + y, CMM_PLAYER);
			x++;
		}
		y++;
	}
}
