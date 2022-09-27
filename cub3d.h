/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 08:47:40 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 17:09:18 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"

/* f : perror, strerror, printf */
# include <stdio.h>

/* f : open, close */
# include <fcntl.h>

/* < custom header > */
# include "./structure.h"
# include "parser/valid_map_check.h"
# include "game_manager/game_manager.h"

/****************************************************************************
								DEL_DEBUG_HEADER
****************************************************************************/
# include "debug/debug.h"
/****************************************************************************
								DEL_DEBUG_HEADER
*****************************************************************************/

/*
		utils.c
*/
void	error_exit(char *message);
char	*ft_strtok(char *str, char sepa);
void	gameinfo_init(t_game_info *info, \
		t_img_info *img_info, t_map_info *map_info);

/*
		del
*/
void	free_token(char **token);
void	free_map(t_map_info *info);
void	free_img_info(t_img_info *info);
void	free_err_exit(t_game_info *info, char *line, int *arr, char *msg);

#endif
