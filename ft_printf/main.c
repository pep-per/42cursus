// #include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include "./bonus/ft_printf_bonus.h"

int main(void)
{
	int r1;
	int r2;

	r1 = printf("%-7.5s", "tubular");
	printf("\n");
	printf("printf cnt : %d\n", r1);
	r2 = ft_printf("%-7.5s", "tubular");
	printf("\n");
	printf("ft_printf cnt : %d\n", r2);
}
