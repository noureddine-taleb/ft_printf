#include "ft_printf.h"

int ft_print_uint_hex(unsigned int i, int upper, struct flags *flags) {
	char *base;
	char *new_str;

	flags->space = flags->plus = 0;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	char *str = ft_utoa_base(i, base);
	new_str = str;
	
	if (flags->hash) {
		new_str = "0x";
		if (upper)
			new_str = "0X";
		new_str = ft_strjoin(new_str, str);
		free(str);
	}

	if (flags->dot) {
		flags->zero = 0;
		new_str = ft_adjust_precision(new_str, flags->precision, flags);
	}

	return ft_print_padded_str(new_str, flags, 1);
}