NAME = push_swap
CC = gcc
CFLAGS = #-g -Wall -Werror -Wextra
RM = rm -rf
FT_PRINTF = ./ft_printf/libftprintf.a
SRCS  = push_swap.c ./src/check_inputs.c ./src/stack_utils.c ./src/swap.c ./src/push.c ./src/rotate.c ./src/rev_rotate.c

all: $(NAME)

$(NAME): $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SRCS) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
	make bonus -C ./ft_printf

clean:
	$(RM) $(NAME)

fclean: 	clean

re: fclean all

.PHONY:  all clean fclean re
