#include "ft_printf.h"

int ft_print_int(int i, struct flags *flags) {
	flags->hash = 0;
	char	*str = ft_itoa(i);
	char 	*new_str = str;
	char	sign[2] = {0, 0};

	if ((flags->space || flags->plus) && i >= 0) {
		if (flags->space)
			sign[0] = ' ';
		else if(flags->plus)
			sign[0] = '+';
		new_str = ft_strjoin(sign, str);
		free(str);
	}

	if (flags->dot) {
		flags->zero = 0;
		new_str = ft_adjust_precision(new_str, flags->precision, flags);
	}

	return ft_print_padded_str(new_str, flags, 1);
}