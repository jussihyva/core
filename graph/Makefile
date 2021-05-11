NAME		=	libgraph.a

CC			=	gcc
CFLAGS 		=	-O3 -Wall -Wextra -Werror -Wpedantic -Wtype-limits \
				-Wunreachable-code  -Wshadow -fPIC -Wconversion
SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/

SRC_BASE	=	graph_new.c \
				graph_null.c \
				graph_add_node.c \
				graph_add_edge.c \
				graph_cmp_nodes.c \
				graph_find_node.c \
				graph_find_edge.c \
				graph_find_roots.c \
				graph_bfs.c \
				graph_dfs.c \
				graph_find_shortest_path.c \
				graph_edge_backtrack.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all:
				@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
				@echo "\\n\033[32;1mGRAPH FUNCTIONS COMPILED\033[0m \\n"

$(OBJ_DIR):
				@mkdir -p $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)
				@echo $@

clean:
				@rm -rf $(OBJ_DIR);


fclean: clean
				@rm -rf $(NAME);

re: fclean all

.PHONY: all fclean clean re
