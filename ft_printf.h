#ifndef FT_PRINTF
#define FT_PRINTF

int ft_print_percent();
int ft_print_char(char c);
int ft_print_str(char *str);
int ft_print_int(int i);
int ft_print_uint(unsigned int i);
int ft_print_uint_hex(unsigned int i, int upper);
int ft_print_ptr(void *p);

int ft_printf(const char *fmt, ...);

#endif