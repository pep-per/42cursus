/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:10:24 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/17 16:46:29 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"


static int	parse_type_char(va_list args, t_tags *tags, int (*ft_put[])(void *))
{
	int		type;
	char	c;
	char	*arg;
	char	*str;

	type = tags->type;
	c = '%';
	if (type == 'c' || type == '%')
	{
		if (type == 'c')
			c = (char)va_arg(args, int);
		return (apply_type_char(&c, tags, ft_put[0]));
	}
	else
	{
		arg = va_arg(args, char *);
		if (!arg)
			return (apply_type_char(ft_strdup("(null)"), tags, ft_put[1]));
		str = ft_strdup(arg);
		if (!str)
			return (-1);
		if (tags->precision != -1)
			str[tags->precision] = 0;
		return (apply_type_char(str, tags, ft_put[1]));
	}
}

static int	parse_type_num(va_list args, t_tags *tags, int (*ft_put[])(void *))
{
	int				type;
	int				i;
	unsigned int	ui;
	void			*arg;

	type = tags->type;
	if (type == 'p')
	{
		arg = va_arg(args, void *);
		return (convert_to_hexa(arg, tags, ft_put[2]));
	}
	else if (type == 'd' || type == 'i')
	{
		i = va_arg(args, int);
		return (convert_to_decimal(&i, tags, ft_put[5]));
	}
	else
	{
		ui = va_arg(args, unsigned int);
		if (type == 'u')
			return (convert_to_decimal(&ui, tags, ft_put[6]));
		else if (type == 'x')
			return (convert_to_hexa(&ui, tags, ft_put[3]));
		return (convert_to_hexa(&ui, tags, ft_put[4]));
	}
}
	//write 실패 시  -1 리턴
	//해석 실패 시 - 1 리턴
	//오버플로우 - 1 리턴

static int	parse_format(char *format, va_list args, int *i)
{
	t_tags	*tags;
	int		(*ft_put[6])(void *arg);

	tags = (t_tags *)malloc(sizeof(t_tags));
	init_tags(tags);
	init_ft_put(ft_put);
	while (format[++(*i)])
	{
		if (is_type(format[*i]))
		{
			tags->type = (int)format[*i];
			if (tags->type == 'c' || tags->type == 's')
				return (parse_type_char(args, tags, ft_put));
			else
				return (parse_type_num(args, tags, ft_put));
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
