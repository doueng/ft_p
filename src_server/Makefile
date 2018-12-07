NAME = ../server

LIBFT = ../libft
LIB = ../libft/libft.a

#FLAGS =
FLAGS = -Werror -Wextra -Wall -g

SRC = $(wildcard *.c ../both/*.c)

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCO) $(LIB)
	@gcc $(SRCO) $(LIB) -o $(NAME)

$(LIB):
	@make -C $(LIBFT)

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean:
	@/bin/rm -f $(SRCO)
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
