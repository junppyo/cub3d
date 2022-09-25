/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 08:47:40 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/25 16:43:27 by sangtale         ###   ########.fr       */
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

typedef	struct s_img
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


/****************************************************************************
								DEL_DEBUG_HEADER
****************************************************************************/
# include "debug.h"
/****************************************************************************
								DEL_DEBUG_HEADER
*****************************************************************************/

/*
		utils.c
*/
void	error_exit(char *message);
char	*ft_strtok(char *str, char sepa);
void	gameinfo_init(t_game_info *info, t_img_info *img_info, t_map_info *map_info);

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
void 	init_map_info(t_game_info *info, char *line);

/*
		map_check_utils
*/
int		is_map(char *str);
int		map_check(t_game_info *game_info);

/*
		del
*/
void    free_token(char **token);
void	free_map(t_map_info *info);
void	free_img_info(t_img_info *info);
void	free_err_exit(t_game_info *info, char *line, int *arr, char *msg);

#endif
