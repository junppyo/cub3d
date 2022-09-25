/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 08:47:40 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/26 07:57:39 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"

enum	e_identifier
{
	EAST = 1,
	WEST,
	SOUTH,
	NORTH,
	CELLING,
	FLOOR
};

typedef struct s_img_info
{
	int		*floor;
	int		*celling;
	char	*east;
	char	*west;
	char	*south;
	char	*north;
}	t_img_info;

typedef struct s_img
{
	void	*east;
	void	*west;
	void	*south;
	void	*north;
}	t_img;

typedef struct s_map_info
{
	int		row;
	int		col;
	int		player_x;
	int		player_y;
	char	**map;
}	t_map_info;

typedef struct s_game_info
{
	int			fd;
	void		*mlx;
	void		*win;
	t_img		img;
	t_img_info	*imginfo;
	t_map_info	*mapinfo;
}	t_game_info;

/* f : perror, strerror, printf */
# include <stdio.h>

/* f : open, close */
# include <fcntl.h>

/* < custom header > */
# include "valid_map_check.h"
# include "game_manager.h"

/****************************************************************************
								DEL_DEBUG_HEADER
****************************************************************************/
# include "debug.h"
/****************************************************************************
								DEL_DEBUG_HEADER
*****************************************************************************/

# define RGB_LEN 3
# define MAX_ROW 512

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
