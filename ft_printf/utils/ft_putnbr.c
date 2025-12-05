#include "../ft_printf.h"

int ft_putnbr(int n)
{
    int     len;
    long    num;

    num = n;
    len = 0;
    if (num < 0)
    {
        len += ft_putchar('-');
        num = -num;
    }
    if (num >= 10)
        len += ft_putnbr(num / 10);
    len += ft_putchar((num % 10) + '0');
    return (len);
}

