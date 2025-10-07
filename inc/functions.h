#ifndef FUNCTIONS_H
#define FUNCTIONS_H

# include "../lib/myLibft/include/my_libft.h"
# include "structs.h"

// HELPER
void	ft_print2d(char **str2d);

// PARSING
void	game_init(t_game *game);
void	arg_validation(char **argv, int n);
void	map_validation(t_game *game);
void	char_validation(char *map);
void	map_open(t_map_info *map_info);
int		floodfill_validation(t_game *game);
void	create_map(t_game *game);
void	get_player_pos(t_game *game);
void	get_map_width_height(t_game *game);

// EXIT
void	exit_success(t_game *game);
void	exit_failure(t_game *game, char *msg);
void	clean_game(t_game *game);

// HOOKS
void	key_hook(mlx_key_data_t keydata, void *param);
void	resize_hook(int32_t width, int32_t height, void *param);
void	loop_hook(void *param);

// MINIMAP
void		create_minimap(t_game *game);
void		paint_background(t_game *game);
void		paint_minimap(t_game *game);
void		paint_player(t_game *game);
void		paint_direction(t_game *game);
uint32_t	get_tile_color(char mapval);
void	put_pixel_safe(mlx_image_t *image, uint32_t x, uint32_t y, uint32_t color);

// MOVEMENT
void	turn_left(t_game *game);
void	turn_right(t_game *game);
void	walk_north(t_game *game);
void	walk_west(t_game *game);
void	walk_south(t_game *game);
void	walk_east(t_game *game);

// RAYCASTING
void	raycasting(t_game *game);
void	draw_minimap_rays(t_game *game, int i, t_vector ray_dir, double perp_wall_dist);
void	draw_minimap_rays_old(mlx_image_t *img, int x0, int y0, int x1, int y1, uint32_t color);


#endif