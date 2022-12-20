/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:10:24 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/20 16:04:36 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	parse_type(va_list args, t_tags *tags, \
						int (*ft_put[])(va_list args))
{
	int	type;

	type = tags->type;
	if (type == 'c' || type == '%')
		return (apply_type_char(args, tags, ft_put[0]));
	else if (type == 's')
		return (apply_type_char(args, tags, ft_put[1]));
	else if (type == 'p')
		return (convert_to_hexa(args, tags, ft_put[2]));
	else if (type == 'd' || type == 'i')
		return (convert_to_decimal(args, tags, ft_put[5]));
	else if (type == 'u')
		return (convert_to_decimal(args, tags, ft_put[6]));
	else if (type == 'x')
		return (convert_to_hexa(args, tags, ft_put[3]));
	else
		return (convert_to_hexa(args, tags, ft_put[4]));
}
	//write 실패 시  -1 리턴
	//해석 실패 시 - 1 리턴
	//오버플로우 - 1 리턴

static int	parse_format(char *format, va_list args, int *i)
{
	t_tags	*tags;
	int		(*ft_put[6])(va_list args);

	tags = (t_tags *)malloc(sizeof(t_tags));
	init_tags(tags);
	init_ft_put(ft_put);
	while (format[++(*i)])
	{
		if (is_type(format[*i]))
		{
			tags->type = (int)format[*i];
			return (parse_type(args, tags, ft_put));
		}
		else
		{
			parse_option(format[*i], tags);
			if (tags->type == -1)
				return (-1);
		}
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
