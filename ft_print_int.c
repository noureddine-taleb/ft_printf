#include "libft/libft.h"

int ft_print_int(int i) {
	char	*str = ft_itoa(i);
	int		len = ft_strlen(str);

	ft_putstr_fd(str, 1);
	free(str);
	return len;
}