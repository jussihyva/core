# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 00:14:29 by jkoskela          #+#    #+#              #
#    Updated: 2021/05/04 17:37:04 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libmap.a

CC			=	gcc
FLAGS 		=	-g -Wall -Wextra -Werror -Wpedantic -Wtype-limits -Wswitch-default -Wunreachable-code -Wpadded -Wshadow -fPIC

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC_BASE	=	map_add.c \
				map_get.c \
				map_new.c \
				map_grow.c \
				map_null_node.c \
				map_hash_1.c \
				map_probe_quad_pow2.c \
				map_resize_pow2.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
DIR			=	$(sort $(dir $(OBJ)))

all:
				$(MAKE) -j $(NAME)

$(NAME): $(OBJ) Makefile
				@ar -rcs $(NAME) $(OBJ)
				@echo "\\n\033[32;MAP FUNCTIONS COMPILED\033[0m \\n"

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
