/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:44:26 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/23 15:17:36 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	공백 스킵
	블록 파싱, 파일 존재 여부
	공백 스킵
	블록 파싱, 파일 존재 여부
	공백 스킵
	지도 파싱, 지도 유효성 체크
	파일 닫고 다시 열기
*/
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

static void	fill_map_info(char **line, int fd, t_map_info *info)
{
	int	id;

	while (ft_strncmp(*line, "\n", 1) != 0 && ft_strlen(*line) != 1 \
		&& line != NULL)
	{
		id = get_identifier(*line);
		if (id == 0)
		{
			printf("%s", *line);
			error_exit("Invalid Identifier\n");
		}
		if (id == EAST)
			info->east = ft_strdup(*line);
		if (id == WEST)
			info->west = ft_strdup(*line);
		if (id == SOUTH)
			info->south = ft_strdup(*line);
		if (id == NORTH)
			info->north = ft_strdup(*line);
		if (id == CELLING)
			info->celling = line_to_arr(*line);
		if (id == FLOOR)
			info->floor = line_to_arr(*line);
		ft_free(*line);
		*line = get_next_line(fd);
	}
	if (*line == NULL)
		error_exit("Invalid Map\n");
}

static void	valid_check(int fd, t_map_info *info)
{
	int		id;
	char	*line;

	skip_newline(&line, fd);
	fill_map_info(&line, fd, info);
	skip_newline(&line, fd);
	fill_map_info(&line, fd, info);
	free(line);// 메모리 누수 체크로 인한 임시 해제
	/*
		맵 체크
	*/
}

void	valid_check_and_fill_info(char *av[], t_map_info *info)
{
	int	fd;

	if (is_invalid_extension(av[1]))
		error_exit("Map's Extension Must Be {$FILE_NAME}.cub\n");
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
		error_exit("open error\n");
	valid_check(fd, info);
}
