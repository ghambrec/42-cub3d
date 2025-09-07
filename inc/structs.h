#ifndef STRUCTS_H
#define STRUCTS_H

#include "../lib/mlx/include/MLX42/MLX42.h"

// player in **map auf 'P' setzen
// position und blickrichtung des players in t_player speichern
// position = **map position + 0.5 (x und y)
// maximalste breite und hoehe der minimap speichern in t_minimap.max_...

// blickrichtungen:
// north: x=0, y=-1
// east:  x=1, y=0
// south: x=0, y=1
// west:  x=-1, y=0

typedef struct s_position2D
{
	double x;
	double y;
} t_position2D;

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
	int			max_width;
	int			max_height;
} t_minimap;

typedef struct	s_player
{
	t_position2D	pos;
	t_position2D	dir;
} t_player;

typedef struct s_map_info
{
	char	*map_name;
	char	*map_string;	
	char	**map2d;
	char	**map2d_copy;
} t_map_info;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img_game;
	mlx_image_t		*img_minimap;
	t_minimap		minimap;
	t_player		player;
	t_map_info		map;
} t_game;

typedef struct s_size
{
	uint32_t	width;
	uint32_t	height;
} t_size;


#endif