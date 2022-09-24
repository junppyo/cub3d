/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:55:52 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/24 09:03:19 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_check.h"

void	init_map_info(t_map_info *info)
{
	info->celling = NULL;
	info->floor = NULL;
	info->east = NULL;
	info->west = NULL;
	info->south = NULL;
	info->north = NULL;
}

int	skip_newline(char **line, int fd)
{
	if (*line)
		ft_free(*line);
	*line = get_next_line(fd);
	while (ft_strlen(*line) == 1 && ft_strncmp(*line, "\n", 1) == 0)
	{
		ft_free(*line);
		*line = get_next_line(fd);
	}
	if (*line == NULL)
		return (1);
	return (0);
}

void	free_err_exit(char **token, char *line, int *arr, char *msg)
{
	int	i;

	if (token)
	{
		i = -1;
		while (token[++i])
			free(token[i]);
		free(token);
	}
	if (line)
		free(line);
	if (arr)
		free(arr);
	error_exit(msg);
}

int	*line_to_arr(char *line)
{
	int		i;
	int		*arr;
	char	**temp;

	temp = ft_split(line + 2, ',');
	if (!temp)
		free_err_exit(NULL, line, NULL, "Split Error\n");
	arr = (int *)malloc(sizeof(int) * RGB_LEN);
	if (!arr)
		free_err_exit(temp, line, NULL, "line_to_arr malloc Error\n");
	i = -1;
	while (++i < RGB_LEN)
	{
		arr[i] = ft_atoi(temp[i]);
		if (arr[i] < 0 || 255 < arr[i])
			free_err_exit(temp, line, arr, "Invalid RGB Color.\n");
	}
	if (temp[i] != NULL)
		free_err_exit(temp, line, arr, "Invalid RGB Color.\n");
	i = -1;
	while (temp[++i])
		free(temp[i]);
	free(temp);
	return (arr);
}

int	get_identifier(char *line)
{
	if (ft_strlen(line) < 3)
		return (0);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (EAST);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (WEST);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (SOUTH);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (NORTH);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (CELLING);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (FLOOR);
	return (0);
}
