SRC	= philosophers.c \
		parsing.c \
		supervisor.c \
		ft_calloc.c \
		ft_action.c \
		init.c \
		ft_routine.c \
		ft_routine_utils.c \
		time.c \

OBJ	= $(SRC:.c=.o)

# Compilation
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all	

.PHONY: all clean fclean re
