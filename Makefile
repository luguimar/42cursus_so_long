# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 22:33:22 by luguimar          #+#    #+#              #
#    Updated: 2024/03/05 13:12:23 by luguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c src/map_ckeck.c src/flood_fill.c src/map_check_extra.c src/flood_fill_extra.c src/mlx_config.c src/movements.c

SRC_BONUS = src_bonus/main_bonus.c src_bonus/map_ckeck_bonus.c src_bonus/flood_fill_bonus.c src_bonus/map_check_extra_bonus.c src_bonus/flood_fill_extra_bonus.c src_bonus/mlx_config_bonus.c src_bonus/movements_bonus.c src_bonus/enemies_bonus.c src_bonus/mlx_config_extra_bonus.c

BONUS_OBJS = ${SRC_BONUS:.c=.o}

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
		if [ ! -d "${MLX_PATH}" ]; then \
		${DOWNLOAD} ${MINILIBX_FILE} ${MINILIBX_URL}; \
		${EXTRACT} ${MINILIBX_FILE} -C ${LIBRARIES}; \
		${REMOVE} ${MINILIBX_FILE}; \
		${MOVE} lib/minilibx-linux ${MLX_PATH}; \
		fi

all: ${NAME}

bonus: ${MLX} ${BONUS_OBJS} ${LIBFT}
		${CC} ${BONUS_OBJS} ${LIBFT} ${MLX} -o ${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		if [ -d "${MLX_PATH}" ]; then ${MAKE} ${MLX_PATH} clean; fi
		${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		if [ -d "${MLX_PATH}" ]; then ${RM} -r ${MLX_PATH}; fi
		${RM} ${NAME}

re: fclean all

.PHONY: download-and-extract-mlx all clean fclean re
