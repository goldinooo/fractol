# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: retahri <retahri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 00:39:34 by retahri           #+#    #+#              #
#    Updated: 2025/03/24 03:24:45 by retahri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror
# BFLAGS = -lglfw -framework Cocoa -framework OpenGL
BFLAGS = -lglfw -L/goinfre/retahri/homebrew/Cellar/glfw/3.4/lib -framework Cocoa -framework OpenGL


SRC = utils.c render.c engine.c main.c types.c hooks.c 
OBJ = $(SRC:.c=.o)
MLX_PATH = $(HOME)/libs/mlx
MLX = $(MLX_PATH)/build/libmlx42.a

INCLUDES = -I$(MLX_PATH)/include 

all : $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX) $(INCLUDES) $(BFLAGS) -o $(NAME) $(OBJ)
	
$(MLX):
	cmake -s  $(MLX_PATH) -B $(MLX_PATH)/build --DDEBUG=1
	make -C $(MLX_PATH)/build -j
%.o: %.c fractol.h
	$(CC) $(CFLAGS)  $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)


fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re