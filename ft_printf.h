#ifndef FT_PRINTF
#define FT_PRINTF

#include "libft/libft.h"

struct flags
{
	int hash;
	int minus;
	int zero;
	int plus;
	int space;

	int width;

	int dot;
	int precision;

	char conversion;
};

void set_flag(struct flags *f, char flag);
int print_flags(struct flags *flags);
int isflag(char c);
int ft_print_padded_str(char *str, struct flags *flags, int _free);
int ft_print_padded_mem(char *src, int len, struct flags *flags, int _free);
void handle_flags(const char **fmt, struct flags *flags);
char *ft_adjust_precision(char *number, int new_precision, struct flags *flags);

int ft_print_percent(struct flags *flags);
int ft_print_char(char c, struct flags *flags);
int ft_print_str(char *str, struct flags *flags);
int ft_print_int(int i, struct flags *flags);
int ft_print_uint(unsigned int i, struct flags *flags);
int ft_print_uint_hex(unsigned int i, int upper, struct flags *flags);
int ft_print_ptr(void *p, struct flags *flags);

int ft_printf(const char *fmt, ...);

#endif