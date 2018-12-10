# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dengstra <dengstra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/06 18:30:14 by douglas           #+#    #+#              #
#    Updated: 2017/09/11 15:42:04 by dengstra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
FLAGS = -Wextra -Wall -Werror
LIBFT = ./libft
LIB = libft/libft.a

SRC = main.c get_options.c ft_error.c get_directories.c get_files.c printer.c \
		creator.c btree_functions.c print_l.c \
		btree_cmp.c print_extended.c print_pages.c print_pages_ini.c

SRCO = ${SRC:%.c=%.o}

all: $(NAME)

$(NAME): $(LIB) $(SRCO)
	gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)

$(LIB):
	@make -C $(LIBFT)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	/bin/rm -f $(SRCO)
	make clean -C $(LIBFT)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean re all make_lib
