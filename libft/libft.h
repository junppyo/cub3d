/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:54:25 by sangtale          #+#    #+#             */
/*   Updated: 2022/09/27 18:01:39 by sangtale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
***	libft
*/
typedef struct s_list
{
	void			*value;
	struct s_list	*next;
}	t_list;

/*
***	gnl
*/
typedef struct s_lst
{
	int				fd;
	char			*save;
	struct s_lst	*prev;
	struct s_lst	*next;
}	t_lst;

/*
***	ft_printf
*/
typedef struct s_notation
{
	unsigned int	base;
	int				capital;
}	t_notation;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (42)
# endif

/*
***
****	libft
***
*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
void	ft_bzero(void *b, size_t num);
void	*ft_memcpy(void *dst, const void *src, size_t size);
void	*ft_memset(void *dest, int c, size_t num);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *str, int vaule, size_t size);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
/*
***		linked_list
*/
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(void *value);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/*
***
*****	get_next_line
***
*/
char	*get_next_line(int fd);
t_lst	*get_node(t_lst *head, int fd);
char	*read_and_stuff(char **save, char *buf, char *past, int fd);
char	*gnl_strjoin(char *save, char *buf);
char	*refine_line(t_lst *node, char *save);
/*
***		get_next_line_utils
*/
void	gnl_free(void *data);
void	*del_node(t_lst **node);
/*
***
*****	ft_pritnf.c
***
*/
int		ft_printf(const char *format, ...);
int		parse_format(va_list *ap, char format);
int		putnbr_order(long nbr, char format);
int		ft_putchar_cnt(char c);
int		ft_putstr_cnt(char *str);
void	init_struct(t_notation *notation, char format);
void	putnbr_int(unsigned int nbr, t_notation notation, int *cnt);
void	putnbr_long(unsigned long nbr, t_notation notation, int *cnt);
/*
***
*****	ETC
***
**
*/
char	*ft_strdup_without_newline(char *str);
char	*ft_strdup_nl_and_free(char *str);
size_t	ft_strlcpy_without_newline(char *dst, char *src, size_t dstsize);
char	*ft_strjoin_without_newline(char *s1, char *s2);
void	ft_free(void *data);

#endif
