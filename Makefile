# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanukool <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 13:31:51 by tanukool          #+#    #+#              #
#    Updated: 2022/09/11 14:18:06 by tanukool         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIB_CFLAGS =  -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit -L$(LIBFT_DIR) -lft

SRC = main.c parse_file.c display_grid_loop.c draw_line.c matrix_ops.c matrix_transform.c
OBJ = $(SRC:.c=.o)

HDR = fdf.h

MLX = $(MLX_DIR)/libmlx.a
MLX_DIR = minilibx_macos

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = libft

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(LIB_CFLAGS) $(OBJ) -o $@

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

debug: $(SRC) $(MLX) $(LIBFT)
	$(CC) -g $(CFLAGS) $(LIB_CFLAGS) $(SRC) -o $@

norm:
	norminette $(SRC) $(HDR)

clean:
	make clean -C $(MLX_DIR)
	make fclean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
