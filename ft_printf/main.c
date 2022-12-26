#include "./bonus/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>
// #include "ft_printf_bonus.h"

int main(void)
{
	int r1;
	int r2;

	r1 = printf("42%023.4d42", 0);
	printf("\n");
	printf("printf cnt : %d\n", r1);
	r2 = ft_printf("42%023.4d42", 0);
	printf("\n");
	printf("ft_printf cnt : %d\n", r2);

}

// int	main(void)
// {
// 	int	cnt;
// 	int	ft_cnt;

// 	ft_cnt = 0;
// 	cnt = 0;
// 	ft_printf("----test----\n");
// 	ft_cnt = ft_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
// 	printf("\n");
// 	cnt = printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
// 	printf("\n");
// 	printf("ft_printf cnt: %d\n", ft_cnt);
// 	printf("printf cnt: %d\n", cnt);
// }



// [ERROR] diff on output for format "\\!/%22.10s\\!/" and arg: ""
// expected: [\\!/                      \\!/]
//      got: [\\!/            \\!/\x00\x00------<\x00]