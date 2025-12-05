/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:42:01 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/05 12:22:28 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Bresenham Algo
static void	bresenham(mlx_image_t *img, t_bresenham *b, uint32_t color)
{
	int	e2;

	while (1)
	{
		mlx_put_pixel(img, b->start->x, b->start->y, color);
		if (b->start->x == b->end->x && b->start->y == b->end->y)
			break ;
		e2 = 2 * b->err;
		if (e2 > -b->dy)
		{
			b->err -= b->dy;
			b->start->x += b->sx;
		}
		if (e2 < b->dx)
		{
			b->err += b->dx;
			b->start->y += b->sy;
		}
	}
}

static void	calc_bresenham_params(t_bresenham *b)
{
	b->dx = abs(b->end->x - b->start->x);
	b->dy = abs(b->end->y - b->start->y);
	if (b->start->x < b->end->x)
		b->sx = 1;
	else
		b->sx = -1;
	if (b->start->y < b->end->y)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx - b->dy;
}

// s = start // e = end
void	draw_minimap_rays(t_game *g, int i, t_ray *ray)
{
	t_position	s;
	t_position	e;
	t_bresenham	b;

	if (i % 5 == 0)
	{
		if (!g->minimap.mm_exist)
			return ;
		s.x = g->player.pos.x * g->minimap.tile_size + g->minimap.off_x;
		s.y = g->player.pos.y * g->minimap.tile_size + g->minimap.off_y;
		e.x = s.x + ray->ray_dir.x * ray->perp_wall_dist * g->minimap.tile_size;
		e.y = s.y + ray->ray_dir.y * ray->perp_wall_dist * g->minimap.tile_size;
		b.start = &s;
		b.end = &e;
		calc_bresenham_params(&b);
		bresenham(g->img_minimap, &b, CMM_RAYS);
	}
}
