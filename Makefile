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

# Src_files
SRC_FILES += ft_abs.c
SRC_FILES += ft_atoi.c
SRC_FILES += ft_atoi_base.c
SRC_FILES += ft_atol.c
SRC_FILES += ft_bzero.c
SRC_FILES += ft_convert_base.c
SRC_FILES += ft_isalnum.c
SRC_FILES += ft_isalpha.c
SRC_FILES += ft_isascii.c
SRC_FILES += ft_isdigit.c
SRC_FILES += ft_isprint.c
SRC_FILES += ft_itoa.c
SRC_FILES += ft_itoa_base_str.c
SRC_FILES += ft_max.c
SRC_FILES += ft_memalloc.c
SRC_FILES += ft_memccpy.c
SRC_FILES += ft_memchr.c
SRC_FILES += ft_memcmp.c
SRC_FILES += ft_memcpy.c
SRC_FILES += ft_memdel.c
SRC_FILES += ft_memmove.c
SRC_FILES += ft_memset.c
SRC_FILES += ft_min.c
SRC_FILES += ft_putchar.c
SRC_FILES += ft_putchar_fd.c
SRC_FILES += ft_putendl.c
SRC_FILES += ft_putendl_fd.c
SRC_FILES += ft_putnbr.c
SRC_FILES += ft_putnbr_fd.c
SRC_FILES += ft_putstr.c
SRC_FILES += ft_putstr_fd.c
SRC_FILES += ft_split.c
SRC_FILES += ft_sqrt.c
SRC_FILES += ft_strcat.c
SRC_FILES += ft_strcdup.c
SRC_FILES += ft_strchr.c
SRC_FILES += ft_strclr.c
SRC_FILES += ft_strcmp.c
SRC_FILES += ft_strcpy.c
SRC_FILES += ft_strdel.c
SRC_FILES += ft_strdup.c
SRC_FILES += ft_strequ.c
SRC_FILES += ft_striter.c
SRC_FILES += ft_striteri.c
SRC_FILES += ft_strjoin.c
SRC_FILES += ft_strlcat.c
SRC_FILES += ft_strlen.c
SRC_FILES += ft_strmap.c
SRC_FILES += ft_strmapi.c
SRC_FILES += ft_strncat.c
SRC_FILES += ft_strncmp.c
SRC_FILES += ft_strncpy.c
SRC_FILES += ft_strnequ.c
SRC_FILES += ft_strnew.c
SRC_FILES += ft_strnstr.c
SRC_FILES += ft_strrchr.c
SRC_FILES += ft_strsplit.c
SRC_FILES += ft_strstr.c
SRC_FILES += ft_strsub.c
SRC_FILES += ft_strtrim.c
SRC_FILES += ft_tolower.c
SRC_FILES += ft_toupper.c
SRC_FILES += ft_swap.c
SRC_FILES += get_next_line.c
SRC_FILES += hash.c
SRC_FILES += is_int_tab_sorted.c
SRC_FILES += print_int_tab.c

# Dict
SRC_FILES += dict/dict_create.c
SRC_FILES += dict/dict_dump.c
SRC_FILES += dict/dict_get.c
SRC_FILES += dict/dict_set.c

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
	@mkdir -p $(OBJ_DIR)/dict
	@mkdir -p $(OBJ_DIR)/ft_printf
	@mkdir -p $(OBJ_DIR)/ft_printf/floats
	@mkdir -p $(OBJ_DIR)/int_vector
	@mkdir -p $(OBJ_DIR)/list
	@mkdir -p $(OBJ_DIR)/queue
	@mkdir -p $(OBJ_DIR)/sort
	@mkdir -p $(OBJ_DIR)/stack

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
