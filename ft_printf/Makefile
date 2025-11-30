# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgodart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 13:20:19 by vgodart           #+#    #+#              #
#    Updated: 2023/11/01 16:28:59 by vgodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = ft_strlen.c \
		ft_putstr_fd.c \
		ft_printf.c \
		ft_putnbr_base_fd.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_hexa_fd.c \
	

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 

re: fclean all


.PHONY: all clean fclean re
	
