/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:38:24 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/05 12:22:39 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../lib/mlx/include/MLX42/MLX42.h"

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_minimap
{
	uint32_t	width;
	uint32_t	height;
	int			tile_size;
	int			off_x;
	int			off_y;
	bool		mm_exist;
}	t_minimap;

typedef struct s_player
{
	t_position	pos1d;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	int			player_count;
}	t_player;

typedef struct s_map_info
{
	char		*map_name;
	char		*map_string;	
	char		**map2d;
	char		**map2d_copy;
	int			max_width;
	int			max_height;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
}	t_map_info;

typedef struct s_size
{
	uint32_t	width;
	uint32_t	height;
}	t_size;

typedef struct s_textures_path
{
	char	*north;
	char	*east;
	char	*south;
	char	*west;
	bool	is_double;
}	t_textures_path;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img_game;
	mlx_image_t		*img_minimap;
	t_minimap		minimap;
	t_player		player;
	t_map_info		map;
	t_textures_path	texture_path;
	mlx_texture_t	*textures[4];
}	t_game;

typedef struct s_ray
{
	t_vector		ray_dir;
	t_position		map_box;
	t_vector		delta_dist;
	t_position		step;
	t_vector		side_dist;
	double			perp_wall_dist;
	int				side;
	double			wall_x;
	mlx_texture_t	*texture;
	int				line_height;
	int				draw_start;
	int				draw_end;
}	t_ray;

typedef struct s_bresenham
{
	t_position	*start;
	t_position	*end;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}	t_bresenham;

#endif
