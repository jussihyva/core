# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 00:14:29 by jkoskela          #+#    #+#              #
#    Updated: 2021/05/11 19:02:18 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libmath.a

CC			=	gcc
CFLAGS 		=	-O3 -Wall -Wextra -Werror -fPIC
SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC_BASE	=	math_abs.c \
				math_ceil.c \
				math_cos.c \
				math_dcnt.c \
				math_dgr.c \
				math_fabs.c \
				math_fac.c \
				math_flabs.c \
				math_floor.c \
				math_fsign.c \
				math_intlen.c \
				math_ipow.c \
				math_log.c \
				math_modf.c \
				math_modl.c \
				math_nextprime.c \
				math_pow.c \
				math_prime.c \
				math_primefac.c \
				math_rad.c \
				math_roundl.c \
				math_sign.c \
				math_sin.c \
				math_sqrt.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all:
				$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
				@ar -rcs $(NAME) $(OBJ)
				@echo "\\n\033[32;1mMATH FUNCTIONS COMPILED\033[0m \\n"

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
