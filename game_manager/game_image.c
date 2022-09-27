/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:44:53 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 13:55:27 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_texture(t_game_info *g)
{
	int	i;

	g->texture = (int **)malloc(sizeof(int *) * 4);
	if (g->texture == NULL)
		free_err_exit(g, 0, 0, "img_texture malloc failure\n");
	i = -1;
	while (++i < 4)
	{
		g->texture[i] = (int *)malloc(sizeof(int) * texHeight * texWidth);
		if (g->texture[i] == NULL)
		{
			while (--i > -1)
				ft_free(g->texture[i]);
			free_err_exit(g, 0, 0, "img_texture malloc failure\n");
		}
	}
	while (--i > -1)
		ft_memset(g->texture[i], 0, sizeof(int) * texHeight * texWidth);
}

void	load_image(t_game_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(info->mlx, path, \
		&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
		&img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_game_info *g)
{
	t_img	img;

	ft_memset(&img, 0, sizeof(t_img));
	init_texture(g);
	load_image(g, g->texture[0], g->imginfo->east, &img);
	load_image(g, g->texture[1], g->imginfo->west, &img);
	load_image(g, g->texture[2], g->imginfo->south, &img);
	load_image(g, g->texture[3], g->imginfo->north, &img);
}
