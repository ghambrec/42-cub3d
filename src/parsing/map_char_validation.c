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

void	char_validation(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (check_chars(map[i]) == -1)
		{
			ft_putstr_fd("Map is invalid! Unallowed character used\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}
