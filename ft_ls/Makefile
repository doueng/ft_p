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

NAME = ../bin/ft_ls
FLAGS = -Wextra -Wall -Werror
LIB = ../libft/libft.a

SRC = main.c get_options.c ft_error.c get_directories.c get_files.c printer.c \
		creator.c btree_functions.c print_l.c \
		btree_cmp.c print_extended.c print_pages.c print_pages_ini.c

SRCO = ${SRC:%.c=%.o}

all: $(NAME)

$(NAME): $(LIB) $(SRCO)
	gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all make_lib
