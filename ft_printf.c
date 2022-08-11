#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"
#include "../libft/libft.h"

int handle_format(const char **fmt, va_list ap) {
	int success = 1;
	int ret = 0;

	switch ((*fmt)[1])
	{
	case '%':
		ret += ft_print_percent();
		break;
	
	case 'c':
		ret += ft_print_char(va_arg(ap, int));
		break;

	case 's':
		ret += ft_print_str(va_arg(ap, char *));
		break;

	case 'i':
	case 'd':
		ret += ft_print_int(va_arg(ap, int));
		break;
	
	case 'u':
		ret += ft_print_uint(va_arg(ap, unsigned int));
		break;
		
	case 'x':
	case 'X':
		ret += ft_print_uint_hex(va_arg(ap, unsigned int), (*fmt)[1] == 'X');
		break;

	case 'p':
		ret += ft_print_ptr(va_arg(ap, void *));
		break;

	default:
		success = 0;
		ft_putchar_fd('%', 1), ret++;
		break;
	}

	if (success)
		(*fmt) ++;

	return ret;
}

int ft_do_printf(const char *fmt, va_list ap) {
	int ret;

	ret = 0;
	while(*fmt) {
		if (*fmt == '%')
			ret += handle_format(&fmt, ap);
		else
			ft_putchar_fd(*fmt, 1), ret++;
		fmt++;
	}

	return ret;
}

#include <stdio.h>
int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int retval;

	va_start(ap, fmt);
	retval = ft_do_printf(fmt, ap);
	va_end(ap);

	return retval;
}
