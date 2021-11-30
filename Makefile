# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fballest <fballest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 12:11:55 by fballest          #+#    #+#              #
#    Updated: 2021/11/30 19:13:16 by fballest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:

# FILE NAME #

NAME = pipex

# SOURCES #

SRC = 	pipexmain parser utils_libft utils_libft_b utils_libft_c
SRCPIP = $(addsuffix .c, $(SRC))
OBJS = $(SRCPIP:.c=.o)

# COMPILER #

CC = gcc -Wall -Wextra -Werror -g

# COLOUR DEFINITION #

BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# CLEANING INSTRUCTION #

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)==========CREATING PIPEX==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJS} $(LIBFT) -o ${NAME}
	@echo "Done"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating pipex file"

clean:
	@$(RM) $(OBJS)
	@echo "$(GREEN)==========REMOVING==========$(RESET)"
	@echo "Success normal cleaning"

fclean: clean
	@$(RM) ${NAME}
	@echo "$(GREEN)==========REMOVING ALL==========$(RESET)"
	@echo "Success deepest cleaning"

re: fclean all

bonus: all

.PHONY: all clean fclean re shell addsuffix
