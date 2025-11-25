#include "cub3d.h"

// raycasting calculation
// raycasting draw
// paint minimap player (above the rays)
void	raycasting(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < GAME_SCREEN_WIDTH)
	{
		calc_rays(game, &ray, x);
		draw_minimap_rays(game, x, &ray);
		draw_rays(game, &ray, x);
		x++;
	}
	paint_player(game);
}
