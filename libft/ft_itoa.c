/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:18:48 by sangtale          #+#    #+#             */
/*   Updated: 2022/03/22 15:18:48 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 20~24 Line : protect overflow */
static short	convert_to_str(char *buffer, int n, short is_neg)
{
	short	index;

	index = 10;
	if (is_neg)
	{
		buffer[index--] = '0' - (n % 10);
		n = (n / 10) * -1;
	}
	else
	{
		buffer[index--] = (n % 10) + '0';
		n /= 10;
	}
	while (n)
	{
		buffer[index--] = (n % 10) + '0';
		n /= 10;
	}
	if (is_neg)
		buffer[index--] = '-';
	return (index + 1);
}

char	*ft_itoa(int n)
{
	short	is_neg;
	short	index;
	char	buffer[12];

	if (n < 0)
		is_neg = 1;
	else
		is_neg = 0;
	buffer[11] = '\0';
	index = convert_to_str(buffer, n, is_neg);
	return (ft_strdup(buffer + index));
}
