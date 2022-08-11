#include "ft_printf.h"
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv) {
    // ft_printf("17 == %d\n", ft_printf("%%s %s world! %\n", "hello"));
    assert(ft_printf("%%s %s world! %\n", "hello") == 18);
    assert(ft_printf("%%s %d world!\n", 5) == 12);
    assert(ft_printf("%%s %i world!\n", 5) == 12);
    assert(ft_printf("%%s %x world!\n", 0xbadb00b5) == 19);
    assert(ft_printf("%%s %X world!\n", 0xbadb00b5) == 19);
    assert(ft_printf("%%s %p world!\n", 0x1234567444444444) == 29);
    assert(ft_printf("%%s %c world!\n", 'c') == 12);
    assert(ft_printf("%%s %u world!\n", -1) == 21);
    assert(ft_printf("%s worl%c %d %u %i! %% ", "hello", 'd', 122, -1, -1) == 33);

    // ft_printf("%%s %s world! %\n", "hello");
    // ft_printf("%%s %d world!\n", 5);
    // ft_printf("%%s %i world!\n", 5);
    // ft_printf("%%s %x world!\n", 0xbadb00b5);
    // ft_printf("%%s %X world!\n", 0xbadb00b5);
    // ft_printf("%%s %p world!\n", 0x1234567444444444);
    // ft_printf("%%s %c world!\n", 'c');
    // ft_printf("%%s %u world!\n", -1);
    // ft_printf("%s worl%c %d %u %i! %% \n", "hello", 'd', 122, -1, -1);
}