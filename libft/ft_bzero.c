/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:17:51 by sangtale          #+#    #+#             */
/*   Updated: 2022/03/22 15:17:51 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 		If *s is NULL, segv 	*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;

	dest = (unsigned char *)s;
	while (n--)
		*(dest++) = 0;
}
