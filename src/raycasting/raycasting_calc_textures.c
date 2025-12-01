/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calc_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:10:16 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/01 10:11:16 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// calc x-hit in texture on which the ray is shooting
//		(between 0 (left) and 1 (right))
// calc texture on which the ray is shooting
void	calc_texture_stuff(t_game *g, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = g->player.pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		ray->wall_x = g->player.pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
	ray->wall_x = 1.0 - ray->wall_x;
	if (ray->side == 0)
	{
		if (ray->ray_dir.x > 0)
			ray->texture = g->textures[T_EAST];
		else
			ray->texture = g->textures[T_WEST];
	}
	else
	{
		if (ray->ray_dir.y > 0)
			ray->texture = g->textures[T_SOUTH];
		else
			ray->texture = g->textures[T_NORTH];
	}
}
