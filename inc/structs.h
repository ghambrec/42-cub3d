#ifndef STRUCTS_H
#define STRUCTS_H

#include "../lib/mlx/include/MLX42/MLX42.h"

typedef struct s_game
{
	mlx_t	*mlx;
} t_game;


typedef struct s_map_info
{
	char	*map_name;
	char	*map_string;
	
} t_map_info;

#endif