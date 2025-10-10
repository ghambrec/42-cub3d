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


// HEIGTH durch 2, obere haelfte ceil untere floor
void	fill_ceil_floor(t_game *game)
{
	uint32_t x;
	uint32_t y;
	uint32_t color;

	y = 0;
	while (y < GAME_SCREEN_HEIGTH)
	{
		if (y >= GAME_SCREEN_HEIGTH / 2)
			color = FLOOR;
		else
			color = CEIL;
		x = 0;
		while (x < GAME_SCREEN_WIDTH)
		{
			mlx_put_pixel(game->img_game, x, y, color);
			x++;
		}
		y++;
	}
}


void	raycasting(t_game *game)
{
	double 		camera_x;
	t_vector	ray_dir;
	int			x;
	t_vector	pos;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		perp_wall_dist;
	t_position	step;
	int			hit;
	int			side;
	t_position	map_box;

	fill_ceil_floor(game);

	x = 0;
	// pro Bildschirmspalte (x)
	while (x < GAME_SCREEN_WIDTH)
	{
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

		// calc perpenducular distance from the camera plaen to hitted wall
		if (side == 0)
			perp_wall_dist = side_dist.x - delta_dist.x;
		else
			perp_wall_dist = side_dist.y - delta_dist.y;


		draw_minimap_rays(game, x, ray_dir, perp_wall_dist);

		// berechne hoehe der line
		int lineHeight = (int)(GAME_SCREEN_HEIGTH / perp_wall_dist);
		// berechne hoechsten und niedrigsten pixel fuer aktuelle spalte
		int drawStart = -lineHeight / 2 + GAME_SCREEN_HEIGTH / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + GAME_SCREEN_HEIGTH / 2;
		if(drawEnd >= GAME_SCREEN_HEIGTH)drawEnd = GAME_SCREEN_HEIGTH - 1;

		uint32_t color = 0xB22222FF;
		if (side == 1) color = 0x730909FF;
		draw_stripe(game->img_game, x, drawStart, drawEnd, color);

		x++;
	}
}

