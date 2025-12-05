/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:30:14 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/05 11:31:04 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_tile_color(char key)
{
	if (key == MV_WALL)
		return (CMM_WALL);
	if (key == MV_FLOOR)
		return (CMM_FLOOR);
	if (key == MV_SPACE)
		return (CMM_FLOOR);
	if (key == MV_PLAYER)
		return (CMM_FLOOR);
	return (CMM_WALL);
}

void	put_pixel_safe(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color)
{
	if ((unsigned)x < img->width && (unsigned)y < img->height)
		mlx_put_pixel(img, x, y, color);
}
