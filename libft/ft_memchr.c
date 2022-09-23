/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:19:47 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/17 17:22:04 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* if *s == NULL, segv */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n--)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		++tmp;
	}
	return (NULL);
}
