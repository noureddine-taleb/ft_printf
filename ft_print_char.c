#include "./libft/libft.h"
#include "ft_printf.h"

int ft_print_char(char c, struct flags *flags) {
	flags->hash = flags->plus = flags->space = flags->zero = 0;
	return ft_print_padded_mem(&c, 1, flags, 0);
}