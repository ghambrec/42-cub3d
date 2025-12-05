/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:33:42 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/05 11:23:00 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_success(t_game *game)
{
	clean_game(game);
	exit(EXIT_SUCCESS);
}

void	exit_failure(t_game *game, char *msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(msg, 2);
	if (game)
		clean_game(game);
	exit(EXIT_FAILURE);
}
