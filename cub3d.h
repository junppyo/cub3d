/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 08:47:40 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/24 08:47:41 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* custom.h */
# include "libft/libft.h"
# include "mlx/mlx.h"

/* f : perror, strerror, printf */
# include <stdio.h>

/* f : open, close */
# include <fcntl.h>

# define RGB_LEN 3
# define MAX_ROW 512

typedef struct s_img_info
{
	int		*floor;
	int		*celling;
	char	*east;
	char	*west;
	char	*south;
	char	*north;
}	t_img_info;

typedef struct s_map_info
{
	char	**map;
	int		row;
	int		col;
	int		player_x;
	int		player_y;
}	t_map_info;

typedef struct s_game_info
{
	int			fd;
	t_img_info	*imginfo;
	t_map_info	*mapinfo;
}	t_game_info;

/*
		valid_check.c
*/
void	valid_check_and_fill_info(char *av[], t_img_info *info);
/*
		utils.c
*/
void	free_img_info(t_img_info *info);
void	error_exit(char *message);
char	*ft_strtok(char *str, char sepa);

#endif
