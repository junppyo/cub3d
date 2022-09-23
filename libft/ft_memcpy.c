/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:20:25 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/17 17:22:09 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t copy_size)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (copy_size--)
		*(dst_ptr++) = *(src_ptr++);
	return (dst);
}
