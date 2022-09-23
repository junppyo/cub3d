/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:21:14 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/17 17:22:52 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
***		If src's lenth smaller than start, returned an empty string.
***		And also it can free.
*/
char	*ft_substr(char const *s, unsigned int start, size_t ret_len)
{
	char	*result;
	size_t	src_len;
	size_t	sub_idx;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len || ret_len == 0)
		return (ft_strdup(""));
	if (ret_len >= src_len)
		ret_len = src_len;
	result = (char *)malloc(sizeof(char) * (ret_len + 1));
	if (!result)
		return (NULL);
	sub_idx = 0;
	while (sub_idx < ret_len)
	{
		result[sub_idx] = s[start];
		++sub_idx;
		++start;
	}
	result[sub_idx] = '\0';
	return (result);
}
