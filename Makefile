# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2022/12/20 11:21:09 by ubegona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)
SRCS =  main.c make_move.c make_map.c save_data.c libft.c errors.c check_map.c ft_itoa.c
CC = gcc -fsanitize=address -g3
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
 
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
#$< gure leheneng dependentziaren izena da, kasu honetan %.c

clean: 
	rm -f *.o
fclean: clean 
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
