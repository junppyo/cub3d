/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 08:47:43 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/24 09:00:51 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_CHECK_H
# define VALID_CHECK_H

# include "./cub3d.h"

/*
		valid_check_utils
*/
void	init_map_info(t_map_info *info);
int		skip_newline(char **line, int fd);
int		*line_to_arr(char *line);
int		get_identifier(char *line);
void	free_err_exit(char **token, char *line, int *arr, char *msg);

enum	e_identifier
{
	EAST = 1,
	WEST,
	SOUTH,
	NORTH,
	CELLING,
	FLOOR
};

#endif
