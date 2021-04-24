# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 00:14:29 by jkoskela          #+#    #+#              #
#    Updated: 2021/04/24 21:49:44 by julius           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libarr.a

CC			=	gcc
CFLAGS 		=	-O3 -Wall -Wextra -Werror -Wpedantic -Wtype-limits \
				-Wunreachable-code -Wpadded -Wshadow -fPIC -Wconversion
SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC_BASE	=	arr_add.c \
				arr_add_first.c \
				arr_add_last.c \
				arr_add_mult.c \
				arr_new.c \
				arr_put.c \
				arr_free.c \
				arr_del.c \
				arr_del_first.c \
				arr_del_last.c \
				arr_get.c \
				arr_get_first.c \
				arr_get_last.c \
				arr_iter.c \
				arr_iter_range.c \
				arr_join.c \
				arr_join_mult.c \
				arr_take.c \
				arr_take_first.c \
				arr_take_last.c \
				arr_search.c \
				arr_find.c \
				arr_parse.c \
				arr_null.c \
				arr_grow.c \
				arr_copy.c \
				arr_rotate.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all:
				$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
				@ar -rcs $(NAME) $(OBJ)
				@echo "\\n\033[32;1mARRAY FUNCTIONS COMPILED\033[0m \\n"

$(OBJ_DIR):
				@mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

clean:
				@rm -rf $(OBJ_DIR);


fclean: clean
				@rm -rf $(NAME);

re: fclean all

.PHONY: all fclean clean re
