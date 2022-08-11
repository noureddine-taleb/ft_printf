#include "libft/libft.h"

int ft_print_str(char *str) {
	ft_putstr_fd(str, 1);
	return ft_strlen(str);
}