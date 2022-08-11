#include "libft/libft.h"

int ft_print_uint_hex(unsigned int i, int upper) {
	char *base;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	char *str = ft_utoa_base(i, base);
	int len = ft_strlen(str);

	ft_putstr_fd(str, 1);
	free(str);
	return len;
}