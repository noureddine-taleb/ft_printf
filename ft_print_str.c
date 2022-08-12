#include "ft_printf.h"

int ft_print_str(char *str, struct flags *flags) {
	flags->hash = flags->plus = flags->space = flags->zero = 0;
	return ft_print_padded_str(str, flags, 0);
}