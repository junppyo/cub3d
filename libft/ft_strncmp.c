/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:21:55 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/25 10:14:27 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	idx;

	if (str1 == NULL || str2 == NULL)
		return (0);
	idx = 0;
	while ((str1[idx] != '\0' || str2[idx] != '\0') && idx < num)
	{
		if (str1[idx] != str2[idx])
			return ((unsigned char)str1[idx] - (unsigned char)str2[idx]);
		++idx;
	}
	return (0);
}
