/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:44:26 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 14:04:12 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	is_invalid_extension(char *filename)
{
	size_t	i;

	i = 0;
	while (filename[i] != '\0')
		i++;
	if (filename[i - 1] == 'b' && filename[i - 2] == 'u' \
		&& filename[i - 3] == 'c' && filename[i - 4] == '.')
		return (0);
	return (1);
}

static int	fill_img_info(char **line, int fd, int id, t_img_info *info)
{
	while (line != NULL && ft_strncmp(*line, "\n", 1) != 0)
	{
		id = get_identifier(*line);
		if (id == 0)
			return (1);
		if (id == EAST)
			info->east = ft_strdup_without_newline(*line + 3);
		if (id == WEST)
			info->west = ft_strdup_without_newline(*line + 3);
		if (id == SOUTH)
			info->south = ft_strdup_without_newline(*line + 3);
		if (id == NORTH)
			info->north = ft_strdup_without_newline(*line + 3);
		if (id == CELLING)
			info->celling = line_to_arr(*line);
		if (id == FLOOR)
			info->floor = line_to_arr(*line);
		ft_free(*line);
		*line = get_next_line(fd);
	}
	if (*line == NULL)
		return (1);
	return (0);
}

static void	valid_check(t_game_info *info)
{
	char	*line;

	line = NULL;
	if (skip_newline(&line, info->fd))
		free_err_exit(info, NULL, NULL, "Invalid Map\n");
	if (fill_img_info(&line, info->fd, 0, info->imginfo))
		free_err_exit(info, line, NULL, "Invalid Map\n");
	if (skip_newline(&line, info->fd))
		free_err_exit(info, line, NULL, "Invalid Map\n");
	if (fill_img_info(&line, info->fd, 0, info->imginfo))
		free_err_exit(info, line, NULL, "Invalid Map\n");
	if (skip_newline(&line, info->fd))
		free_err_exit(info, line, NULL, "Invalid Map\n");
	init_map_info(info, line);
	close(info->fd);
}

static int	file_exist_check(t_img_info *info)
{
	int	fd[4];
	int	error;
	int	i;

	error = 0;
	fd[0] = open(info->east, O_RDONLY);
	if (fd[0] <= 0)
		error += printf("east file not exist\n");
	fd[1] = open(info->west, O_RDONLY);
	if (fd[1] <= 0)
		error += printf("west file not exist\n");
	fd[2] = open(info->south, O_RDONLY);
	if (fd[2] <= 0)
		error += printf("south file not exist\n");
	fd[3] = open(info->north, O_RDONLY);
	if (fd[3] <= 0)
		error += printf("north file not exist\n");
	i = -1;
	while (++i < 4)
		close(fd[i]);
	if (error > 0)
		return (1);
	return (0);
}

void	valid_check_and_fill_info(char *av[], t_game_info *info)
{
	if (is_invalid_extension(av[1]))
		error_exit("Map's Extension Must Be {$FILE_NAME}.cub\n");
	info->fd = open(av[1], O_RDONLY);
	if (info->fd <= 0)
		error_exit("open error\n");
	valid_check(info);
	// if (map_check(info))
	// 	error_exit("invalid map\n");
	if (file_exist_check(info->imginfo))
		error_exit("");
}
