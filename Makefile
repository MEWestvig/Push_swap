# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 10:52:28 by mwestvig          #+#    #+#              #
#    Updated: 2018/08/20 11:45:13 by mwestvig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap

FLAGS = -Wall -Werror -Wextra -I includes

SRCS = srcs/checker.c \
	   srcs/error.c \
	   srcs/lst_functions.c \
	   srcs/operations.c \
	   srcs/receive_input.c \
	   srcs/check_stacks.c \
	   srcs/initialise.c \

SRCS2 = srcs/push_swap.c \
		srcs/error.c \
		srcs/lst_functions.c \
		srcs/operations.c \
		srcs/receive_input.c \
		srcs/check_stacks.c \
		srcs/initialise.c \

OBJ = $(SRCS:.c=.o)
OBJ2 = $(SRCS2:.c=.o)

all : $(NAME) $(NAME2)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a

$(NAME2) : $(OBJ)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME2) $(OBJ2) libft/libft.a

clean :
	@make clean -C libft
	@rm -rf $(OBJ)
	@rm -rf $(OBJ2)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@rm -rf $(NAME2)

re : fclean all
