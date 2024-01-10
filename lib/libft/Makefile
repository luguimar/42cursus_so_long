# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luguimar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 15:40:48 by luguimar          #+#    #+#              #
#    Updated: 2023/12/19 16:53:17 by luguimar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PART1 = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strlen.c ft_strlcat.c ft_strncmp.c ft_strdup.c ft_calloc.c ft_memcpy.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c ft_memset.c ft_memmove.c ft_strlcpy.c

PART2 = ft_itoa.c ft_strjoin.c ft_split.c ft_striteri.c ft_strmapi.c ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstlast.c

EXTRA = ft_putnbr_base_fd.c ft_printf.c get_next_line.c get_next_line_utils.c free_array_of_strings.c ft_splitquote.c quotes.c quotes_utils.c ft_matrixlen.c ft_abs_value.c ft_atol.c ft_strcmp.c int_size_utils.c

SRC = ${PART1} ${PART2} ${BONUS} ${EXTRA}

OBJS = ${SRC:.c=.o}

CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I .

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
