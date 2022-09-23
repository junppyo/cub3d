/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:20:30 by sangtale          #+#    #+#             */
/*   Updated: 2022/03/22 15:20:30 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src)
	{
		dst_tmp = (unsigned char *)dst + len - 1;
		src_tmp = (unsigned char *)src + len - 1;
		while (len--)
			*(dst_tmp--) = *(src_tmp--);
	}
	return (dst);
}
