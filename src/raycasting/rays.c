#include "cub3d.h"


void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, uint32_t color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_put_pixel(img, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx)  { err += dx; y0 += sy; }
    }
}


void	raycasting(t_game *game)
{
	double 		camera_x;
	t_vector	ray_dir;
	int			i;
	t_vector	pos;
	t_vector	side_dist;
	t_vector	delta_dist;
	double		perp_wall_dist;
	t_position	step;
	int			hit;
	int			side;
	t_position	map_box;

	i = 0;
	while (i < GAME_SCREEN_WIDTH)
	{
		camera_x = 2 * i / (double)GAME_SCREEN_WIDTH - 1;
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

		// debugging
		// if (i == 0 || i == 1919)
		if (true)
		{
			// printf("--------------------\n");
			// printf("i=%i\nray_dir: %f, %f\n", i, ray_dir.x, ray_dir.y);
			// printf("step: %i, %i\n", step.x, step.y);
			// printf("side_dist: %f, %f\n", side_dist.x, side_dist.y);
			// printf("delta_dist: %f, %f\n", delta_dist.x, delta_dist.y);
			// printf("map: %i, %i\n", map_box.x, map_box.y);

		


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
				ft_putendl_fd("HIT!", STDOUT_FILENO);
				hit = 1;
			}
		}

		// calc perpenducular distance from the camera plaen to the hitted wall
		if (side == 0)
			perp_wall_dist = side_dist.x - delta_dist.x;
		else
			perp_wall_dist = side_dist.y - delta_dist.y;

		// printf("--------------------\n");
		// printf("i=%i\nray_dir: %f, %f\n", i, ray_dir.x, ray_dir.y);
		// printf("perp_dist %f\n", perp_wall_dist);
		// printf("step: %i, %i\n", step.x, step.y);
		// printf("side_dist: %f, %f\n", side_dist.x, side_dist.y);
		// printf("delta_dist: %f, %f\n", delta_dist.x, delta_dist.y);
		// printf("map: %i, %i\n", map_box.x, map_box.y);
		// printf("--------------------\n");

		if (i % 2 == 0)
		{
		// try to paint in minimap
		t_position start;
		t_position end;

		start.x = game->player.pos.x * game->minimap.tile_size + game->minimap.off_x;
		start.y = game->player.pos.y * game->minimap.tile_size + game->minimap.off_y;
		put_pixel_safe(game->img_minimap, start.x, start.y, WHITE);
		// printf("START: %i, %i\n", start.x, start.y);

		end.x = start.x + ray_dir.x * perp_wall_dist * game->minimap.tile_size;
		end.y = start.y + ray_dir.y * perp_wall_dist * game->minimap.tile_size;
		put_pixel_safe(game->img_minimap, end.x, end.y, BLACK);
		// printf("END  : %i, %i\n", end.x, end.y);
		draw_line(game->img_minimap, start.x, start.y, end.x, end.y, RED);
		}

	} // debugging end
		i++;
	}
}

