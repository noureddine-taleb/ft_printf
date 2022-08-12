#include "ft_printf.h"

int ft_print_padded_str(char *str, struct flags *flags, int _free) {
	return ft_print_padded_mem(str, ft_strlen(str), flags, _free);
}

int ft_print_prefix(char *src, struct flags *flags) {
	int retval;

	retval = 0;
	if (src[0] == '-' || flags->space || flags->plus) {
		ft_putchar_fd(src[0], 1);
		retval++;
	}

	if (
		flags->conversion == 'p' ||
		(
			flags->conversion == 'x' &&
			flags->hash
		)
	) {
		ft_putstr_fd("0x", 1);
		retval += 2;
	}

	if (
		flags->conversion == 'X' &&
		flags->hash
	) {
		ft_putstr_fd("0X", 1);
		retval += 2;
	}

	return retval;
}

int ft_print_padded_mem(char *src, int len, struct flags *flags, int _free) {
	int retval;
	int offset;

	retval = len;
	offset = 0;
	if (flags->width > len) {
		int remaining = flags->width - len;
		retval += remaining;
		if (flags->zero) {
			// show sign if applicable
			offset = ft_print_prefix(src, flags);
			while (remaining--)
				ft_putchar_fd('0', 1);
		}

		if (!flags->zero && !flags->minus)
			while (remaining--)
				ft_putchar_fd(' ', 1);
		
		ft_putmem_fd(src + offset, len - offset, 1);
		
		if (flags->minus)
			while (remaining--)
				ft_putchar_fd(' ', 1);
	} else {
		ft_putmem_fd(src, len, 1);
	}

	if (_free)
		free(src);

	return retval;
}