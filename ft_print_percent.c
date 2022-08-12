#include "./libft/libft.h"
#include "ft_printf.h"

// %%
int ft_print_percent(struct flags *flags) {
	(void) flags;
	ft_putchar_fd('%', 1);
	return 1;
}