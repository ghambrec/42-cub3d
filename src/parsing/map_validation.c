/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:47:13 by rstumpf           #+#    #+#             */
/*   Updated: 2025/08/27 17:41:20 by rstumpf          ###   ########.fr       */
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
	printf("Player Position: x=%f, y=%f\n", game->player.pos.x, game->player.pos.y);
	floodfill_validation(game);
	printf("Map validation successful\n");
	return ;
}
