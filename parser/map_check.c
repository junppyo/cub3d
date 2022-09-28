/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:13:03 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 19:57:42 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_map_info(t_game_info *info, char *line)
{
	int	i;

	i = 0;
	// int tmp[24][24] =
	// {
	// 						{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
	// 						{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
	// 						{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	// 						{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
	// 						{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
	// 						{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
	// 						{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
	// 						{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
	// 						{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
	// 						{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
	// 						{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
	// 						{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
	// 						{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
	// 						{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
	// 						{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
	// 						{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
	// 						{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
	// 						{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
	// 						{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
	// 						{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
	// 						{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
	// 						{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
	// 						{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
	// 						{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
	// 					};
	// info->mapinfo->map = malloc(sizeof(char *) * 24);
	// info->mapinfo->row = 24;
	// info->mapinfo->col = 24;
	// for (int i = 0 ; i < 24; i++)
	// {
	// 	info->mapinfo->map[i] = malloc(sizeof(char) * 24);
	// 	for (int j = 0 ; j < 24;j ++)
	// 	{
	// 		info->mapinfo->map[i][j] = tmp[i][j] + '0';
	// 	}
	// }
	// return ;
	info->mapinfo->map = malloc(sizeof(char *) * MAX_ROW);
	info->mapinfo->row = 0;
	info->mapinfo->map[i] = line;
	info->mapinfo->col = ft_strlen(line);
	while (info->mapinfo->map[i])
	{
		info->mapinfo->row++;
		if (info->mapinfo->col < (int) ft_strlen(info->mapinfo->map[i]))
			info->mapinfo->col = ft_strlen(info->mapinfo->map[i]);
		info->mapinfo->map[++i] = get_next_line(info->fd);
	}
	while (++i < MAX_ROW)
		ft_free(info->mapinfo->map[i]);
}

int	chk_map(t_map_info *info)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j] != '\n' && info->map[i][j] != '\0')
		{
			if (info->map[i][j] == ' ' || info->map[i][j] == '0' || \
				info->map[i][j] == '1')
				continue ;
			if (flag == 0 && (info->map[i][j] == 'N' || \
				info->map[i][j] == 'S' || info->map[i][j] == 'W' || \
				info->map[i][j] == 'E'))
			{
				flag = 1;
				continue ;
			}
			return (1);
		}
	}
	return (0);
}

static int	chk_wall(char *s)
{
	char	*tmp;

	tmp = ft_strtok(s, ' ');
	if (!tmp)
		free(s);
	while (tmp)
	{
		if (ft_strlen(tmp) == 1 && tmp[0] == '1')
		{
			tmp = ft_strtok(NULL, ' ');
			continue ;
		}
		if (tmp[ft_strlen(tmp) - 1] == '\n' && tmp[ft_strlen(tmp) - 2] != '1')
			return (1);
		if (tmp[ft_strlen(tmp) - 1] != '\n' && tmp[ft_strlen(tmp) - 1] != '1')
			return (1);
		if (tmp[0] != '1')
			return (1);
		tmp = ft_strtok(NULL, ' ');
	}
	return (0);
}

int	chk_x_wall(t_map_info *info)
{
	int	i;

	i = -1;
	while (info->map[++i])
	{
		if (chk_wall(info->map[i]))
			return (1);
	}
	return (0);
}

int	chk_y_wall(t_map_info *info)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	s = malloc(sizeof(char) * info->row);
	while (++i < info->col)
	{
		j = -1;
		while (++j < info->row)
		{
			if ((int)ft_strlen(info->map[j]) - 1 < i || info->map[j][i] == '\n')
				s[j] = ' ';
			else
				s[j] = info->map[j][i];
		}
		if (chk_wall(s))
		{
			free(s);
			return (1);
		}
	}
	return (0);
}
