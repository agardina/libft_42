## FORMATTING

GREEN = "\\033[32m"
BOLD = "\\033[1m"
RESET_FORMAT = "\\033[0m"
ERASE_LINE = "\\033[A\\033[K\\033[A"

## COMPILATION

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

## HEADERS

HDR_DIR = ./inc/
HDR_FILES = dict.h \
				ft_printf_prototypes.h \
				ft_printf_structs.h \
				get_next_line.h \
				int_vectors.h \
				libft.h \
				queue.h \
				stack.h \
HDR = $(addprefix $(HDR_DIR), $(HDR_FILES))

## SOURCES

SRC_DIR = ./src/

# Char
SRC_FILES += char/ft_isalnum.c
SRC_FILES += char/ft_isalpha.c
SRC_FILES += char/ft_isprint.c
SRC_FILES += char/ft_tolower.c
SRC_FILES += char/ft_toupper.c

# Conversion
SRC_FILES += conversion/ft_atoi.c
SRC_FILES += conversion/ft_atoi_base.c
SRC_FILES += conversion/ft_atol.c
SRC_FILES += conversion/ft_convert_base.c
SRC_FILES += conversion/ft_itoa.c
SRC_FILES += conversion/ft_itoa_base_str.c

# Dict
SRC_FILES += dict/dict_create.c
SRC_FILES += dict/dict_dump.c
SRC_FILES += dict/dict_get.c
SRC_FILES += dict/dict_set.c

# Display
SRC_FILES += display/ft_putchar.c
SRC_FILES += display/ft_putchar_fd.c
SRC_FILES += display/ft_putendl.c
SRC_FILES += display/ft_putendl_fd.c
SRC_FILES += display/ft_putnbr.c
SRC_FILES += display/ft_putnbr_fd.c
SRC_FILES += display/ft_putstr.c
SRC_FILES += display/ft_putstr_fd.c

# ft_printf
SRC_FILES += ft_printf/bin.c
SRC_FILES += ft_printf/buffer.c
SRC_FILES += ft_printf/buffer2.c
SRC_FILES += ft_printf/char.c
SRC_FILES += ft_printf/colors.c
SRC_FILES += ft_printf/hex.c
SRC_FILES += ft_printf/int_utils.c
SRC_FILES += ft_printf/loop.c
SRC_FILES += ft_printf/oct.c
SRC_FILES += ft_printf/parsing.c
SRC_FILES += ft_printf/parsing_bis.c
SRC_FILES += ft_printf/parsing_utils.c
SRC_FILES += ft_printf/pointers.c
SRC_FILES += ft_printf/signed.c
SRC_FILES += ft_printf/string.c
SRC_FILES += ft_printf/unsigned.c
SRC_FILES += ft_printf/floats/deal_inf_nan.c
SRC_FILES += ft_printf/floats/double.c
SRC_FILES += ft_printf/floats/get_bigint_info.c
SRC_FILES += ft_printf/floats/long_double.c
SRC_FILES += ft_printf/floats/op.c
SRC_FILES += ft_printf/floats/print_big_dbl.c
SRC_FILES += ft_printf/floats/print_dec_part.c
SRC_FILES += ft_printf/floats/print_int_part.c
SRC_FILES += ft_printf/floats/print_small_dbl.c
SRC_FILES += ft_printf/floats/round_up.c
SRC_FILES += ft_printf/floats/store_dbl.c
SRC_FILES += ft_printf/floats/store_ldbl.c
SRC_FILES += ft_printf/floats/utils.c

# Get_next_line
SRC_FILES += get_next_line/get_next_line.c

# Int tab
SRC_FILES += int_tab/is_int_tab_sorted.c
SRC_FILES += int_tab/print_int_tab.c

# Int vector
SRC_FILES += int_vector/int_vector_append.c
SRC_FILES += int_vector/int_vector_create.c
SRC_FILES += int_vector/int_vector_destroy.c
SRC_FILES += int_vector/int_vector_print.c
SRC_FILES += int_vector/int_vector_realloc.c
SRC_FILES += int_vector/is_int_vector_sorted.c

# List
SRC_FILES += list/ft_lstadd.c
SRC_FILES += list/ft_lstadd_tail.c
SRC_FILES += list/ft_lstdel.c
SRC_FILES += list/ft_lstdelone.c
SRC_FILES += list/ft_lstiter.c
SRC_FILES += list/ft_lstmap.c
SRC_FILES += list/ft_lstnew.c
SRC_FILES += list/ft_lstsize.c

# Maths
SRC_FILES += maths/ft_abs.c
SRC_FILES += maths/ft_max.c
SRC_FILES += maths/ft_min.c
SRC_FILES += maths/ft_sqrt.c

# Memory
SRC_FILES += memory/ft_bzero.c
SRC_FILES += memory/ft_memalloc.c
SRC_FILES += memory/ft_memccpy.c
SRC_FILES += memory/ft_memchr.c
SRC_FILES += memory/ft_memcmp.c
SRC_FILES += memory/ft_memcpy.c
SRC_FILES += memory/ft_memdel.c
SRC_FILES += memory/ft_memmove.c
SRC_FILES += memory/ft_memset.c

# Other
SRC_FILES += other/ft_swap.c
SRC_FILES += other/hash.c

# Queue
SRC_FILES += queue/queue_dequeue.c
SRC_FILES += queue/queue_destroy.c
SRC_FILES += queue/queue_enqueue.c
SRC_FILES += queue/queue_peek.c
SRC_FILES += queue/queue_size.c

# Sort
SRC_FILES += sort/bubble_sort.c
SRC_FILES += sort/insertion_sort.c
SRC_FILES += sort/merge_sort.c
SRC_FILES += sort/quicksort.c
SRC_FILES += sort/radix_sort.c
SRC_FILES += sort/selection_sort.c

# Stack
SRC_FILES += stack/stack_destroy.c
SRC_FILES += stack/stack_peek.c
SRC_FILES += stack/stack_pop.c
SRC_FILES += stack/stack_push.c
SRC_FILES += stack/stack_size.c

# String
SRC_FILES += string/ft_split.c
SRC_FILES += string/ft_strcat.c
SRC_FILES += string/ft_strcdup.c
SRC_FILES += string/ft_strchr.c
SRC_FILES += string/ft_strclr.c
SRC_FILES += string/ft_strcmp.c
SRC_FILES += string/ft_strcpy.c
SRC_FILES += string/ft_strdel.c
SRC_FILES += string/ft_strdup.c
SRC_FILES += string/ft_strequ.c
SRC_FILES += string/ft_striter.c
SRC_FILES += string/ft_striteri.c
SRC_FILES += string/ft_strjoin.c
SRC_FILES += string/ft_strlcat.c
SRC_FILES += string/ft_strlen.c
SRC_FILES += string/ft_strmap.c
SRC_FILES += string/ft_strmapi.c
SRC_FILES += string/ft_strncat.c
SRC_FILES += string/ft_strncmp.c
SRC_FILES += string/ft_strncpy.c
SRC_FILES += string/ft_strnequ.c
SRC_FILES += string/ft_strnew.c
SRC_FILES += string/ft_strnstr.c
SRC_FILES += string/ft_strrchr.c
SRC_FILES += string/ft_strsplit.c
SRC_FILES += string/ft_strstr.c
SRC_FILES += string/ft_strsub.c
SRC_FILES += string/ft_strtrim.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

## OBJECT FILES

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

## RULES

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Object files related to libft created"
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(BOLD)$(NAME)$(RESET_FORMAT) [$(GREEN)OK$(RESET_FORMAT)]"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/char
	@mkdir -p $(OBJ_DIR)/conversion
	@mkdir -p $(OBJ_DIR)/dict
	@mkdir -p $(OBJ_DIR)/display
	@mkdir -p $(OBJ_DIR)/ft_printf
	@mkdir -p $(OBJ_DIR)/ft_printf/floats
	@mkdir -p $(OBJ_DIR)/get_next_line
	@mkdir -p $(OBJ_DIR)/int_tab
	@mkdir -p $(OBJ_DIR)/int_vector
	@mkdir -p $(OBJ_DIR)/list
	@mkdir -p $(OBJ_DIR)/maths
	@mkdir -p $(OBJ_DIR)/memory
	@mkdir -p $(OBJ_DIR)/other
	@mkdir -p $(OBJ_DIR)/queue
	@mkdir -p $(OBJ_DIR)/sort
	@mkdir -p $(OBJ_DIR)/stack
	@mkdir -p $(OBJ_DIR)/string

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HDR) Makefile
	@$(CC) $(CFLAGS) -I$(HDR_DIR) -c -o $@ $<
	@echo "Compiled: $*.o [$(GREEN)OK$(RESET_FORMAT)]"
	@echo "$(ERASE_LINE)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files related to libft deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re:
	@$(MAKE) fclean
	@echo ""
	@$(MAKE) all

.PHONY: all clean fclean re
