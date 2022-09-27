/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:23:48 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 09:27:14 by sangtale         ###   ########.fr       */
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

#endif
