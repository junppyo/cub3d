/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:19:38 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 09:28:54 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_MANAGER_H
# define GAME_MANAGER_H

#include "../cub3d.h"

# define X_EVENT_KEY_EXIT			17
# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

/*
		game_manager
*/
int		game_exit(t_game_info *g);
void	game_start(t_game_info *g);
/*
		game_image
*/
t_img	load_texture(t_game_info *g);
/*
		game_input
*/
int		press_key(int key_code, t_game_info *game);

#endif
