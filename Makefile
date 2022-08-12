NAME := libftprintf.a
SRCS := ft_print_char.c ft_print_int.c ft_print_ptr.c ft_print_uint.c ft_printf.c ft_print_percent.c ft_print_str.c ft_print_uint_hex.c ft_print_padded_str.c
OBJS := $(SRCS:.c=.o)
BONUS_SRCS := ft_flags_bonus.c
BONUS_OBJS := $(BONUS_SRCS:.c=.o)
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

AR := ar
# TODO: this is not working on mac
ARFLAGS := crT

CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

bonus: CFLAGS += -D_BONUS
bonus: clean $(LIBFT) $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(filter-out clean,$^)

clean:
	-rm $(OBJS) $(BONUS_OBJS)
	-$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	-rm $(NAME)
	-$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all