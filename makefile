# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efret <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:05:01 by efret             #+#    #+#              #
#    Updated: 2024/02/01 17:32:49 by elias            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
LIBFT = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g

SRCS_COMMON = $(wildcard src/utils/*.c)\
			  $(wildcard src/commands/*.c)
SRCS = src/push_swap_main.c ${SRCS_COMMON}
SRCS_BONUS = src/checker_main.c ${SRCS_COMMON}\
			 $(wildcard src/bonus/*.c)

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

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${LIBFT}/${LIBFT}.a ${SRCS_BONUS}
	@echo -n "${YELLOW}"
	${CC} ${CFLAGS} ${SRCS_BONUS} ${LIBFT}/${LIBFT}.a -o ${NAME_BONUS}
	@echo "${GREEN}${NAME_BONUS} Done compiling.${RESET}"

${LIBFT}/${LIBFT}.a:
	@make -sC ${LIBFT}

clean:
	@make fclean -sC ${LIBFT}

fclean: clean
	@rm -rf ${NAME}
	@rm -rf ${NAME_BONUS}

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus
