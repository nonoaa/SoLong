# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 21:58:50 by byahn             #+#    #+#              #
#    Updated: 2021/08/21 01:15:10 by byahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx
OPTIONS = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit
NAME = so_long
SOURCES = main.c check_map.c check_status.c draw1.c draw2.c get_next_line.c move_player.c read_map.c utils.c
SOURCES_BONUS = main_bonus.c check_map_bonus.c check_status_bonus.c check_status_enemy_bonus.c draw1_bonus.c draw2_bonus.c draw_enemy_bonus.c get_next_line_bonus.c move_player_bonus.c read_map_bonus.c utils_bonus.c ft_itoa_bonus.c
OBJECTS = $(SOURCES:%.c=%.o)
OBJECTS_BONUS = $(SOURCES_BONUS:%.c=%.o)
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
	rm -f $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(NAME) $(OBJECTS_BONUS)

.PHONY: all clean fclean re bonus
