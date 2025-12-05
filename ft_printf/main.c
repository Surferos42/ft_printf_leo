#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

// Kody ANSI do kolorów
#define GREEN   "\033[0;32m"
#define BLUE    "\033[0;34m"
#define RESET   "\033[0m"

int main(void)
{
    int ret1, ret2;
    int x = 42;

    // %c – zwykły znak i znak NUL
    printf(GREEN "=== ft_printf ===\n" RESET);
    ret1 = ft_printf("Char normal: %c\n", 'A');
    ret1 = ft_printf("Char NUL: %c\n", '\0');
    printf(BLUE "=== printf ===\n" RESET);
    ret2 = printf("Char normal: %c\n", 'A');
    ret2 = printf("Char NUL: %c\n", '\0');
    printf("\n");

    // %s – pusty string i NULL
    printf(GREEN "=== ft_printf ===\n" RESET);
    ft_printf("Empty string: %s\n", "");
    ft_printf("Null string: %s\n", NULL);
    printf(BLUE "=== printf ===\n" RESET);
    printf("Empty string: %s\n", "");
    printf("\n");

    // %d / %i – 0, INT_MIN, INT_MAX
    printf(GREEN "=== ft_printf ===\n" RESET);
    ft_printf("Zero: %d\n", 0);
    ft_printf("INT_MIN: %d\n", INT_MIN);
    ft_printf("INT_MAX: %d\n", INT_MAX);
    printf(BLUE "=== printf ===\n" RESET);
    printf("Zero: %d\n", 0);
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("\n");

    // %u – 0 i UINT_MAX
    printf(GREEN "=== ft_printf ===\n" RESET);
    ft_printf("Unsigned zero: %u\n", 0u);
    ft_printf("Unsigned max: %u\n", 4294967295u);
    printf(BLUE "=== printf ===\n" RESET);
    printf("Unsigned zero: %u\n", 0u);
    printf("Unsigned max: %u\n", 4294967295u);
    printf("\n");

    // %x / %X – 0 i UINT_MAX
    printf(GREEN "=== ft_printf ===\n" RESET);
    ft_printf("Hex lower zero: %x\n", 0u);
    ft_printf("Hex upper zero: %X\n", 0u);
    ft_printf("Hex lower max: %x\n", 4294967295u);
    ft_printf("Hex upper max: %X\n", 4294967295u);
    printf(BLUE "=== printf ===\n" RESET);
    printf("Hex lower zero: %x\n", 0u);
    printf("Hex upper zero: %X\n", 0u);
    printf("Hex lower max: %x\n", 4294967295u);
    printf("Hex upper max: %X\n", 4294967295u);
    printf("\n");

    // %p – NULL i adres zmiennej
    printf(GREEN "=== ft_printf ===\n" RESET);
    ft_printf("Pointer NULL: %p\n", NULL);
    ft_printf("Pointer to x: %p\n", &x);
    printf(BLUE "=== printf ===\n" RESET);
    printf("Pointer NULL: %p\n", NULL);
    printf("Pointer to x: %p\n", &x);
    printf("\n");

    // Mix wszystkiego
    printf(GREEN "=== ft_printf ===\n" RESET);
    ret1 = ft_printf("Mix: %c %s %d %u %x %X %p %%\n", 'A', "abc", -42, 42u, 255, 255, &x);
    printf(BLUE "=== printf ===\n" RESET);
    ret2 = printf("Mix: %c %s %d %u %x %X %p %%\n", 'A', "abc", -42, 42u, 255, 255, &x);
    printf("ft_printf -> %d znaków, printf -> %d znaków\n\n", ret1, ret2);

    return 0;
}

