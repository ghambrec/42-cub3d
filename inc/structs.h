#ifndef STRUCTS_H
#define STRUCTS_H

#include "../lib/mlx/include/MLX42/MLX42.h"

typedef struct s_map_info
{
	char	*map_name;
	char	*map_string;
	char	**map2d;
	char	**map2d_copy;
} t_map_info;

typedef struct	s_player
{
	double		x;
	double		y;
} t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img_game;
	mlx_image_t		*img_minimap;
	t_map_info		map;
	t_player		player;
} t_game;

typedef struct s_size
{
	uint32_t	width;
	uint32_t	height;
} t_size;


#endif