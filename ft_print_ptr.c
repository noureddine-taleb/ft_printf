#include "libft/libft.h"

int ft_print_ptr(void *p) {
	char *str = ft_utoa_base((unsigned long)p, "0123456789abcdef");
	int len = ft_strlen(str);

	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	free(str);
	return len + 2;
}