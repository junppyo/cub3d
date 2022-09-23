/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:43:52 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/24 04:36:05 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

typedef struct s_lst
{
	int				fd;
	char			*save;
	struct s_lst	*prev;
	struct s_lst	*next;
}	t_lst;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (10000)
# endif

/*
***		get_next_line
*/
char	*get_next_line(int fd);
t_lst	*get_node(t_lst *head, int fd);
char	*read_and_stuff(char **save, char *buf, char *past, int fd);
char	*gnl_strjoin(char *save, char *buf);
char	*refine_line(t_lst *node, char *save);
/*
***		get_next_line_util
*/
void	gnl_free(void *data);
void	*del_node(t_lst **node);

#endif
