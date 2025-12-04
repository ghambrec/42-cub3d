#include "cub3d.h"

void	turn_with_mouse(t_game *game)
{
	int		center_x;
	int		mouse_pos_x;
	int		mouse_pos_y;
	int		delta_x;
	double	angle;

	center_x = GAME_SCREEN_WIDTH / 2;
	mlx_get_mouse_pos(game->mlx, &mouse_pos_x, &mouse_pos_y);
	delta_x = mouse_pos_x - center_x;
	if (delta_x > -2 && delta_x < 2)
    	delta_x = 0;
	angle = delta_x * MV_MOUSE_SENS;
	if (delta_x < 0)
		turn_left(game, fabs(angle));
	else if (delta_x > 0)
		turn_right(game, angle);
	mlx_set_mouse_pos(game->mlx, GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGTH / 2);
}

void	turn_left(t_game *game, double rotation)
{
	t_vector	old_dir;
	t_vector	old_plane;

	old_dir = game->player.dir;
	game->player.dir.x = old_dir.x * cos(-rotation) - old_dir.y * sin(-rotation);
	game->player.dir.y = old_dir.x * sin(-rotation) + old_dir.y * cos(-rotation);
	old_plane = game->player.plane;
	game->player.plane.x = old_plane.x * cos(-rotation) - old_plane.y * sin(-rotation);
	game->player.plane.y = old_plane.x * sin(-rotation) + old_plane.y * cos(-rotation);
}

void	turn_right(t_game *game, double rotation)
{
	t_vector	old_dir;
	t_vector	old_plane;

	old_dir = game->player.dir;
	game->player.dir.x = old_dir.x * cos(rotation) - old_dir.y * sin(rotation);
	game->player.dir.y = old_dir.x * sin(rotation) + old_dir.y * cos(rotation);
	old_plane = game->player.plane;
	game->player.plane.x = old_plane.x * cos(rotation) - old_plane.y * sin(rotation);
	game->player.plane.y = old_plane.x * sin(rotation) + old_plane.y * cos(rotation);
}
