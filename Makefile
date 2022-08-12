NAME := libftprintf.a
SRCS := ft_print_char.c ft_print_int.c ft_print_ptr.c ft_print_uint.c ft_printf.c ft_print_percent.c ft_print_str.c ft_print_uint_hex.c ft_print_padded_str.c ft_adjust_precision.c ft_format.c
OBJS := $(SRCS:.c=.o)
BONUS_SRCS := $(filter-out ft_printf.c, $(OBJ)) ft_flags_bonus.c ft_printf_bonus.c
BONUS_OBJS := $(BONUS_SRCS:.c=.o)
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

AR := ar
ARFLAGS := cr

CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	mv $(LIBFT) $@
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(LIBFT) $(BONUS_OBJS)
	mv $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

clean:
	-rm $(OBJS) $(BONUS_OBJS)
	-$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	-rm $(NAME)
	-$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all