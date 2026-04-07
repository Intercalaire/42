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
	
