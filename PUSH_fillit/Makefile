# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtai <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 11:09:52 by dtai              #+#    #+#              #
#    Updated: 2019/10/23 17:05:13 by dtai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 
FLAGS = -Wall -Wextra -Werror
SRCS = \
fillit_srcs/free_tetri.c \
fillit_srcs/read_tetri.c \
fillit_srcs/main.c \
fillit_srcs/fillit.c \
fillit_srcs/read_file_tetri.c
OBJECTS = free_tetri.o read_tetri.o main.o fillit.o read_file_tetri.o
LIB = libft/

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIB)
	gcc -o $(NAME) $(OBJECTS) $(LIB)libft.a -I $(LIB)includes/

$(OBJECTS):
	gcc $(FLAGS) -c $(SRCS) -I $(LIB)includes/

clean:
	make -C $(LIB) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIB) fclean
	rm -f $(NAME)

re: fclean all
