/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 07:46:48 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 09:15:19 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	game_exit(t_game_info *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(EXIT_SUCCESS);
}

void	game_start(t_game_info *g)
{
	g->img = load_texture(g);
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		free_err_exit(g, 0, 0, "mlx_init failure!\n");
	g->win = mlx_new_window(g->mlx, 960, 640, "cub3D");
	if (g->win == NULL)
		free_err_exit(g, 0, 0, "mlx_new_window failure!\n");
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &game_exit, g);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &press_key, g);
	mlx_loop(g->mlx);
}

