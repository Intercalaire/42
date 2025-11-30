# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgodart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 11:38:34 by vgodart           #+#    #+#              #
#    Updated: 2024/04/10 12:50:20 by vgodart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Basic variables
NAME = ClapTrap
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -f
CLEAR = clear

# Files
SRC	= main.cpp ClapTrap.cpp ScavTrap.cpp

OBJ	= $(SRC:.cpp=.o)

# Compilation
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

.c.o:
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)	

.PHONY: all clean fclean re
