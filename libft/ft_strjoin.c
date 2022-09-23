/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:31:58 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/18 16:47:17 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
***		If *s1, *s2 == NULL, returned empty string(can free).
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (ft_strdup(""));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	ft_strlcpy(result + s1_len, s2, s2_len + 1);
	return (result);
}

char	*ft_strjoin_without_newline(char *s1, char *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup_without_newline(s2));
	else if (s2 == NULL)
		return (ft_strdup_without_newline(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(s1_len + s2_len);
	if (!result)
		return (NULL);
	ft_strlcpy_without_newline(result, s1, s1_len + 1);
	ft_strlcpy_without_newline(result + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (result);
}
