NAME = ../client
BOTH = ../both/

LIB = ../libft/libft.a
LIBFT = ../libft
FT_LS = ../src_ft_ls

FLAGS = -Werror -Wextra -Wall

SRC = client.c \
		connect.c \
		getter.c \
		print_response.c \
		sender.c \
		$(BOTH)add_to_cwd.c \
		$(BOTH)check_path.c \
		$(BOTH)get_file_mmap.c \
		$(BOTH)get_msg.c \
		$(BOTH)get_socket.c \
		$(BOTH)send_msg.c \
		$(BOTH)write_to_file.c \
		$(BOTH)x.c

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCO)
	@make -C $(LIBFT)
	@make -C $(FT_LS)
	@gcc $(SRCO) $(LIB) -o $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) $< -o $@

clean:
	@/bin/rm -f $(SRCO)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
