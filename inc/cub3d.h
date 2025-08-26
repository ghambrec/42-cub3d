/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:53:44 by rstumpf           #+#    #+#             */
/*   Updated: 2025/08/26 15:24:07 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "../lib/myLibft/include/my_libft.h"
# include "../lib/mlx/include/MLX42/MLX42.h"
# include <math.h>

// COLORS
# define BLACK 0x000000FF
# define RED 0xFF0000FF
# define GREY 0x808080FF

// GAME
# define GAME_SIZE_WIDTH 1920
# define GAME_SIZE_HIGH 1080

// MINIMAP
# define MM_MIN_SIZE 512
# define MM_TILE 32
# define MM_PLAYER_SIZE 8


typedef struct s_game
{
	mlx_t	*mlx;
} t_game;

typedef enum e_map_values
{
	MV_WALL = '1',
	MV_FLOOR = '0',
	MV_PLAYER_NORTH = 'P'
}	t_map_values;

typedef struct s_map_info
{
	char	*map_name;
	char	*map_string;
	
} t_map_info;

void	arg_validation(char **argv, int n);
void	map_validation(t_map_info *map_info);
void	char_validation(char *map);
void	map_open(t_map_info *map_info);


#endif
