#ifndef STRUCTS_H
#define STRUCTS_H

#include "../lib/mlx/include/MLX42/MLX42.h"

// player in minimap aiuf P setzen und blickrichtung in dem eigenen player struct speichern

typedef struct s_position2d
{
	double x;
	double y;
} t_position2d;

typedef struct s_position
{
	int x;
	int y;
} t_position;

typedef struct s_minimap
{
	uint32_t	width;
	uint32_t	height;
	int			tile_size;
	int			off_x;
	int			off_y;
} t_minimap;

typedef struct	s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
} t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img_game;
	mlx_image_t		*img_minimap;
	char			**map;
	int				map_max_width;
	int				map_max_height;
	t_minimap		minimap;
	t_player		player;
} t_game;

typedef struct s_map_info
{
	char	*map_name;
	char	*map_string;	
} t_map_info;

typedef struct s_size
{
	uint32_t	width;
	uint32_t	height;
} t_size;


#endif