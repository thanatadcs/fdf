# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 13:31:51 by tanukool          #+#    #+#              #
#    Updated: 2022/09/10 01:31:54 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

SRC = main.c parse_file.c
OBJ = $(SRC:.c=.o)

HDR = fdf.h

MLX = $(MLX_DIR)/libmlx.a
MLX_DIR = minilibx_macos

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = libft

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

norm:
	norminette $(SRC) $(HDR)

clean:
	make clean -C $(MLX_DIR)
	make fclean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
