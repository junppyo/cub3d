/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:23:48 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 18:13:10 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

enum	e_identifier
{
	EAST = 1,
	WEST,
	SOUTH,
	NORTH,
	CELLING,
	FLOOR
};

# define MOV_SPEED (float)2
# define ROT_SPEED (float)2

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
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_map_info
{
	int		row;
	int		col;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	char	**map;
}	t_map_info;

typedef struct s_game_info
{
	int			fd;
	void		*mlx;
	void		*win;
	int			**texture;
	t_img		img;
	t_img_info	*imginfo;
	t_map_info	*mapinfo;
}	t_game_info;

#endif
