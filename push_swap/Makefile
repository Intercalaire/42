# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgodart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 11:38:34 by vgodart           #+#    #+#              #
#    Updated: 2024/04/03 11:38:37 by vgodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Basic variables
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CLEAR = clear

# Files
SRC	= ./src/push_swap.c\
	  ./src/lst_utils.c\
	  ./src/push.c\
	  ./src/radix.c\
	  ./src/reverse.c\
	  ./src/rotate.c\
	  ./src/swap.c\
	  ./src/index.c\
	  ./src/simple_sort.c\
	  ./src/simple_sort_utils.c \
	  ./src/utils.c\

OBJ	= $(SRC:.c=.o)

# Libft
LIBFT_PATH	= ./Libft
LIBFT_NAME	= ./Libft/Libft.a

# Compilation
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all	

.PHONY: all clean fclean re
