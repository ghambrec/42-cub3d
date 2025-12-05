/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:38:34 by ghambrec          #+#    #+#             */
/*   Updated: 2025/12/05 11:38:40 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_map_values
{
	MV_WALL = '1',
	MV_FLOOR = '0',
	MV_PLAYER = 'P',
	MV_SPACE = ' '
}	t_map_values;

typedef enum e_textures_keys
{
	T_NORTH,
	T_EAST,
	T_SOUTH,
	T_WEST
}	t_textures_keys;

#endif
