/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:23:06 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/07 13:04:39 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_game(t_game *game)
{
	if (game->map.map_string)
		free(game->map.map_string);
	if (game->map.map2d)
	{
		ft_str2d_free(game->map.map2d);
		ft_str2d_free(game->map.map2d_copy);
	}
	if (game->texture_path.east)
		free(game->texture_path.east);
	if (game->texture_path.north)
		free(game->texture_path.north);
	if (game->texture_path.west)
		free(game->texture_path.west);
	if (game->texture_path.south)
		free(game->texture_path.south);
	if (game->textures[T_NORTH])
		mlx_delete_texture(game->textures[T_NORTH]);
	if (game->textures[T_EAST])
		mlx_delete_texture(game->textures[T_EAST]);
	if (game->textures[T_SOUTH])
		mlx_delete_texture(game->textures[T_SOUTH]);
	if (game->textures[T_WEST])
		mlx_delete_texture(game->textures[T_WEST]);
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map.floor_color)
		free(game->map.floor_color);
	if (game->map.ceiling_color)
		free(game->map.ceiling_color);
}
