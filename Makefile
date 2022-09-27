# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangtale <sangtale@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/25 16:52:16 by sangtale          #+#    #+#              #
#    Updated: 2022/09/27 19:25:09 by sangtale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	compile
NAME		= cub3D
FLAGS		= -Wall -Wextra -Werror
LIBC		= ar rcs

#	Library
LIBFT		= libft
LIBFT_LIB	= libft.a

#	Directory
MANAGE_DIR	= game_manager
PARSER_DIR	= parser
DEBUG_DIR	= debug

SRCS		= 	\
				main.c \
				utils.c \
				del.c \
				$(PARSER_DIR)/valid_check.c \
				$(PARSER_DIR)/valid_check_utils.c \
				$(PARSER_DIR)/map_check.c \
				$(PARSER_DIR)/map_check_utils.c \
				$(MANAGE_DIR)/game_manager.c \
				$(MANAGE_DIR)/game_manager_utils.c \
				$(MANAGE_DIR)/game_input.c \
				$(MANAGE_DIR)/game_image.c \
				$(MANAGE_DIR)/floor_casting.c \
				$(DEBUG_DIR)/debug.c \

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
