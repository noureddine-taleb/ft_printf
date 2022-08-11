#include "libft/libft.h"

int ft_print_uint(unsigned int i) {
	char *str = ft_utoa_base(i, "0123456789");
	int len = ft_strlen(str);

	ft_putstr_fd(str, 1);
	free(str);
	return len;
}