/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:10:24 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/20 14:02:59 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_type(char c, va_list args)
{
	int				i;
	char			*str;
	unsigned int	ui;

	if (c == 'p')
		return (ft_put_address(va_arg(args, void *)));
	if (c == 'c' || c == 'd' || c == 'i')
	{
		i = va_arg(args, int);
		if (c == 'c')
			return (ft_put_to_char(&i));
		return (ft_itoa(&i));
	}
	if (c == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			return (ft_putstr("(null)"));
		return (ft_putstr(str));
	}
	if (c == 'u' || c == 'x' || c == 'X')
	{
		ui = va_arg(args, unsigned int);
		if (c == 'x')
			return (ft_put_hexa_lower(&ui));
		else if (c == 'X')
			return (ft_put_hexa_upper(&ui));
		return (ft_uitoa(&ui));
	}
	return (ft_putchar('%'));
}

static int	parse_format(char *format, va_list args, int *i)
{
	while (format[++(*i)])
	{
		if (format[*i] == 'c' || format[*i] == 's' || format[*i] == 'p' \
			|| format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'u' \
			|| format[*i] == 'x' || format[*i] == 'X' || format[*i] == '%')
			return (parse_type(format[*i], args));
	}
	return (0);
}

static int	input_format(char *format, va_list args)
{
	int		len;
	int		i;
	int		count;

	len = 0;
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count = parse_format(format, args, &i);
			if (count == -1)
				return (-1);
			len += count;
		}
		else
		{
			if (ft_putchar(format[i]) == -1)
				return (-1);
			len += 1;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, (char *)format);
	len = input_format((char *)format, args);
	va_end(args);
	return (len);
}
