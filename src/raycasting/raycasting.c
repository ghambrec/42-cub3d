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

void	calc_draw_params(t_game *game, t_ray *ray, int x)
{

	// calc perpenducular distance from the camera plane to hitted wall
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;

	draw_minimap_rays(game, x, ray->ray_dir, ray->perp_wall_dist);



	// X-Treffpunkt im texture auf das der ray geht (zwischen 0-1)
	double texture_x;
	if (ray->side == 0)
		texture_x = game->player.pos.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		texture_x = game->player.pos.x + ray->perp_wall_dist * ray->ray_dir.x;
	texture_x = texture_x - floor(texture_x);


	// texture bestimmen auf die der ray geht
	int texture_key;

	if (ray->side == 0) // vertikal
	{
		if (ray->ray_dir.x > 0)
			texture_key = T_EAST;
		else
			texture_key = T_WEST;
	}
	else // horizontal
	{
		if (ray->ray_dir.y > 0)
			texture_key = T_SOUTH;
		else
			texture_key = T_NORTH;
	}
	mlx_texture_t *texture = game->textures[texture_key];


	

	// berechne hoehe der line
	int lineHeight = (int)(GAME_SCREEN_HEIGTH / ray->perp_wall_dist);
	// berechne hoechsten und niedrigsten pixel fuer aktuelle spalte
	int drawStart = -lineHeight / 2 + GAME_SCREEN_HEIGTH / 2;
	if(drawStart < 0)drawStart = 0;
	int drawEnd = lineHeight / 2 + GAME_SCREEN_HEIGTH / 2;
	if(drawEnd >= GAME_SCREEN_HEIGTH)drawEnd = GAME_SCREEN_HEIGTH - 1;


	// if (x == 1)
	// {
	// 	printf("x[%i] texture_x[%f] t_key[%i]\n", x, texture_x, texture_key);
	// }



	uint32_t color = 0xB22222FF;
	if (ray->side == 1) color = 0x730909FF;
	draw_stripe(game->img_game, x, drawStart, drawEnd, color);
}

void	calc_rays(t_game *game, t_ray *ray, int x)
{


	// steps berechnung:
	// [1] calc basic params
	calc_basic_params(game, ray, x);
	// [2] calc dda params
	calc_dda_params(game, ray);
	// [3] calc dda
	calc_dda(game, ray);
	// [4] calc draw params
	calc_draw_params(game, ray, x);





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
		// draw_minimap_rays(game, x, &ray); // hierher auslagern
		// draw_rays(game, &ray, x);
		x++;
	}
}

