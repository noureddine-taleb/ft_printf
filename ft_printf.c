/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntaleb <ntaleb@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:58:23 by ntaleb            #+#    #+#             */
/*   Updated: 2022/08/12 20:58:04 by ntaleb           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"

int	ft_do_printf(const char *fmt, va_list ap)
{
	int				ret;
	struct s_flags	flags;

	ret = 0;
	ft_bzero(&flags, sizeof(flags));
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ret += handle_format(&fmt, ap, &flags);
		}
		else
		{
			ft_putchar_fd(*fmt++, 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		retval;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	retval = ft_do_printf(fmt, ap);
	va_end(ap);
	return (retval);
}
