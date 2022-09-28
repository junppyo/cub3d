/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 07:46:48 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/28 14:20:19 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	game_exit(t_game_info *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(EXIT_SUCCESS);
}

static void	draw(t_game_info *g, t_ray *r)
{
    int x;
    int y;

    y = -1;
	while (++y < height)
	{
        x = -1;
		while (++x < width)
			g->img.data[y * width + x] = r->buf[y][x];
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}


int	game_loop(t_game_info *g)
{
	t_ray	ray;

	floor_casting(g, &ray);
	wall_casting(g, &ray);
	draw(g, &ray);
	return (0);
}

void	game_start(t_game_info *g)
{
	find_starting_point(g->mapinfo, g->mapinfo->map);
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		free_err_exit(g, 0, 0, "mlx_init failure!\n");
	load_texture(g);
	g->win = mlx_new_window(g->mlx, width, height, "cub3D");
	if (g->win == NULL)
		free_err_exit(g, 0, 0, "mlx_new_window failure!\n");
	g->img.img = mlx_new_image(g->mlx, width, height);
	g->img.data = (int *)mlx_get_data_addr \
		(g->img.img, &(g->img.bpp), &(g->img.size_l), &(g->img.endian));
	mlx_loop_hook(g->mlx, &game_loop, g);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &press_key, g);
	mlx_loop(g->mlx);
}
