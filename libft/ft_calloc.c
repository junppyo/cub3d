/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:21:38 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/17 17:21:39 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*		count or size == 0, undefined behavior. 	*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated;

	allocated = malloc(count * size);
	if (!allocated)
		return (NULL);
	ft_memset(allocated, 0, count * size);
	return (allocated);
}
