#include "./libft/libft.h"
#include "ft_printf.h"

int ft_print_char(char c, struct flags *flags) {
	char buf[2] = {c, 0};
	flags->hash = flags->plus = flags->space = flags->zero = 0;
	return ft_print_padded_str(buf, flags, 0);
}