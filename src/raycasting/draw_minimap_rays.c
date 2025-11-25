#include "cub3d.h"

// Bresenham Algo
static void bresenham(mlx_image_t *img, int x0, int y0, int x1, int y1, uint32_t color)
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

void	draw_minimap_rays(t_game *game, int i, t_ray *ray)
{
	if (i % 5 == 0)
	{
		t_position  start;
		t_position  end;

		start.x = game->player.pos.x * game->minimap.tile_size + game->minimap.off_x;
		start.y = game->player.pos.y * game->minimap.tile_size + game->minimap.off_y;
		end.x = start.x + ray->ray_dir.x * ray->perp_wall_dist * game->minimap.tile_size;
		end.y = start.y + ray->ray_dir.y * ray->perp_wall_dist * game->minimap.tile_size;
		bresenham(game->img_minimap, start.x, start.y, end.x, end.y, CMM_RAYS);
	}
}
