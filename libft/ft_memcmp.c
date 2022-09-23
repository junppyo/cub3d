/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:19:52 by sangtale          #+#    #+#             */
/*   Updated: 2022/03/22 15:20:02 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				idx;

	idx = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (idx < n)
	{
		if (str1[idx] != str2[idx])
			return (str1[idx] - str2[idx]);
		++idx;
	}
	return (0);
}
