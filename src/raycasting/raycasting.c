#include "cub3d.h"

static void draw_stripe(mlx_image_t *img, int x, int y0, int y1, uint32_t color)
{
    // if ((unsigned)x >= img->width) return;
    if (y0 < 0) y0 = 0;
    if (y1 >= (int)img->height) y1 = (int)img->height - 1;

    int y = y0;
    while (y <= y1) {
        mlx_put_pixel(img, x, y, color);
        y++;
    }
}


// calc ray_direction
// calc delta_dist
void	calc_basic_params(t_game *game, t_ray *ray, int x)
{
	double		camera_x;
	t_vector	pos;

	camera_x = 2 * x / (double)GAME_SCREEN_WIDTH - 1;
	ray->ray_dir.x = game->player.dir.x + game->player.plane.x * camera_x;
	ray->ray_dir.y = game->player.dir.y + game->player.plane.y * camera_x;
	pos = game->player.pos;
	ray->map_box = (t_position){(int)pos.x, (int)pos.y};
	ray->delta_dist = (t_vector){1e30, 1e30};
	if (ray->ray_dir.x != 0)
		ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	if (ray->ray_dir.y != 0)
		ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
}

// calc step and side_dist for dda
void	calc_dda_params(t_game *game, t_ray *ray)
{
	t_vector	pos;

	pos = game->player.pos;
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (pos.x - ray->map_box.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_box.x + 1.0 - pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (pos.y - ray->map_box.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_box.y + 1.0 - pos.y) * ray->delta_dist.y;
	}
}

// perform dda
void	calc_dda(t_game *game, t_ray *ray)
{
	int			hit;

	hit = 0;
	while (hit == 0)
	{
		// jump to next map box, either in x or in y dir
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_box.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_box.y += ray->step.y;
			ray->side = 1;
		}
		if (game->map.map2d[ray->map_box.y][ray->map_box.x] == '1')
		{
			hit = 1;
		}
	}	
}

// calc X-Hit in texture on which the ray is shooting (between 0 and 1)
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
			ray->texture_key = T_EAST;
		else
			ray->texture_key = T_WEST;
	}
	else
	{
		if (ray->ray_dir.y > 0)
			ray->texture_key = T_SOUTH;
		else
			ray->texture_key = T_NORTH;
	}
}

// calc perpenducular distance from the camera plane to hitted wall
// calc height of the line to draw
// calc draw start y and draw end y
void	calc_draw_params(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	ray->line_height = (int)(GAME_SCREEN_HEIGTH / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + GAME_SCREEN_HEIGTH / 2;
	if(ray->draw_start < 0)ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + GAME_SCREEN_HEIGTH / 2;
	if(ray->draw_end >= GAME_SCREEN_HEIGTH)ray->draw_end = GAME_SCREEN_HEIGTH - 1;
}


// calculation steps
// [1] calc basic params
// [2] calc dda params
// [3] calc dda
// [4] calc draw params
// [5] calc texture stuff
void	calc_rays(t_game *game, t_ray *ray, int x)
{
	calc_basic_params(game, ray, x);
	calc_dda_params(game, ray);
	calc_dda(game, ray);
	calc_draw_params(ray);
	calc_texture_stuff(game, ray);

	// untextured
	uint32_t color = 0xB22222FF;
	if (ray->side == 1) color = 0x730909FF;
	draw_stripe(game->img_game, x, ray->draw_start, ray->draw_end, color);
}

void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	// pro Bildschirmspalte (x)
	while (x < GAME_SCREEN_WIDTH)
	{
		calc_rays(game, &ray, x);
		draw_minimap_rays(game, x, &ray);
		// draw_rays(game, &ray, x);
		x++;
	}
}

