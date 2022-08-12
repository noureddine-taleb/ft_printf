#include "ft_printf.h"

int ft_print_padded_str(char *str, struct flags *flags, int _free) {
	int len;

	len = ft_strlen(str);
	if (flags->width > len) {
		int remaining = flags->width - len;
		len += remaining;
		if (flags->zero)
			while (remaining--)
				ft_putchar_fd('0', 1);

		if (!flags->zero && !flags->minus)
			while (remaining--)
				ft_putchar_fd(' ', 1);
		
		ft_putstr_fd(str, 1);
		
		if (flags->minus)
			while (remaining--)
				ft_putchar_fd(' ', 1);
	} else {
		ft_putstr_fd(str, 1);
	}

	if (_free)
		free(str);

	return len;
}