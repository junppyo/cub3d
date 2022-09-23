/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:22:11 by sangtale          #+#    #+#             */
/*   Updated: 2022/03/22 15:31:34 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*** 	1. Size's length bigger than dst_len + 1('\0'),
			if not returned size + src length.
***		2. If not case.1, returned dst_len + suffix length.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_idx;

	dst_len = ft_strlen(dst);
	if (size < dst_len + 1)
		return (size + ft_strlen(src));
	src_idx = 0;
	while (dst_len + src_idx + 1 < size && src[src_idx] != '\0')
	{
		dst[dst_len + src_idx] = src[src_idx];
		++src_idx;
	}
	dst[dst_len + src_idx] = '\0';
	return (dst_len + ft_strlen(src));
}
