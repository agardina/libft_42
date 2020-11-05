#FORMATTING

GREEN = "\\033[32m"
BOLD = "\\033[1m"
RESET_FORMAT = "\\033[0m"
ERASE_LINE = "\\033[A\\033[K\\033[A"

#COMPILATION

NAME = libft.a

SRC_DIR = ./src/
SRC_FILES = bubble_sort.c \
				dict_create.c \
				dict_dump.c \
				dict_get.c \
				dict_set.c \
				ft_abs.c \
				ft_atoi.c \
				ft_atoi_base.c \
				ft_atol.c \
				ft_bzero.c \
				ft_convert_base.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_itoa_base_str.c \
				ft_lstadd.c \
				ft_lstadd_tail.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_max.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_min.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_sqrt.c \
				ft_strcat.c \
				ft_strcdup.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_swap.c \
				get_next_line.c \
				hash.c \
				insertion_sort.c \
				is_int_tab_sorted.c \
				merge_sort.c \
				print_int_tab.c \
				quicksort.c \
				radix_sort.c \
				selection_sort.c

PRINTF_SRC_FILES = bin.c \
					buffer.c \
					buffer2.c \
					char.c \
					colors.c \
					hex.c \
					int_utils.c \
					loop.c \
					oct.c \
					parsing.c \
					parsing_bis.c \
					parsing_utils.c \
					pointers.c \
					signed.c \
					string.c \
					unsigned.c \
					floats/deal_inf_nan.c \
					floats/double.c \
					floats/get_bigint_info.c \
					floats/long_double.c \
					floats/op.c \
					floats/print_big_dbl.c \
					floats/print_dec_part.c \
					floats/print_int_part.c \
					floats/print_small_dbl.c \
					floats/round_up.c \
					floats/store_dbl.c \
					floats/store_ldbl.c \
					floats/utils.c
PRINTF_SRC_DIR = ft_printf/
PRINTF_SRC = $(addprefix $(PRINTF_SRC_DIR), $(PRINTF_SRC_FILES))
SRC_FILES += $(PRINTF_SRC)
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

HDR_DIR = ./inc/
HDR_FILES = dict.h \
				ft_printf_prototypes.h \
				ft_printf_structs.h \
				get_next_line.h \
				libft.h
HDR = $(addprefix $(HDR_DIR), $(HDR_FILES))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Object files related to libft created"
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(BOLD)$(NAME)$(RESET_FORMAT) [$(GREEN)OK$(RESET_FORMAT)]"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HDR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/ft_printf
	@mkdir -p $(OBJ_DIR)/ft_printf/floats
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
