# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fprevot <fprevot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 14:15:21 by fprevot           #+#    #+#              #
#    Updated: 2024/01/23 14:15:23 by fprevot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
MLX = minilibx-linux
FLAGS = -Wall -Wextra -Werror
LFLAGS = -lft -lmlx -lXext -lX11 -lm
SRC = center_pos.c exit.c FdF.c draw.c get_point_pos.c main.c utils.c
LIBFT = libft
OBJ = $(SRC:.c=.o)

INCLUDE = -Ifdf.h -I./libft

all: $(NAME)

%.o: %.c fdf.h
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	make -C libft

$(MLX):
	make -C minilibx-linux

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx-linux
	$(CC) $(FLAGS) -L./$(LIBFT) -L./$(MLX) -o $@ $^ $(LFLAGS)

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C minilibx-linux clean

re: fclean all

.PHONY: all clean fclean re
