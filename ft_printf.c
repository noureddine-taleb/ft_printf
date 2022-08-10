#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"
#include "../libft/libft.h"

#define min(a, b) (a > b ? b : a) 

#define SIGNED	1
#define UPPER	2
#define BASEPRE	4

enum FORMAT_TYPE {
	TYPE_NONE,
	TYPE_STR,
	TYPE_CHAR,
	TYPE_PERCENT_CHAR,
	TYPE_PTR,
	TYPE_INT,
};

struct format_token {
	enum FORMAT_TYPE	type;
	int					base;
	int					flags;
};

// TODO: optimize me
// char	*ft_utoa(unsigned long long n)
// {
// 	unsigned int				count;
// 	unsigned int				i;
// 	unsigned long long			cp1;
// 	unsigned long long			cp2;
// 	char						*s;

// 	count = 0;
// 	cp1 = n;
// 	cp2 = n;
// 	if (n == 0)
// 		count++;
// 	while (cp2)
// 	{
// 		count++;
// 		cp2 /= 10;
// 	}
// 	s = malloc(count + 1);
// 	if (!s)
// 		return (NULL);
// 	cp2 = cp1;
// 	if (cp2 == 0)
// 	{
// 		ft_strlcpy(s, "0", count + 1);
// 		return (s);
// 	}
// 	i = count;
// 	s[i] = 0;
// 	i--;
// 	while (cp2)
// 	{
// 		s[i] = cp2 % 10 + '0';
// 		cp2 /= 10;
// 		i--;
// 	}

// 	return (s);
// }

unsigned int	format_decode(const char *fmt, struct format_token *token)
{
	unsigned int	read;

	read = 0;
	*token = (struct format_token){ 0 };
	
	if (*fmt == '%')
	{
		fmt++, read++;
		if (*fmt == 's')
			token->type = TYPE_STR;
		else if (*fmt == 'c')
			token->type = TYPE_CHAR;
		else if (*fmt == '%')
			token->type = TYPE_PERCENT_CHAR;
		else if (*fmt == 'p')
			token->type = TYPE_PTR, token->flags |= BASEPRE, token->base = 16;
		else if (*fmt == 'd' || *fmt == 'i')
			token->type = TYPE_INT, token->flags |= SIGNED, token->base = 10;
		else if (*fmt == 'u')
			token->type = TYPE_INT, token->base = 10;
		else if (*fmt == 'x')
			token->type = TYPE_INT, token->base = 16;
		else if (*fmt == 'X')
			token->type = TYPE_INT, token->flags |= UPPER, token->base = 16;
		if (token->type && *fmt)
			return ++read;
	}
	
	while (*fmt && *fmt++ != '%')
		read++;

	token->type = TYPE_NONE;
	return (read);
}

static int	ft_vsnprintf(char *buf, size_t len, const char *fmt, va_list ap)
{
	struct format_token	token;
	unsigned int		read;
	// unsigned long long	num;
	// char c;
	char *str;
	size_t tmp;
	unsigned long u;

	while (*fmt && len > 1) {
		read = format_decode(fmt, &token);
		if (token.type == TYPE_NONE)
		{
			read = min(len - 1, read);
			ft_strlcpy(buf, fmt, read + 1);
			buf += read, len -= read;
		}
		else if (token.type == TYPE_PERCENT_CHAR)
		{
			*buf++ = '%';
			len--;
		}
		else if (token.type == TYPE_CHAR)
		{
			*buf++ = (unsigned char)va_arg(ap, int);
			len--;
		}
		else if (token.type == TYPE_STR)
		{
			str = va_arg(ap, char *);
			ft_strlcpy(buf, str, len);
			tmp = min(ft_strlen(str), len - 1);
			len -= tmp;
			buf += tmp;
		}
		else if (token.type == TYPE_INT)
		{
			tmp = va_arg(ap, int);
			str = ft_itoa(tmp);
			if (!str)
				return -1;
			ft_strlcpy(buf, str, len);
			tmp = min(ft_strlen(str), len - 1);
			len -= tmp;
			buf += tmp;
			fmt++;
			free(str);
		}
		switch (*fmt)
		{

		case 'd':
		case 'i':
			tmp = va_arg(ap, int);
			str = ft_itoa(tmp);
			if (!str)
				return -1;
			ft_strlcpy(buf, str, len);
			tmp = min(ft_strlen(str), len - 1);
			len -= tmp;
			buf += tmp;
			fmt++;
			free(str);
			break;
		
		case 'u':
			u = va_arg(ap, unsigned long long);
			str = ft_utoa_base(u, "0123456789");
			if (!str)
				return -1;
			ft_strlcpy(buf, str, len);
			tmp = min(ft_strlen(str), len - 1);
			len -= tmp;
			buf += tmp;
			fmt++;
			free(str);
			break;

		case 'p':
			ft_strlcpy(buf, "0x", len);
			tmp = min(2, len - 1);
			len -= tmp;
			buf += tmp;
			if (len <= 1)
				break;
			// fallthrough
		case 'x':
			u = va_arg(ap, unsigned long long);
			str = ft_utoa_base(u, "0123456789abcdef");
			if (!str)
				return -1;
			ft_strlcpy(buf, str, len);
			tmp = min(ft_strlen(str), len - 1);
			len -= tmp;
			buf += tmp;
			fmt++;
			free(str);
			break;

		case 'X':
			u = va_arg(ap, unsigned long long);
			str = ft_utoa_base(u, "0123456789ABCDEF");
			if (!str)
				return -1;
			ft_strlcpy(buf, str, len);
			tmp = min(ft_strlen(str), len - 1);
			len -= tmp;
			buf += tmp;
			fmt++;
			free(str);
			break;

		}
		fmt += read;
	}
	*buf = 0;
	return 0;
}

#include <stdio.h>

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	char buf[256];
	int retval;

	va_start(ap, fmt);
	printf("before: %s\n", fmt);
	retval = ft_vsnprintf(buf, sizeof buf, fmt, ap);
	printf("after: %s\n", buf);
	va_end(ap);

	ft_putstr_fd(buf, 1);

	return retval;
}
