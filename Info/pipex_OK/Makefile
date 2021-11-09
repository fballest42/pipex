# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milmi <milmi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 12:50:51 by milmi             #+#    #+#              #
#    Updated: 2021/06/05 12:58:34 by milmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = pipex.c \
		free.c \
		utils.c

FLAGS= -Wall -Wextra -Werror
rm = rm -f
CC = gcc

all : $(NAME)

$(NAME) : $(LIBFT)
	@cp ./libft/libft.a .
	@$(CC) $(FLAGS) $(SRCS) libft.a -o $(NAME)
	
$(LIBFT) :
	@$(MAKE) -C ./libft
	
clean :
	@$(rm) libft.a
	@$(MAKE) -C ./libft clean
	
fclean : clean
	@$(rm) $(NAME)

re: fclean all