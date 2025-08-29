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
