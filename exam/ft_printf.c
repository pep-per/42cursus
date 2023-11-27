/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:58:01 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/08/15 22:04:10 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_deci(int num)
{
	long long		n;
	int				len;
	int				i;
	char			*str;

	len = 0;
	n = (long long)num;
	if (n == 0)
		len = 1;
	else if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	n = (long long)num;
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	i = len;
	str[i] = '\0';
	while (n > 0)
	{
		i--;
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	write(1, str, len);
	free(str);
	return (len);
}

int	print_hexa(unsigned int num)
{
	unsigned int	n;
	int				len;
	int				i;
	char			*str;

	len = 0;
	n = num;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	n = num;
	if (n == 0)
		str[0] = '0';
	i = len;
	str[i] = '\0';
	while (n > 0)
	{
		i--;
		if ((n % 16) > 9)
			str[i] = (n % 16) - 10 + 'a';
		else
			str[i] = (n % 16) + '0';
		n /= 16;
	}
	write(1, str, len);
	free(str);
	return (len);
}

int	parse_type(va_list ap, char c)
{
	int				len;
	int				num;
	unsigned int	unum;
	char			*str;

	if (c == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
		{
			len = write(1, "(null)", 6);
		}
		else
		{
			len = write(1, str, ft_strlen(str));
		}
	}
	else if (c == 'x')
	{
		unum = va_arg(ap, unsigned int);
		len = print_hexa(unum);
	}
	else if (c == 'd')
	{
		num = va_arg(ap, int);
		len = print_deci(num);
	}
	return (len);
}

// int	find_type(char *fmt, va_list ap, int *i)
// {
// 	(*i)++;
// 	while (fmt[*i])
// 	{
// 		if (fmt[*i] == 's' || fmt[*i] == 'd' || fmt[*i] == 'x')
// 			return (parse_type(ap, fmt[*i]));
// 		(*i)++;
// 	}
// 	return (-1);
// }

int	find_type(char c, va_list ap)
{
	if (c == 's' || c == 'd' || c == 'x')
		return (parse_type(ap, c));
	return (0);
}

int	input(char *fmt, va_list ap)
{
	int	result;
	int	len;
	int	i;

	result = 0;
	len = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			len = find_type(fmt[i], ap);
			if (len == -1)
				return (-1);
			result += len;
		}
		else
		{
			result += write(1, &fmt[i], 1);
		}
		i++;
	}
	return (result);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = input((char *)fmt, ap);
	va_end(ap);
	return (len);
}

#include <stdio.h>
int	main(void)
{
	int	n;

	n = printf("%%s\n", NULL);
	printf("%d\n", n);
	n = ft_printf("%%s\n", NULL);
	printf("%d\n", n);

	n =  printf("%lx\n", 2147483648);
	printf("%d\n", n);
	n =  ft_printf("%x\n", 2147483648);
	printf("%d\n", n);

	n =  printf("%x\n", 2147483647);
	printf("%d\n", n);
	n =  ft_printf("%x\n", 2147483647);
	printf("%d\n", n);

	n =  printf("%d %s %x\n", 0, "abcdef", 12345);
	printf("%d\n", n);
	n =  ft_printf("%d % s %x\n", 0, "abcdef", 12345);
	printf("%d\n", n);


}
