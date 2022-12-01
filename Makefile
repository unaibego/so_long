# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2022/12/01 14:03:46 by ubegona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)
SRCS =  main.c
CC = gcc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror 
 
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
#$< gure leheneng dependentziaren izena da, kasu honetan %.c

clean: 
	rm -f *.o
fclean: clean 
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
