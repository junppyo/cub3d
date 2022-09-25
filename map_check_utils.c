/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 07:42:57 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/25 16:34:42 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_check(t_game_info *game_info)
{
	int	error;
	int	i;

	error = 0;
	i = -1;
	while (++i < game_info->mapinfo->row)
	{
		if (game_info->mapinfo->map[i] \
			&& ft_strncmp(game_info->mapinfo->map[i], "\n", 1) == 0)
			return (printf("map include empty line\n"));
		if (!is_map(game_info->mapinfo->map[i]))
			return (printf("Invalid characters\n"));
	}
	if (chk_map(game_info->mapinfo))
		error += printf("start position must be one\n");
	if (chk_x_wall(game_info->mapinfo))
		error += printf("X wall broken\n");
	if (chk_y_wall(game_info->mapinfo))
		error += printf("Y wall broken\n");
	return (error);
}

int	is_map(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1' \
			|| str[i] == ' ' || str[i] == '\n'\
			|| str[i] == 'W' || str[i] == 'E' \
			|| str[i] == 'N' || str[i] == 'S')
			i++;
		else
			return (0);
	}
	return (1);
}
