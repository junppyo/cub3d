/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:43:55 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/06 00:04:01 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnl_free(void *data)
{
	free(data);
	data = NULL;
}

void	*del_node(t_lst **node)
{
	free((*node)->save);
	(*node)->prev->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	free(*node);
	*node = NULL;
	return (NULL);
}
