/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:55:52 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 09:31:03 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	token_free_exit(char **token, char *msg)
{
	if (token)
		free_token(token);
	if (msg)
		error_exit(msg);
}

int	skip_newline(char **line, int fd)
{
	if (*line)
		ft_free(*line);
	*line = get_next_line(fd);
	while (line != NULL && ft_strncmp(*line, "\n", 1) == 0)
	{
		ft_free(*line);
		*line = get_next_line(fd);
	}
	if (*line == NULL)
		return (1);
	return (0);
}

int	*line_to_arr(char *line)
{
	int		i;
	int		*arr;
	char	**temp;

	temp = ft_split(line + 2, ',');
	if (!temp)
		token_free_exit(NULL, "Split Error\n");
	arr = (int *)malloc(sizeof(int) * RGB_LEN);
	if (!arr)
		token_free_exit(temp, "line_to_arr malloc Error\n");
	i = -1;
	while (++i < RGB_LEN)
	{
		arr[i] = ft_atoi(temp[i]);
		if (arr[i] < 0 || 255 < arr[i])
			token_free_exit(temp, "Invalid RGB Color.\n");
	}
	if (temp[i] != NULL)
		token_free_exit(temp, "Invalid RGB Color.\n");
	i = -1;
	while (temp[++i])
		ft_free(temp[i]);
	ft_free(temp);
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
