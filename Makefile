# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 16:52:16 by sangtale          #+#    #+#              #
#    Updated: 2022/09/25 16:52:16 by sangtale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
FLAGS		= -Wall -Wextra -Werror
LIBC		= ar rcs
LIBFT		= libft
LIBFT_LIB	= libft.a
SRCS		= 	\
				main.c \
				utils.c \
				valid_check.c \
				valid_check_utils.c \
				map_check.c \
				map_check_utils.c \
				del.c \
				debug.c

OBJS		= $(SRCS:%.c=%.o)

%.o : %.c
		@gcc $(FLAGS) -c $^ -I./ -o $@

all			: $(NAME)


$(NAME)		: $(OBJS)
		@make all -C $(LIBFT)/
		@gcc -o $(NAME) $(OBJS) -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit


clean :
		@rm -f $(OBJS)
		@make clean -C $(LIBFT)

fclean : clean
		@rm -f $(NAME)
		@rm -f $(TARGET)
		@rm -f $(LIBFT_LIB)
		@make fclean -C $(LIBFT)

re :
		@make fclean
		@make -j 8 all
		@make clean

.PHONY :
		all clean fclean re bonus
