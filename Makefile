# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwestvig <m.westvig@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 10:52:28 by mwestvig          #+#    #+#              #
#    Updated: 2018/08/15 12:45:39 by mwestvig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

FLAGS = -Wall -Werror -Wextra -I includes

SRCS = srcs/checker.c \
	   srcs/error.c \
	   srcs/lst_functions.c \

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(OBJ) libft/libft.a

clean :
	@make clean -C libft
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft
	@rm -rf $(NAME)

re : fclean all
