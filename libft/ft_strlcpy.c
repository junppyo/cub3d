/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:22:07 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/18 19:21:38 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	while (dstsize > idx + 1 && src[idx] != '\0')
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dstsize > 0)
		dst[idx] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcpy_without_newline(char *dst, char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	while (dstsize > idx + 1 && src[idx] != '\0' && src[idx] != '\n')
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dstsize > 0)
		dst[idx] = '\0';
	return (ft_strlen(src));
}
