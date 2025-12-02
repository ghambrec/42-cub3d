/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:37:20 by rstumpf           #+#    #+#             */
/*   Updated: 2025/08/27 16:23:39 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_chars(char c)
{
	if (c == 'N' || c == '0' || c == '1' || c == 'W'
		|| c == 'S' || c == 'E' || c == '\n' || c == ' ')
		return (1);
	return (-1);
}

void	char_validation(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map_string[i])
	{
		if (check_chars(game->map.map_string[i]) == -1)
		{
			exit_failure(game, "unallowed character");
		}
		i++;
	}
	return ;
}
