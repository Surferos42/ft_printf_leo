#include "../ft_printf.h"

static int put_hex(unsigned long long n)
{
    char *hex = "0123456789abcdef";
    int count = 0;

    if (n >= 16)
        count += put_hex(n / 16);
    count += write(1, &hex[n % 16], 1);
    return count;
}

int ft_putptr(void *ptr)
{
    if (ptr == NULL)
        return write(1, "(nil)", 5);
    int count = 0;
    count += write(1, "0x", 2);
    count += put_hex((unsigned long long)ptr);
    return count;
}

