
# Basic variables
NAME = Animal
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -f
CLEAR = clear

# Files
SRC	= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

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
