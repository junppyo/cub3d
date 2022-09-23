/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:33:09 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/17 17:22:31 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
***		
		1. int c(converted to a char).
		2. If int c == NULL, strchr returns end of '*s', (NOT NULL POINTER).
***
*/
char	*ft_strchr(const char *s, int c)
{
	char	find_char;

	find_char = (char)c;
	while (*s != '\0')
	{
		if (*s == find_char)
			return ((char *)s);
		++s;
	}
	if (!find_char)
		return ((char *)s);
	return (NULL);
}
