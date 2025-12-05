/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:24:42 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/05 11:25:20 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_resize(t_game *game)
{
	mlx_delete_image(game->mlx, game->img_minimap);
	game->img_minimap = NULL;
	mlx_delete_image(game->mlx, game->img_game);
	game->img_game = NULL;
	render_game(game);
}

// TODO: resize game window (bisher geht nur die minimap)
// TODO: min size festlegen
void	resize_hook(int32_t width, int32_t height, void *param)
{
	t_game	*game;

	(void)width;
	(void)height;
	game = (t_game *)param;
	handle_resize(game);
}
