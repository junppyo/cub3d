/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:21:44 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/17 17:22:57 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
***
	1. If int c == NULL, strrchr returns end of '*s'(NOT NULL).
	2. If *s == NULL, segv.
	3. 
***
*/
char	*ft_strrchr(const char *s, int c)
{
	char		to_find;
	const char	*last_found;

	to_find = (char)c;
	last_found = NULL;
	while (*s)
	{
		if (*s == to_find)
			last_found = s;
		++s;
	}
	if (!c)
		return ((char *)s);
	return ((char *)last_found);
}
