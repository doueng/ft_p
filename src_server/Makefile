NAME = ../server

LIBFT = ../libft
LIB = ../libft/libft.a
FT_LS_SRC = ft_ls_src
FT_LS = ft_ls

#FLAGS =
FLAGS = -Werror -Wextra -Wall -g

SRC = $(wildcard *.c ../both/*.c)

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCO) $(LIB)
	@gcc $(SRCO) $(LIB) -o $(NAME)
	@make -C $(FT_LS)

$(LIB):
	@make -C $(LIBFT)

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean:
	@/bin/rm -f $(SRCO)
	@make -C $(LIBFT) clean
	@make -C $(FT_LS) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@make -C $(FT_LS) fclean

re: fclean all
