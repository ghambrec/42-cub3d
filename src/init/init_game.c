/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:25:25 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/05 11:25:27 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->map.map2d = NULL;
	game->map.map2d_copy = NULL;
	game->map.map_name = NULL;
	game->map.map_string = NULL;
	game->img_game = NULL;
	game->img_minimap = NULL;
	game->mlx = NULL;
	game->player.player_count = 0;
	game->texture_path.north = NULL;
	game->texture_path.west = NULL;
	game->texture_path.east = NULL;
	game->texture_path.south = NULL;
	game->map.ceiling_color = 0;
	game->map.floor_color = 0;
	game->textures[T_NORTH] = NULL;
	game->textures[T_EAST] = NULL;
	game->textures[T_SOUTH] = NULL;
	game->textures[T_WEST] = NULL;
}
