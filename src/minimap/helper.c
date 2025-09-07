#include "cub3d.h"

uint32_t	get_tile_color(char key)
{
	if (key == MV_WALL)
		return (CMM_WALL);
	if (key == MV_FLOOR)
		return (CMM_FLOOR);
	if (key == MV_PLAYER)
		return (CMM_FLOOR);
	return (CMM_WALL);
}

void	put_pixel_safe(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color)
{
    if ((unsigned)x < image->width && (unsigned)y < image->height)
		mlx_put_pixel(image, x, y, color);
}
