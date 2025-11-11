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

// raycasting calculation
// raycasting draw
// paint minimap player (so that he is above the rays)
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

		// untextured
		uint32_t color = 0xB22222FF;
		if (ray.side == 1) color = 0x730909FF;
		draw_stripe(game->img_game, x, ray.draw_start, ray.draw_end, color);

		x++;
	}
	paint_player(game);
}

