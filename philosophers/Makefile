# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maxime <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 17:00:59 by maxime            #+#    #+#              #
#    Updated: 2024/05/17 08:31:03 by maxime           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### APPELLATION ###

NAME		= philo

CC		= gcc -pthread
FLAGS		= -Wall -Werror -Wextra -g
INCLUDES	= -I ./includes

HEADER_SRCS	= philo.h
HEADER_DIR	= includes/
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MANDATORY_SRCS	= main.c utils.c init_philo.c check.c check_death.c routine.c
MANDATORY_DIR	= srcs/
MANDATORY_PATH	= $(addprefix $(MANDATORY_DIR), $(MANDATORY_SRCS))
OBJ_MANDATORY	= $(MANDATORY_PATH:.c=.o)

OBJ_DIR		= objs/

### REGLES ###

%.o:%.c $(HEADER) Makefile
	@$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJ_MANDATORY)
	@$(CC) $(OBJ_MANDATORY) $(INCLUDE) -o $(NAME)

all : $(NAME)

clean	:
	@/bin/rm -rf $(OBJ_MANDATORY)

fclean :
	@/bin/rm -rf $(OBJ_MANDATORY)
	@rm -f $(NAME)

re : fclean all

.PHONY: re, fclean, clean, all
