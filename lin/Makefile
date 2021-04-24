# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 00:14:29 by jkoskela          #+#    #+#              #
#    Updated: 2021/04/25 01:12:07 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	liblin.a

CC			=	gcc
FLAGS 		=	-03 -Wall -Wextra -Werror -Wpedantic -Wtype-limits -Wswitch-default -Wunreachable-code -Wpadded -Wshadow -fPIC

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC_BASE	=	lin_m4_getcol.c \
				lin_m4_rotx.c \
				lin_m4xm4_r.c \
				lin_v4_mag.c \
				lin_m4_getrow.c \
				lin_m4_roty.c \
				lin_m4xv4_r.c \
				lin_v4_norm.c \
				lin_m4_id.c \
				lin_m4_rotz.c \
				lin_v4_add.c \
				lin_v4_sub.c \
				lin_m4_print.c \
				lin_m4_transform.c \
				lin_v4_cross.c \
				lin_m4_proj.c \
				lin_m4_translate.c \
				lin_v4_dot.c \

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
