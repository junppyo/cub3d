/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:33:03 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 18:34:58 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*tmp;
	char	*result;
	size_t	len;

	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	tmp = result;
	while (*str != '\0')
		*(tmp++) = *(str++);
	*tmp = '\0';
	return (result);
}

char	*ft_strdup_without_newline(char *str)
{
	char	*result;
	char	*tmp;
	size_t	len;

	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	tmp = result;
	while (*str != '\0' && *str != '\n')
		*(tmp++) = *(str++);
	*tmp = '\0';
	return (result);
}

char	*ft_strdup_nl_and_free(char *str)
{
	char	*result;
	char	*tmp;
	size_t	len;

	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	tmp = result;
	while (*str != '\0' && *str != '\n')
		*(tmp++) = *(str++);
	*tmp = '\0';
	return (result);
}
