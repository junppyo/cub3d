/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:09:15 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/23 15:09:16 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(const char *str)
{
	char	*tmp;
	char	*result;
	size_t	len;

	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	tmp = result;
	while (*str != '\0')
		*(tmp++) = *(str++);
	*tmp = '\0';
	return (result);
}

void	free_img_info(t_img_info *info)
{
	if (info->floor)
		free(info->floor);
	if (info->celling)
		free(info->celling);
	if (info->east)
		free(info->east);
	if (info->west)
		free(info->west);
	if (info->south)
		free(info->south);
	if (info->north)
		free(info->north);
}

void	error_exit(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	perror("");
	exit(EXIT_FAILURE);
}

char	*ft_strtok(char *str, char sepa)
{
	static char	*stock = NULL;
	char		*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if (str != NULL)
		stock = ft_strdup(str);
	while (*stock != '\0')
	{
		if (i == 0 && *stock != sepa)
		{
			i = 1;
			ptr = stock;
		}
		else if (i == 1 && *stock == sepa)
		{
			*stock = '\0';
			stock += 1;
			break ;
		}
		stock++;
	}
	return (ptr);
}