NAME = libprint.a

OBJ_DIR = obj
SRC_DIR = src
DEP_DIR = .deps

MATH_SRC = $(addprefix src/, \
	ft_dpow.c \
	ft_abs.c \
	ft_fabs.c \
	ft_isnan.c \
	ft_isnegative.c \
	ft_isneginf.c \
	ft_isposinf.c \
	ft_modf.c \
	ft_uintmax_pow.c \
	ft_atoi.c \
)

MEM_SRC = $(addprefix src/, \
	ft_realloc.c \
)

STR_SRC = $(addprefix src/, \
	ft_isdigit.c \
	ft_isspace.c \
	ft_intmax_itoa_base.c \
	ft_uintmax_itoa_base.c \
)

PRINTF_SRC = $(addprefix src/, \
	ft_asprintf.c \
	ft_dprintf.c \
	print.c \
	format.c \
	ft_vasprintf.c \
	conversion_specs.c \
	dtoa.c \
	parse_chars.c \
	parse_doubles.c \
	parse_pointers.c \
	parse_signed_integers.c \
	parse_unsigned_integers.c \
	parse_helpers.c \
	parser.c \
	round_double.c \
)

SRC = $(MATH_SRC) \
	$(MEM_SRC) \
	$(STR_SRC) \
	$(PRINTF_SRC)

CC = gcc
CFLAGS = -O3 -Wall -Wextra -Werror #-fsanitize=address
CPPFLAGS = -I . -I ../inc -I inc
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d
COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))
	@echo "Create $@"
	@ar rc $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DEP_DIR) $(OBJ_DIR)
	@$(COMPILE.c) -o $@ $<

$(DEP_DIR): ; @mkdir -p $@

$(OBJ_DIR): ; @mkdir -p $@

DEPFILES = $(addprefix $(DEP_DIR)/, $(SRC:.c=.d))
$(DEPFILES):

clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

include $(wildcard $(DEPFILES))
