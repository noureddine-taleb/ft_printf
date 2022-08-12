#include "ft_printf.h"
#include <stdio.h>

int ft_print_str(char *str, struct flags *flags) {
	flags->hash = flags->plus = flags->space = flags->zero = 0;
	int free = 0;

	if (str && flags->dot && ft_strlen(str) > (size_t)flags->precision) {
		str = ft_substr(str, 0, flags->precision);
		free = 1;
	} else if (!str) {
		str = "(null)";
		if (flags->dot && flags->precision < 6)
			str = "";
	}

	return ft_print_padded_str(str, flags, free);
}