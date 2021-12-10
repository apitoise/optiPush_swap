# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 15:46:34 by apitoise          #+#    #+#              #
#    Updated: 2021/05/28 14:00:49 by apitoise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang

LIB = libft/libft.a

INC = header/push_swap.h

CFLAGS = -Wall -Wextra -Werror

DIR_O = objs

SRCS = srcs/main_func/main.c \
		srcs/main_func/algo.c \
		srcs/main_func/check_arg.c \
		srcs/main_func/exec_best.c \
		srcs/utils/clean_exit.c \
		srcs/utils/ft_atoi_check.c \
		srcs/utils/ft_error.c \
		srcs/utils/is_sort.c \
		srcs/utils/new_rot_min.c\
		srcs/utils/calculate_best.c\
		srcs/actions/do_reverse_rotate.c \
		srcs/actions/do_rotate.c \
		srcs/actions/do_push.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
			make -C libft/
			mkdir -p objs
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)
			mv srcs/*/*.o objs 

clean: 
		rm -rf $(DIR_O)
		make clean -C libft/

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft/

re: fclean all

.PHONY: clean all fclean re
