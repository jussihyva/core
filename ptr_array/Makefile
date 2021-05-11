NAME		=	libparr.a

CC			=	gcc
CFLAGS 		=	-O3 -Wall -Wextra -Werror -Wpedantic -Wtype-limits -Wswitch-default -Wunreachable-code  -Wshadow -fPIC

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC_BASE	=	parr_add.c \
				parr_add_first.c \
				parr_add_last.c \
				parr_add_mult.c \
				parr_new.c \
				parr_assign.c \
				parr_free.c \
				parr_del.c \
				parr_del_first.c \
				parr_del_last.c \
				parr_get.c \
				parr_get_first.c \
				parr_get_last.c \
				parr_iter.c \
				parr_join.c \
				parr_read_file.c \
				parr_write_file.c \
				parr_split.c \
				parr_take.c \
				parr_take_first.c \
				parr_take_last.c \
				parr_search.c \
				parr_find.c \
				parr_parse.c \
				parr_write.c \
				parr_null.c \
				parr_grow.c \
				parr_copy.c \
				parr_dup.c \
				parr_rotate.c \

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
