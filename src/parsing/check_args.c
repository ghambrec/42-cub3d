/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:10:28 by rstumpf           #+#    #+#             */
/*   Updated: 2025/12/05 12:27:05 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	arg_validation(char **argv, int n)
{
	if (n != 2)
		exit_failure(NULL, "You need one and only one argument!");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		exit_failure(NULL, "Your map has to end with .cub");
	return ;
}
