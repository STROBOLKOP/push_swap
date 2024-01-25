# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efret <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:05:01 by efret             #+#    #+#              #
#    Updated: 2024/01/25 14:46:22 by efret            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

SRCS = $(wildcard *.c)

RESET = \e[0m
GREEN = \e[38;5;40m
YELLOW = \e[33m
UP = \e[F
CLEAR_LINE = \e[2K\r

all: ${NAME}

${NAME}: ${LIBFT}/${LIBFT}.a ${SRCS}
	@echo -n "${YELLOW}"
	${CC} ${CFLAGS} ${SRCS} ${LIBFT}/${LIBFT}.a -o ${NAME}
	@echo "${GREEN}${NAME} Done compiling.${RESET}"

${LIBFT}/${LIBFT}.a:
	@make -sC ${LIBFT}

clean:
	@make fclean -sC ${LIBFT}

fclean: clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
