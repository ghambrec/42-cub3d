/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:18:32 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/05 11:42:54 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// calc x position in the texture
// reflect if necessary
static int	calc_texture_x(t_ray *ray)
{
	int	texture_x;

	texture_x = (int)(ray->wall_x * (double)ray->texture->width);
	if (texture_x < 0)
		texture_x = 0;
	if (texture_x >= (int)ray->texture->width)
		texture_x = (int)ray->texture->width - 1;
	if (ray->side == 0 && ray->ray_dir.x > 0)
		texture_x = ray->texture->width - texture_x - 1;
	if (ray->side == 1 && ray->ray_dir.y < 0)
		texture_x = ray->texture->width - texture_x - 1;
	return (texture_x);
}

// built byte array for color
static uint32_t	get_color(t_ray *ray, int texture_x, int texture_y)
{
	uint8_t	*pixels;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	size_t	idx;

	pixels = ray->texture->pixels;
	idx = ((size_t)texture_y * ray->texture->width + (size_t)texture_x) * 4;
	r = pixels[idx + 0];
	g = pixels[idx + 1];
	b = pixels[idx + 2];
	return ((r << 24) | (g << 16) | (b << 8) | pixels[idx + 3]);
}

void	draw_rays(t_game *game, t_ray *ray, int x)
{
	int		y;
	double	step;
	double	tex_pos_y;
	int		texture_y;
	int		texture_x;

	texture_x = calc_texture_x(ray);
	step = (double)ray->texture->height / (double)ray->line_height;
	tex_pos_y = (ray->draw_start - GAME_SCREEN_HEIGTH / 2.0 + \
ray->line_height / 2.0) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		texture_y = (int)tex_pos_y;
		tex_pos_y += step;
		if (texture_y < 0)
			texture_y = 0;
		if (texture_y >= (int)ray->texture->height)
			texture_y = (int)ray->texture->height - 1;
		mlx_put_pixel(game->img_game, x, y, \
get_color(ray, texture_x, texture_y));
		y++;
	}
}
