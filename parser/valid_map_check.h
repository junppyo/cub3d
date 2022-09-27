/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_check.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:31:23 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 15:32:32 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_MAP_CHECK_H
# define VALID_MAP_CHECK_H

# include "../cub3d.h"

# define RGB_LEN 3
# define MAX_ROW 512

/*
		valid_check.c
*/
void	valid_check_and_fill_info(char *av[], t_game_info *info);
/*
		valid_check_utils
*/
int		skip_newline(char **line, int fd);
int		*line_to_arr(char *line);
int		get_identifier(char *line);
void	free_err_exit(t_game_info *info, char *line, int *arr, char *msg);

/*
		map_check
*/
int		chk_x_wall(t_map_info *info);
int		chk_y_wall(t_map_info *info);
int		chk_map(t_map_info *info);
void	init_map_info(t_game_info *info, char *line);

/*
		map_check_utils
*/
int		is_map(char *str);
int		map_check(t_game_info *game_info);

#endif
