# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 00:14:29 by jkoskela          #+#    #+#              #
#    Updated: 2021/04/24 21:49:53 by julius           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libmem.a

CC			=	gcc
FLAGS 		=	-g -Wall -Wextra -Werror -Wpedantic -Wtype-limits -Wswitch-default -Wunreachable-code -Wpadded -Wshadow -fPIC

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC_BASE	=	mem_alloc.c \
				mem_zero.c \
				mem_calloc.c \
				mem_ccpy.c \
				mem_chr.c \
				mem_cmp.c \
				mem_cpy.c \
				mem_cpy_safe.c \
				mem_del.c \
				mem_move.c \
				mem_set.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
DIR			=	$(sort $(dir $(OBJ)))

all:
				$(MAKE) -j $(NAME)

$(NAME): $(OBJ) Makefile
				@ar -rcs $(NAME) $(OBJ)
				@echo "\\n\033[32;1mMEMORY FUNCTIONS COMPILED\033[0m \\n"

$(DIR):
				@mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile | $(DIR)
				@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

clean:
				@rm -rf $(OBJ_DIR);


fclean: clean
				@rm -rf $(NAME);

re: fclean
				@$(MAKE) -j $(NAME)

.PHONY: fclean clean re
