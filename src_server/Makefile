NAME = ../server
BOTH = ../both/

LIB = ../libft/libft.a
LIBFT = ../libft
FT_LS = ../src_ft_ls

FLAGS = -Werror -Wextra -Wall

SRC = cmd_cd.c \
		cmd_get.c \
		cmd_help.c \
		cmd_ls.c \
		cmd_mkdir.c \
		cmd_put.c \
		cmd_pwd.c \
		cmd_quit.c \
		cmd_rmdir.c \
		server.c \
		start_listening.c \
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
