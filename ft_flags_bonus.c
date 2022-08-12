#include "libft/libft.h"
#include "ft_printf.h"

void set_flag(struct flags *f, char flag) {
	switch (flag)
	{
	case '-':
		f->zero = 0;
		f->minus = 1;
		break;
	case '0':
		if (!f->minus)
			f->zero = 1;
		break;
	case '#':
		f->hash = 1;
		break;
	case '+':
		f->space = 0;
		f->plus = 1;
		break;
	case ' ':
		if (!f->plus)
			f->space = 1;
		break;
	}
}

int print_flags(struct flags *flags) {
	int ret;

	ret = 0;
	// #sp+-0
	if (flags->hash)
		ft_putchar_fd('#', 1), ret++;
		
	if (flags->space)
		ft_putchar_fd(' ', 1), ret++;

	if (flags->plus)
		ft_putchar_fd('+', 1), ret++;

	if (flags->minus)
		ft_putchar_fd('-', 1), ret++;

	if (flags->zero)
		ft_putchar_fd('0', 1), ret++;

	if (flags->width) {
		char *w = ft_itoa(flags->width);
		ft_putstr_fd(w, 1), ret += ft_strlen(w), free(w);
	}

	return ret;
}

int isflag(char c) {
	return !!ft_strchr("#-0+ ", c);
}


