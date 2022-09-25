/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:43:44 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/25 16:49:01 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	img_init(t_game_info *g)
{
	t_img	img;
	int		wid;
	int		hei;

	ft_memset(&img, 0, sizeof(t_img));
	img.west = mlx_xpm_file_to_image(g->mlx, g->imginfo->west, &wid, &hei);
	img.east = mlx_xpm_file_to_image(g->mlx, g->imginfo->east, &wid, &hei);
	img.south = mlx_xpm_file_to_image(g->mlx, g->imginfo->south, &wid, &hei);
	img.north = mlx_xpm_file_to_image(g->mlx, g->imginfo->north, &wid, &hei);
	if (!(img.west || img.east || img.south || img.north))
		error_exit("img_init() failure. img file does not exist\n");
	return (img);
}

static void	game_start(t_game_info *g)
{
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		free_err_exit(g, 0, 0, "mlx_init failure!\n");
	g->img = img_init(g);
	g->win = mlx_new_window(g->mlx, 960, 640, "cub3D");
	if (g->win == NULL)
		free_err_exit(g, 0, 0, "mlx_new_window failure!\n");
}

int	main(int ac, char *av[])
{
	t_game_info	gameinfo;
	t_img_info	img_info;
	t_map_info	map_info;

	if (ac != 2)
		error_exit("Argument Error\n[USAGE]\t./cub3d {$FILE_NAME}.cub\n");
	gameinfo_init(&gameinfo, &img_info, &map_info);
	valid_check_and_fill_info(av, &gameinfo);
	game_start(&gameinfo);
	return (EXIT_SUCCESS);
}
