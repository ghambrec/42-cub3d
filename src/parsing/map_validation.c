/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:47:13 by rstumpf           #+#    #+#             */
/*   Updated: 2025/09/08 13:26:17 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_validation(t_game *game)
{
	map_open(&game->map);
	char_validation(game->map.map_string);
	create_map(game);
	get_map_width_height(game);
	get_player_pos(game);
	printf("Player Position: x=%i, y=%i\n", game->player.pos1D.x, game->player.pos1D.y);
	floodfill_validation(game);
	printf("Map validation successful\n");
	return ;
}
