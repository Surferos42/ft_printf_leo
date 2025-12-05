#include "../ft_printf.h"

static int put_hex(unsigned int n, int upper)
{
    char *hex;
    int count = 0;

    hex = upper ? "0123456789ABCDEF" : "0123456789abcdef";
    if (n >= 16)
        count += put_hex(n / 16, upper);
    count += write(1, &hex[n % 16], 1);
    return count;
}

int ft_puthex(unsigned int n, int upper)
{
    if (n == 0)
        return write(1, "0", 1);
    return put_hex(n, upper);
}

