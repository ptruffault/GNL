NAME		= test

LIB_PATH	= ./libft/

LIB		= -Llibft/ -lft

SRC		= get_next_line.c main.c

CFLAGS		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH) all
	@gcc $(CFLAGS) $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "\033[92mCreate $(NAME)\033[0m"

clean:
	@make -C $(LIB_PATH) clean

fclean:
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@echo "\033[92mClean $(NAME)\033[0m"

re:	fclean all

.PHONY: all clean fclean re
