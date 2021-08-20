# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 21:58:50 by byahn             #+#    #+#              #
#    Updated: 2021/08/20 22:14:02 by byahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit
NAME = so_long
SOURCES = main.c check_map.c check_status.c draw1.c draw2.c get_next_line.c move_player.c read_map.c utils.c
OBJECTS = $(SOURCES:.c=.o)
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $(SOURCES)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
