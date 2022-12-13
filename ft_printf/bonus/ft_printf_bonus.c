/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:10:24 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/14 05:15:23 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	init_tags(t_tags *tags)
{
	tags->type = 0;
	tags->width = 0;
	tags->precision = -1;
	tags->minus = 0;
	tags->plus = 0;
	tags->zero = 0;
	tags->hash = 0;
	tags->space = 0;
}

static int	parse_type(char c, va_list args, t_tags *tags)
{
	char	*arg;

	if (c == 'c')
		return (apply_type_c((char)va_arg(args, int), tags));
	else if (c == 's')
	{
		arg = va_arg(args, char *);
		return (apply_type_s(arg, tags));
	}
	else if (c == 'p')
		return (apply_type_p(va_arg(args, void *), tags));
	else if (c == 'd' || c == 'i')
		return (apply_type_d(va_arg(args, int), tags));
	else if (c == 'u')
		return (apply_type_u(va_arg(args, unsigned int), tags));
	else if (c == 'x')
		return (apply_type_x(va_arg(args, unsigned int), 0, tags));
	else if (c == 'X')
		return (apply_type_x(va_arg(args, unsigned int), 1, tags));
	else
		return (ft_putchar('%'));
}

static void	parse_option(char c, t_tags *tags)
{
	if (!is_num(c) && !is_option(c))
		return ;
	if (c == '-')
		tags->minus = 1;
	if (c == '+')
		tags->plus = 1;
	if (c == '#')
		tags->hash = 1;
	if (c == ' ')
		tags->space = 1;
	if (c == '.')
		tags->precision = 0;
	if (c == '0' && tags->width == 0 && tags->minus == 0
		&& tags->precision == -1)
		tags->zero = 1;
	else if (is_num(c) && tags->precision == -1)
		tags->width = 10 * (tags->width) + (c - '0');
	else if (is_num(c))
		tags->precision = 10 * (tags->precision) + (c - '0');
}
	//write 실패 시  -1 리턴
	//해석 실패 시 - 1 리턴
	//오버플로우 - 1 리턴

static int	parse_format(char *format, va_list args, int *i)
{
	t_tags	*tags;

	init_tags(tags);
	while (format[++(*i)])
	{
		if (is_type(format[*i]))
		{
			tags->type = (int)format[*i];
			return (parse_type(format[*i], args, tags));
		}
		else
			parse_option(format[*i], tags);
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
			if (ft_putchar(format[i]) == -1 || format[i] == '%')
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
