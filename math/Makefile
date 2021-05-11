# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 00:14:29 by jkoskela          #+#    #+#              #
#    Updated: 2021/05/11 14:30:32 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libmath.a

CC			=	gcc
CFLAGS 		=	-O3 -Wall -Wextra -Werror -fPIC
SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC_BASE	=	mat_abs.c \
				mat_ceil.c \
				mat_cos.c \
				mat_dcnt.c \
				mat_dgr.c \
				mat_fabs.c \
				mat_fac.c \
				mat_flabs.c \
				mat_floor.c \
				mat_fsign.c \
				mat_intlen.c \
				mat_ipow.c \
				mat_log.c \
				mat_modf.c \
				mat_modl.c \
				mat_nextprime.c \
				mat_pow.c \
				mat_prime.c \
				mat_primefac.c \
				mat_rad.c \
				mat_roundl.c \
				mat_sign.c \
				mat_sin.c \
				mat_sqrt.c \

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
