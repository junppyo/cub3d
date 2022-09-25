#include "cub3d.h"

void    free_token(char **token)
{
    int i;

    i = 0;
    while (token[i])
    {
        ft_free(token[i]);
        i++;
    }
    ft_free(token);
}

void	free_img_info(t_img_info *info)
{
	if (info->floor != NULL)
		ft_free(info->floor);
	if (info->celling != NULL)
		ft_free(info->celling);
	if (info->east != NULL)
		ft_free(info->east);
	if (info->west != NULL)
		ft_free(info->west);
	if (info->south != NULL)
		ft_free(info->south);
	if (info->north != NULL)
		ft_free(info->north);
}

void	free_map(t_map_info *info)
{
	int	i;

	if (info->map == NULL)
		return ;
	i = -1;
	while (++i < info->col)
		ft_free(info->map[i]);
	ft_free(info->map);
}

void	free_err_exit(t_game_info *info, char *line, int *arr, char *msg)
{
	int	i;

	if (info->imginfo != NULL)
		free_img_info(info->imginfo);
	if (info->mapinfo != NULL)
	{
		i = -1;
		while (++i < info->mapinfo->col)
			ft_free(info->mapinfo->map[i]);
		ft_free(info->mapinfo);
	}
	if (line)
		ft_free(line);
	if (arr)
		ft_free(arr);
	error_exit(msg);
}