#include "../cub3d.h"

t_img	load_texture(t_game_info *g)
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
		error_exit("load_texture() failure. img file does not exist\n");
	return (img);
}
