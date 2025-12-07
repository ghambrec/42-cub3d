/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:35:46 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/07 13:26:15 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "../lib/myLibft/include/my_libft.h"
# include "structs.h"

// HELPER
void		ft_print2d(char **str2d);
void		fill_ceil_floor(t_game *game);
void		render_game(t_game *game);

// INIT
void		init_game(t_game *game);
void		init_mlx(t_game *game);
void		init_hooks(t_game *game);

// PARSING
void		arg_validation(char **argv, int n);
void		map_validation(t_game *game);
void		char_validation(t_game *game);
void		map_open(t_game *game);
int			floodfill_validation(t_game *game);
void		create_map(t_game *game);
void		get_player_pos(t_game *game);
void		get_map_width_height(t_game *game);
int			is_texture_line(char *line);
void		copy_texture_paths(char *texture_path_string, t_game *game);
uint32_t	*parse_color(char *line, t_game *game);
void		parse_rgbs(char *string, t_game *game);
void		parse_textures(char *string, char *path, t_game *game);
void		create_map_string(t_game *game, int fd);
int			is_map_line(char *line);

// EXIT
void		exit_success(t_game *game);
void		exit_failure(t_game *game, char *msg);
void		clean_game(t_game *game);

// HOOKS
void		key_hook(mlx_key_data_t keydata, void *param);
void		resize_hook(int32_t width, int32_t height, void *param);
void		loop_hook(void *param);
void		handle_resize(t_game *game);

// MINIMAP
void		create_minimap(t_game *game);
void		paint_background(t_game *game);
void		paint_minimap(t_game *game);
void		paint_player(t_game *game);
uint32_t	get_tile_color(char mapval);
void		put_pixel_safe(mlx_image_t *img,\
								uint32_t x, uint32_t y, uint32_t color);

// MOVEMENT
void		turn_with_mouse(t_game *game);
void		turn_left(t_game *game, double rotation);
void		turn_right(t_game *game, double rotation);
void		walk_north(t_game *game);
void		walk_west(t_game *game);
void		walk_south(t_game *game);
void		walk_east(t_game *game);

// RAYCASTING
void		raycasting(t_game *game);
void		calc_rays(t_game *game, t_ray *ray, int x);
void		calc_texture_stuff(t_game *game, t_ray *ray);
void		draw_minimap_rays(t_game *game, int i, t_ray *ray);
void		draw_rays(t_game *game, t_ray *ray, int x);

#endif
