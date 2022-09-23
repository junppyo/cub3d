/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:50:30 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/06 00:12:55 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define DIGITS "0123456789abcdef0123456789ABCDEF"

int	ft_putchar_cnt(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_cnt(char *str)
{
	size_t	i;
	int		put_count;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	put_count = 0;
	while (str[i])
		put_count += write(1, &str[i++], 1);
	return (put_count);
}

void	putnbr_int(unsigned int nbr, t_notation notation, int *cnt)
{
	if (nbr < notation.base)
	{
		*cnt += ft_putchar_cnt(DIGITS[nbr + notation.capital]);
	}
	else
	{
		putnbr_int(nbr / notation.base, notation, cnt);
		putnbr_int(nbr % notation.base, notation, cnt);
	}
}

void	putnbr_long(unsigned long nbr, t_notation notation, int *cnt)
{
	if (nbr < notation.base)
	{
		*cnt += ft_putchar_cnt(DIGITS[nbr + notation.capital]);
	}
	else
	{
		putnbr_long(nbr / notation.base, notation, cnt);
		putnbr_long(nbr % notation.base, notation, cnt);
	}
}
