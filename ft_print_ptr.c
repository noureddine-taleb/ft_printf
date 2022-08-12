#include "ft_printf.h"

int ft_print_ptr(void *p, struct flags *flags) {
	flags->hash = 0;
	char *str;
	char *new_str;

	if (!p) {
		new_str = "(nil)";
	} else {
		str = ft_utoa_base((unsigned long)p, "0123456789abcdef");
		new_str = ft_strjoin("0x", str);
		free(str);
		if (flags->space || flags->plus) {
			if (flags->space) {
				str = ft_strjoin(" ", new_str);
			} else {
				str = ft_strjoin("+", new_str);
			}
			free(new_str);
			new_str = str;
		}
	}

	return ft_print_padded_str(new_str, flags, p != NULL);
}