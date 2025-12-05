#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int     i;
    int     count;

    va_start(args, format);
    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 'c')
                count += ft_putchar(va_arg(args, int));
            else if (format[i] == 's')
                count += ft_putstr(va_arg(args, char *));
            else if (format[i] == 'p')
                count += ft_putptr(va_arg(args, void *)); // ✅ void * dla testów Tripouille
            else if (format[i] == 'd' || format[i] == 'i')
                count += ft_putnbr(va_arg(args, int));
            else if (format[i] == 'u')
                count += ft_putunbr(va_arg(args, unsigned int));
            else if (format[i] == 'x')
                count += ft_puthex(va_arg(args, unsigned int), 0);
            else if (format[i] == 'X')
                count += ft_puthex(va_arg(args, unsigned int), 1);
            else if (format[i] == '%')
                count += ft_putchar('%');
            else
                count += ft_putchar(format[i]); // fallback
        }
        else
            count += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (count);
}

