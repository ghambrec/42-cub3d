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


// void	calc_ray_direction(t_game *game, t_ray *ray, int x)
// {

// }

void	calc_rays(t_game *game, t_ray *ray, int x)
{
	// ############################ OLD
	double 		camera_x;
	t_vector	ray_dir;
	t_vector	pos;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		perp_wall_dist;
	t_position	step;
	int			hit;
	int			side;
	t_position	map_box;
	// ############################ OLD END


	// steps berechnung:
	// [1] calc ray direction
	// [2] calc dda params
	// [3] calc dda
	// [4] calc draw params

	camera_x = 2 * x / (double)GAME_SCREEN_WIDTH - 1;
	// ray direction
	ray_dir.x = game->player.dir.x + game->player.plane.x * camera_x;
	ray_dir.y = game->player.dir.y + game->player.plane.y * camera_x;

	// current player position
	pos = game->player.pos;
	// current map box
	map_box = (t_position){(int)game->player.pos.x, (int)game->player.pos.y};

	// calc delta_dist
	delta_dist = (t_vector){1e30, 1e30};
	if (ray_dir.x != 0)
		delta_dist.x = fabs(1 / ray_dir.x);
	if (ray_dir.y != 0)
		delta_dist.y = fabs(1 / ray_dir.y);

	// calc step and side_dist for the DDA
	// x
	if (ray_dir.x < 0)
	{
		step.x = -1;
		side_dist.x = (pos.x - map_box.x) * delta_dist.x;
	}
	else
	{
		step.x = 1;
		side_dist.x = (map_box.x + 1.0 - pos.x) * delta_dist.x;
	}
	// y
	if (ray_dir.y < 0)
	{
		step.y = -1;
		side_dist.y = (pos.y - map_box.y) * delta_dist.y;
	}
	else
	{
		step.y = 1;
		side_dist.y = (map_box.y + 1.0 - pos.y) * delta_dist.y;
	}


	// perform DDA
	hit = 0;
	while (hit == 0)
	{
		// jump to next map box, either in x or in y dir
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			map_box.x += step.x;
			side = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			map_box.y += step.y;
			side = 1;
		}
		if (game->map.map2d[map_box.y][map_box.x] == '1')
		{
			hit = 1;
		}
	}





	// calc perpenducular distance from the camera plane to hitted wall
	if (side == 0)
		perp_wall_dist = side_dist.x - delta_dist.x;
	else
		perp_wall_dist = side_dist.y - delta_dist.y;

	draw_minimap_rays(game, x, ray_dir, perp_wall_dist);





	// X-Treffpunkt im texture auf das der ray geht (zwischen 0-1)
	double texture_x;
	if (side == 0)
		texture_x = pos.y + perp_wall_dist * ray_dir.y;
	else
		texture_x = pos.x + perp_wall_dist * ray_dir.x;
	texture_x = texture_x - floor(texture_x);





	// texture bestimmen auf die der ray geht
	int texture_key;

	if (side == 0) // vertikal
	{
		if (ray_dir.x > 0)
			texture_key = T_EAST;
		else
			texture_key = T_WEST;
	}
	else // horizontal
	{
		if (ray_dir.y > 0)
			texture_key = T_SOUTH;
		else
			texture_key = T_NORTH;
	}
	mlx_texture_t *texture = game->textures[texture_key];


	

	// berechne hoehe der line
	int lineHeight = (int)(GAME_SCREEN_HEIGTH / perp_wall_dist);
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
	if (side == 1) color = 0x730909FF;
	draw_stripe(game->img_game, x, drawStart, drawEnd, color);
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

