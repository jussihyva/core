###############################################################################
#
#	Makefile
#
###############################################################################

NAME		=	libgraph.a

SRC_DIR		=	src/
INC_DIR		=	inc/
OBJ_DIR		=	obj/
DEP_DIR		=	.deps/

CC			=	gcc
CFLAGS 		=	-g -Wall -Wextra -Werror -fPIC -pthread
DFLAGS		=	-Wunreachable-code -Wconversion -Wpedantic -Wtype-limits
CPPFLAGS	=	-I $(INC_DIR)
DEPFLAGS	=	-MT $@ -MMD -MP -MF $(DEP_DIR)$*.d
COMPILE.c	=	$(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

SRC_BASE	=	digraph_new.c \
				digraph_add_node.c \
				digraph_del_node.c \
				digraph_add_edge.c \
				digraph_find_node.c \
				digraph_collect_nodes.c \
				digraph_find_edge.c \
				digraph_del_edge.c \
				digraph_find_roots.c \
				digraph_breadth_first_search.c \
				digraph_depth_first_search.c \
				digraph_find_shortest_path.c \
				digraph_edge_set_backtrack.c \
				digraph_node_reset.c \
				digraph_print_node_set_tab.c \
				digraph_collect_inbound_edges.c \
				digraph_collect_outbound_edges.c \
				digraph_collect_edges.c \
				digraph_new_amat.c \
				digraph_to_amat.c \
				digraph_print_amat.c \
				digraph_print_edge_set_dot.c \
				digraph_print_node_set_path.c \
				digraph_print_node_set.c \
				digraph_print_edge_set.c \
				digraph_clear_node_set.c \
				digraph_clear_edge_set.c \
				digraph_free_node_set.c \
				digraph_free_edge_set.c \
				digraph_new_node_set.c \
				digraph_new_edge_set.c \
				digraph_free.c \
				digraph_free_amat.c \
				digraph_breadth_first_search_mt.c \
				digraph_rng_fill.c \

SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))

all:
				@$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
				@ar -rcs $(NAME) $(OBJ)
				@echo "\\n\033[32;1mGRAPH FUNCTIONS COMPILED\033[0m \\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEP_DIR)%.d | $(OBJ_DIR) $(DEP_DIR)
				@$(COMPILE.c) $< -o $@
				@echo $@

$(OBJ_DIR):
				@mkdir -p $@

$(DEP_DIR):
				@mkdir -p $@

DEPFILES = $(addprefix $(DEP_DIR), $(SRC_BASE:.c=.d))
$(DEPFILES):

clean:
				@rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
				@rm -rf $(NAME);

re: fclean all

.PHONY: all fclean clean re

include $(wildcard $(DEPFILES))