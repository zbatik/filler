# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/10 11:19:07 by zbatik            #+#    #+#              #
#    Updated: 2018/07/21 15:15:24 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ../libft/
LIB	= $(join $(LIBFT_DIR),libft.a)
BIN = ./zbatik.filler
FILES = main.c \
		setup.c \
		update.c \
		placement.c \
		limit.c \
	   	trim.c \
		display.c	

all:
	rm -f $(BIN)
	make -s -C $(LIBFT_DIR)
	gcc $(FLAGS) $(FILES) $(LIB) -o $(BIN)
run: all
	../resources/filler_vm -p1 ../resources/players/abanlin.filler -p2 $(BIN) -f ../resources/maps/map00

norm:
	norminette $(FILES) *.c *.h
