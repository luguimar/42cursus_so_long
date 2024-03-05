# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 22:33:22 by luguimar          #+#    #+#              #
#    Updated: 2024/03/05 06:05:34 by luguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c src/map_ckeck.c src/flood_fill.c src/map_check_extra.c src/flood_fill_extra.c src/mlx_config.c src/movements.c

OBJS = ${SRC:.c=.o}

CC = cc -g
MOVE = mv
REMOVE = rm -f
EXTRACT = tar -xvf
DOWNLOAD = wget -O
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
MAKE = make -C
LIBRARIES = lib
MINILIBX_FILE = minilibx-linux.tgz
MINILIBX_URL = https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz
LIBFT_PATH = lib/libft
MLX_PATH = lib/mlx
LIBFT = ${LIBFT_PATH}/libft.a
MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

$(NAME): $(MLX) ${OBJS} ${LIBFT}
		${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

$(LIBFT):
		${MAKE} ${LIBFT_PATH}

$(MLX): download-and-extract-mlx
		${MAKE} ${MLX_PATH}

download-and-extract-mlx:
		${DOWNLOAD} ${MINILIBX_FILE} ${MINILIBX_URL}
		${EXTRACT} ${MINILIBX_FILE} -C ${LIBRARIES}
		${REMOVE} ${MINILIBX_FILE}
		${MOVE} lib/minilibx-linux ${MLX_PATH}

all: ${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		if [ -d "${MLX_PATH}" ]; then ${MAKE} ${MLX_PATH} clean; fi
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		if [ -d "${MLX_PATH}" ]; then ${RM} -r ${MLX_PATH}; fi
		${RM} ${NAME}

re: fclean all

.PHONY: download-and-extract-mlx all clean fclean re
