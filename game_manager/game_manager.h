/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:19:38 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 19:52:12 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MANAGER_H
# define GAME_MANAGER_H

#include "../cub3d.h"

# define texWidth 				64
# define texHeight 				64
# define width					640
# define height					640

# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

typedef	struct s_ray
{
	int		p;
	int		cellX;
	int		cellY;
	int		tx;
	int		ty;
	int		color;
	float	posZ;
	float	rayDirX0;
	float	rayDirY0;
	float	rayDirX1;
	float	rayDirY1;
	float	rowDistance;
	float	floorStepX;
	float	floorStepY;
	float	floorX;
	float	floorY;
	int		buf[height][width];
}	t_ray;

/*
		game_manager
*/
int		game_exit(t_game_info *g);
void	game_start(t_game_info *g);
/*
		game_image
*/
void	load_texture(t_game_info *g);
/*
		game_input
*/
int		press_key(int key_code, t_game_info *game);
/*
		util
*/
void	find_starting_point(t_map_info *m, char **map);
/*		
		ray_caster
		-[floor_casting]
*/
void	floor_casting(t_game_info *info, t_ray *ray);

#endif
