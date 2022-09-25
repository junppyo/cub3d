/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 07:46:48 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/26 07:54:36 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	img_init(t_game_info *g);

int	game_exit(t_game_info *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(EXIT_SUCCESS);
}

void	game_start(t_game_info *g)
{
	g->img = img_init(g);
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

static t_img	img_init(t_game_info *g)
{
	t_img	img;
	int		wid;
	int		hei;

	ft_memset(&img, 0, sizeof(t_img));
	img.east = mlx_xpm_file_to_image(g->mlx, g->imginfo->east, &wid, &hei);
	ft_free(g->imginfo->east);
	img.west = mlx_xpm_file_to_image(g->mlx, g->imginfo->west, &wid, &hei);
	ft_free(g->imginfo->west);
	img.south = mlx_xpm_file_to_image(g->mlx, g->imginfo->south, &wid, &hei);
	ft_free(g->imginfo->south);
	img.north = mlx_xpm_file_to_image(g->mlx, g->imginfo->north, &wid, &hei);
	ft_free(g->imginfo->north);
	if (!(img.west || img.east || img.south || img.north))
		error_exit("img_init() failure. img file does not exist\n");
	return (img);
}
