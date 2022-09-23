/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:21:40 by sangtale          #+#    #+#             */
/*   Updated: 2022/03/22 15:21:40 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	is_set(char const *set, char c)
{
	while (set && *set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (len && *s1 && is_set(set, *s1))
	{
		++s1;
		--len;
	}
	while (len && is_set(set, s1[len - 1]))
		--len;
	return (ft_substr(s1, 0, len));
}
