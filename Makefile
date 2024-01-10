# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luguimar <luguimar@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 22:33:22 by luguimar          #+#    #+#              #
#    Updated: 2024/01/10 22:59:11 by luguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c

OBJS = ${SRC:.c=.o}

CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .
MAKE = make -C
LIBFT_PATH = lib/libft
MLX_PATH = lib/mlx
LIBFT = ${LIBFT_PATH}/libft.a
MLX = ${MLX_PATH}/libmlx.a

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${LIBFT} $(MLX)
		${CC} ${OBJS} ${LIBFT} -o ${NAME}
		${CC} ${OBJS} ${MLX} -o ${NAME}

$(LIBFT):
		${MAKE} ${LIBFT_PATH}

$(MLX):
		${MAKE} ${MLX_PATH}

all: ${NAME}

clean:
		${MAKE} ${LIBFT_PATH} clean
		${RM} ${OBJS} ${MLX_PATH}

fclean: clean
		${MAKE} ${LIBFT_PATH} fclean
		${RM} ${NAME} ${MLX_PATH}

re: fclean all

.PHONY: all clean fclean re
