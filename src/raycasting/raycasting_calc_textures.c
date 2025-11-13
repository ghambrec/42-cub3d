#include "cub3d.h"

// calc x-hit in texture on which the ray is shooting (between 0 (left) and 1 (right))
// calc texture on which the ray is shooting
void	calc_texture_stuff(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->wall_x = game->player.pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		ray->wall_x = game->player.pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	ray->wall_x = ray->wall_x - floor(ray->wall_x);
	ray->wall_x = 1.0 - ray->wall_x;

	if (ray->side == 0)
	{
		if (ray->ray_dir.x > 0)
			ray->texture = game->textures[T_EAST];
		else
			ray->texture = game->textures[T_WEST];
	}
	else
	{
		if (ray->ray_dir.y > 0)
			ray->texture = game->textures[T_SOUTH];
		else
			ray->texture = game->textures[T_NORTH];
	}
}
