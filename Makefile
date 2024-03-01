# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 22:33:22 by luguimar          #+#    #+#              #
#    Updated: 2024/03/01 05:21:45 by luguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c src/map_ckeck.c src/flood_fill.c src/flood_fill_extra.c

OBJS = ${SRC:.c=.o}

CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
MAKE = make -C
LIBFT_PATH = lib/libft
MLX_PATH = lib/mlx
LIBFT = ${LIBFT_PATH}/libft.a
MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${LIBFT} $(MLX)
		${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME}

$(LIBFT):
		${MAKE} ${LIBFT_PATH}

$(MLX):
		${MAKE} ${MLX_PATH}

all: ${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${MAKE} ${MLX_PATH} clean
		${RM} ${OBJS}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
