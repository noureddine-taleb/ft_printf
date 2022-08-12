#include "ft_printf.h"

int ft_print_uint(unsigned int i, struct flags *flags) {
	char *str = ft_utoa_base(i, "0123456789");
	flags->plus = flags->space = flags->hash = 0;

	if (flags->dot) {
		flags->zero = 0;
		str = ft_adjust_precision(str, flags->precision, flags);
	}

	return ft_print_padded_str(str, flags, 1);
}