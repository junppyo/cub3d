/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:21:48 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/17 17:23:00 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
***
	 	1. If needle is an empty string, haystack is returned.
		2. If haystack or needle == NULL POINTER, segv.
***
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hay_idx;
	size_t	needle_idx;

	if (needle[0] == '\0')
		return ((char *)haystack);
	hay_idx = 0;
	needle_idx = 0;
	while (haystack[hay_idx] != '\0' && (hay_idx < len))
	{
		if (haystack[hay_idx] == needle[needle_idx])
			++needle_idx;
		else
		{
			hay_idx -= needle_idx;
			needle_idx = 0;
		}
		if (needle[needle_idx] == '\0')
			return ((char *)haystack + hay_idx - needle_idx + 1);
		++hay_idx;
	}
	return (NULL);
}
