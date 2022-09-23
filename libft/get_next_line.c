/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:43:49 by sangtale          #+#    #+#             */
/*   Updated: 2022/05/24 04:36:17 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_lst	head;
	t_lst			*node;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	node = get_node(&head, fd);
	if (!node)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	node->save = read_and_stuff(&(node->save), buffer, 0, fd);
	gnl_free(buffer);
	if (node->save == NULL)
		return (del_node(&node));
	return (refine_line(node, node->save));
}

t_lst	*get_node(t_lst *head, int fd)
{
	t_lst	*node;

	node = head->next;
	while (node != NULL)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->save = NULL;
	node->prev = head;
	node->next = head->next;
	if (head->next != NULL)
		head->next->prev = node;
	head->next = node;
	return (node);
}

char	*read_and_stuff(char **save, char *buffer, char *past, int fd)
{
	char	*new;
	ssize_t	read_size;

	new = *save;
	read_size = 0;
	while (new == NULL || !ft_strchr(new, '\n'))
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 1)
			break ;
		buffer[read_size] = '\0';
		past = new;
		new = gnl_strjoin(new, buffer);
		gnl_free(past);
	}
	if (new == NULL || read_size < 0 || new[0] == '\0')
	{
		gnl_free(new);
		return (NULL);
	}
	return (new);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;

	if (!s2)
		return (NULL);
	else if (s1 == NULL && s2)
	{
		new = (char *)malloc(ft_strlen(s2) + 1);
		if (!new)
			return (NULL);
		ft_strlcpy(new, s2, ft_strlen(s2) + 1);
		return (new);
	}
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcpy(new + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (new);
}

char	*refine_line(t_lst *node, char *save)
{
	size_t	len;
	char	*line;
	char	*new_save;

	if (ft_strchr(save, '\n'))
		len = ft_strchr(save, '\n') - save + 1;
	else
		len = ft_strchr(save, '\0') - save;
	line = (char *)malloc(len + 1);
	if (!line)
		return (del_node(&node));
	ft_strlcpy(line, save, len + 1);
	new_save = (char *)malloc(ft_strlen(save + len) + 1);
	if (!new_save)
		return (del_node(&node));
	ft_strlcpy(new_save, save + len, ft_strlen(save + len) + 1);
	gnl_free(node->save);
	node->save = new_save;
	return (line);
}
