/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:10:24 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/10 17:32:43 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_type_p(void *arg)
{
	if (!arg)
		return (ft_put_hexa(0, 0, 1));
	return (ft_put_hexa((size_t)arg, 0, 1));
}

static int	parse_type(char c, va_list args)
{
	char	*arg;

	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == 's')
	{
		arg = va_arg(args, char *);
		if (!arg)
			return (ft_putstr("(null)"));
		return (ft_putstr(arg));
	}
	else if (c == 'p')
		return (apply_type_p(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (c == 'u')
		return (ft_uitoa(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_put_hexa(va_arg(args, unsigned int), 0, 0));
	else if (c == 'X')
		return (ft_put_hexa(va_arg(args, unsigned int), 1, 0));
	else
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
