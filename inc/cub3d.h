/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstumpf <rstumpf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:53:44 by rstumpf           #+#    #+#             */
/*   Updated: 2025/08/25 16:32:10 by rstumpf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "../lib/myLibft/include/my_libft.h"

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
