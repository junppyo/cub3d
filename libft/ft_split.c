/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:33:21 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/17 17:22:27 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **array, size_t index)
{
	while (index--)
		free(array[index]);
	free(array);
}

/*	string copy and free	*/
static short	append_result(char **result, size_t index,
						const char *word_start, size_t str_len)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!new_str)
	{
		free_array(result, index);
		return (0);
	}
	ft_strlcpy(new_str, word_start, str_len + 1);
	result[index] = new_str;
	return (1);
}

/* count string length and malloc 1-D array */
static short	parsing_string(char **result, const char *str, char c)
{
	size_t		index;
	size_t		str_len;
	const char	*word_start;

	while (c != '\0' && *str == c)
		++str;
	index = 0;
	while (*str != '\0')
	{
		str_len = 0;
		word_start = str;
		while (*str != c && *str != '\0')
		{
			++str_len;
			++str;
		}
		if (!append_result(result, index, word_start, str_len))
			return (0);
		++index;
		while (c != '\0' && *str == c)
			++str;
	}
	result[index] = 0;
	return (1);
}

/* 	count charset, and set empty 2-D array 	*/
static char	**set_empty_array(const char *str, char c)
{
	short	is_charset;
	size_t	charset_count;
	char	**result;

	is_charset = 1;
	charset_count = 0;
	while (*str != '\0')
	{
		if (*str == c)
			is_charset = 1;
		else
		{
			if (is_charset == 1)
				++charset_count;
			is_charset = 0;
		}
		++str;
	}
	result = (char **)malloc(sizeof(char *) * (charset_count + 1));
	if (!result)
		return (NULL);
	return (result);
}

char	**ft_split(const char *str, char c)
{
	char	**result;

	if (!str)
		return (NULL);
	result = set_empty_array(str, c);
	if (!result)
		return (NULL);
	if (!parsing_string(result, str, c))
		return (NULL);
	return (result);
}
