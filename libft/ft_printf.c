/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:50:25 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/06 00:19:52 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SPECIFIER "cspdiuxX%"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		i;
	int			cnt;

	i = 0;
	cnt = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			++cnt;
		}
		else if (format[i + 1] && ft_strchr(SPECIFIER, format[i + 1]))
		{
			cnt += parse_format(&ap, format[i + 1]);
			++i;
		}
		++i;
	}
	va_end(ap);
	return (cnt);
}
