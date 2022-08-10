NAME := libftprintf.a
SRCS := ft_printf.c
OBJS := $(SRCS:.c=.o)
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

AR := ar
ARFLAGS := crT

CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(ARFLAGS) $@ $^

$(LIBFT): $(LIBFT_DIR)
	$(MAKE) -C $(LIBFT_DIR)

clean:
	-rm $(OBJS)
	-$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	-rm $(NAME)
	-$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all