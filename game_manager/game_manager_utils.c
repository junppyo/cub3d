/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:51:50 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 19:49:49 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void set_starting_point(t_map_info *m, int x, int y)
{
	m->posX = x + 0.5;
	m->posY = y + 0.5;
	if (m->map[y][x] == 'E')
	{
		m->dirX = -1;
		m->dirY = 0;
	}
	else if (m->map[y][x] == 'W')
	{
		m->dirX = 1;
		m->dirY = 0;
	}
	else if (m->map[y][x] == 'S')
	{
		m->dirX = 0;
		m->dirY = -1;
	}
	else if (m->map[y][x] == 'N')
	{
		m->dirX = 0;
		m->dirY = 1;
	}
}

void	find_starting_point(t_map_info *m, char **map)
{
	int x;
	int y;

	y = -1;
	while (++y < m->row)
	{
		x = -1;
		while (++x < m->col)
		{
			if (ft_strchr("EWNS", map[y][x]))
			{
				set_starting_point(m, x, y);
				return ;
			}
		}
	}
}
