/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:17:46 by sangtale          #+#    #+#             */
/*   Updated: 2022/03/22 15:18:19 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{	
	short			sign;
	unsigned int	result;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		++str;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	while (ft_isdigit(*str))
		result = result * 10 + *(str++) - '0';
	if (result > 2147483647 && sign == 1)
		return (-1);
	else if (result - 1 > 2147483647 && sign == -1)
		return (0);
	return (result * sign);
}
