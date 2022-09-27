/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:09:15 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 16:40:53 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	perror("");
	exit(EXIT_FAILURE);
}

void	gameinfo_init(t_game_info *info, t_img_info *img_info, \
			t_map_info *map_info)
{
	ft_memset(img_info, 0, sizeof(img_info));
	ft_memset(map_info, 0, sizeof(map_info));
	info->imginfo = img_info;
	info->mapinfo = map_info;
	info->fd = 0;
}

static char	*ft_strtok_init(char *str, char **stock, int *len, int *i)
{
	*i = 0;
	if (str)
	{
		*len = 0;
		*stock = ft_strdup(str);
	}
	return (NULL);
}

static void	ft_strtok_s(char **ptr, char **stock, int *i)
{
	*ptr = *stock;
	*i = 1;
}

char	*ft_strtok(char *str, char sepa)
{
	static char	*stock = NULL;
	static int	len;
	char		*ptr;
	int			i;

	ptr = ft_strtok_init(str, &stock, &len, &i);
	while (*stock != '\0')
	{
		if (i == 0 && *stock != sepa)
			ft_strtok_s(&ptr, &stock, &i);
		else if (i == 1 && *stock == sepa)
		{
			*stock = '\0';
			stock += 1;
			len++;
			break ;
		}
		stock++;
		len++;
	}
	if (!ptr)
		free(stock - len);
	return (ptr);
}
