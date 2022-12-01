/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:10:24 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/01 21:17:01 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_tags(t_tags *tags)
{
	tags->type = 0;
	tags->width = 0;
	tags->dot = -1;
	tags->minus = 0;
	tags->zero = 0;
	tags->hash = 0;
	tags->space = 0;
}

int	parse_type(const char *format, int i, t_tags *tags, va_list args)
{
	if (format[i] == 'c')
		return (apply_options(ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return ();
}

void	apply_options(const char *format, int i, t_tags *tags, va_list args)
{
	ft_putchar_fd(va_arg(args, int), 1));
}
// void	apply_options(int (*flag[])(t_tags *tags))
// {
// 	int		(*flag[3])(t_tags *tags);

// }

void	parse_flag(int c, t_tags *tags, va_list args)
{
	//init_flag(tags);
	if (c == '0')
	{
		tags->zero = 1;
	}
	else if (c == '-')
	{
		
	}
	//write 실패 시  -1 리턴
	//해석 실패 시 - 1 리턴
	//오버플로우 - 1 리턴
}

int	parse_format(const char *format, va_list args, int *len)
{
	t_tags	*tags;
	int		i;
	int		result;

	init_tags(tags);
	i = 0;
	while (format[i])
	{
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p' \
			|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u' \
			|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
		{
			result = parse_type(format, i, tags, args);
			if (result == -1)
				return (-1);
			else
			{
				*len += result;
				return (i + result);
			}
		}
		parse_flag(format[i], tags, args);
		i++;
	}
	return (i);
}

int	input_format(const char *format, va_list args)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			i = parse_format(format, args, &len);
			if (i == -1)
				return (-1);
			format += i;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			len += 1;
		}
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = input_format(format, args);
	va_end(args);
	// free 꼭해야하나?
	free((char *)format);
	return (len);
}
