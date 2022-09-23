/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:09:15 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/23 15:09:16 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map_info(t_map_info *info)
{
	if (info->floor)
		free(info->floor);
	if (info->celling)
		free(info->celling);
	if (info->east)
		free(info->east);
	if (info->west)
		free(info->west);
	if (info->south)
		free(info->south);
	if (info->north)
		free(info->north);
}

void	error_exit(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	perror("");
	exit(EXIT_FAILURE);
}
