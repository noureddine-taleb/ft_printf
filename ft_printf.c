#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"

// flags-width-conversion
void handle_flags(const char **fmt, struct flags *flags) {

	ft_bzero(flags, sizeof *flags);
#ifndef _BONUS
	(void)fmt;
#endif
#ifdef _BONUS
	// flags
	while (isflag(**fmt)) {
		set_flag(flags, **fmt);
		(*fmt)++;
	}

	// width
	if (ft_isdigit((**fmt))) {
		flags->width = ft_atoi(*fmt);
	}

	while(ft_isdigit((**fmt))) {
		(*fmt)++;
	}
#endif
}

int handle_format(const char **fmt, va_list ap, struct flags *flags) {
	int success = 1;
	int ret = 0;
	
	switch (**fmt)
	{
	case '%':
		ret += ft_print_percent(flags);
		break;
	
	case 'c':
		ret += ft_print_char(va_arg(ap, int), flags);
		break;

	case 's':
		ret += ft_print_str(va_arg(ap, char *), flags);
		break;

	case 'i':
	case 'd':
		ret += ft_print_int(va_arg(ap, int), flags);
		break;
	
	case 'u':
		ret += ft_print_uint(va_arg(ap, unsigned int), flags);
		break;
		
	case 'x':
	case 'X':
		ret += ft_print_uint_hex(va_arg(ap, unsigned int), **fmt == 'X', flags);
		break;

	case 'p':
		ret += ft_print_ptr(va_arg(ap, void *), flags);
		break;

	default:
		success = 0;
		ft_putchar_fd('%', 1), ret++;
#ifdef _BONUS
		ret += print_flags(flags);
#endif
		break;
	}

	if (success)
		(*fmt) ++;

	return ret;
}

int ft_do_printf(const char *fmt, va_list ap) {
	int ret;
	struct flags flags;

	ret = 0;
	while(*fmt) {
		if (*fmt == '%') {
			fmt++;
			handle_flags(&fmt, &flags);
			ret += handle_format(&fmt, ap, &flags);
		}
		else
			ft_putchar_fd(*fmt++, 1), ret++;
	}

	return ret;
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int retval;

	if (!fmt)
		return -1;
	va_start(ap, fmt);
	retval = ft_do_printf(fmt, ap);
	va_end(ap);

	return retval;
}
