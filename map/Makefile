# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 00:14:29 by jkoskela          #+#    #+#              #
#    Updated: 2021/04/19 21:20:52 by julius           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libmap.a

CC			=	clang
CFLAGS 		=	-O3 -Wall -Wextra -Werror -Wpedantic -Wtype-limits -Wswitch-default -Wunreachable-code -Wpadded -Wshadow -fPIC

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC_BASE	=	map_add.c \
				map_add_first.c \
				map_add_last.c \
				map_add_mult.c \
				map_new.c \
				map_assign.c \
				map_free.c \
				map_del.c \
				map_del_first.c \
				map_del_last.c \
				map_get.c \
				map_get_first.c \
				map_get_last.c \
				map_iterate.c \
				map_join.c \
				map_read_file.c \
				map_write_file.c \
				map_split.c \
				map_take.c \
				map_take_first.c \
				map_take_last.c \
				map_search.c \
				map_find.c \
				map_parse.c \
				map_write.c \
				map_null.c \
				map_grow.c \
				map_copy.c \
				map_dup.c \
				map_rotate.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
DIR			=	$(sort $(dir $(OBJ)))

all:
				$(MAKE) -j $(NAME)

$(NAME): $(OBJ) Makefile
				@ar -rcs $(NAME) $(OBJ)
				@echo "\\n\033[32;1mMAP FUNCTIONS COMPILED\033[0m \\n"

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
