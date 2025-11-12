#include "cub3d.h"

// calc x-hit in texture on which the ray is shooting (between 0 and 1)
// calc texture on which the ray is shooting
void	calc_texture_stuff(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->texture_x = game->player.pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		ray->texture_x = game->player.pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	ray->texture_x = ray->texture_x - floor(ray->texture_x);

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
