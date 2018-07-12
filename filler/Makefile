# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 11:19:07 by zbatik            #+#    #+#              #
#    Updated: 2018/07/12 13:33:19 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ../libft/
LIB	= $(join $(LIBFT_DIR),libft.a)
BIN = ./zbatik.filler
FILES = main.c \
		display.c \
		setup.c \
		update.c \

all:
	rm -f $(BIN)
	make -s -C $(LIBFT_DIR)
	gcc $(FLAGS) $(FILES) $(LIB) -o $(BIN)
	$(BIN)
