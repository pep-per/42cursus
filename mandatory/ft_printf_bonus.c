/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:10:24 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 12:46:16 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	parse_type(va_list args, t_tags *tags, \
						int type, int (*ft_put[])(void *p, unsigned int len))
{
	if (tags->type != -1)
		tags->type = type;
	if (type == 'c' || type == '%')
		return (convert_to_char(args, tags));
	else if (type == 's')
		return (convert_to_str(args, tags, ft_put[0]));
	else if (type == 'p')
		return (convert_to_adress(args, tags, ft_put[1]));
	else if (type == 'd' || type == 'i')
		return (convert_to_decimal(args, tags, ft_put[4]));
	else if (type == 'u')
		return (convert_to_decimal(args, tags, ft_put[5]));
	else if (type == 'x')
		return (convert_to_hexa(args, tags, ft_put[2]));
	else
		return (convert_to_hexa(args, tags, ft_put[3]));
}

static int	parse_format(char *format, va_list args, int *i)
{
	t_tags	*tags;
	int		(*ft_put[6])(void *p, unsigned int len);
	int		result;

	tags = (t_tags *)malloc(sizeof(t_tags));
	if (!tags)
		return (-1);
	initialize(tags, ft_put);
	while (format[++(*i)])
	{
		if (is_type(format[*i]))
		{
			if (handle_format_overflow(tags, format[*i]) == -1)
				return (-1);
			result = parse_type(args, tags, format[*i], ft_put);
			free(tags);
			return (result);
		}
		else
			parse_option(format[*i], tags);
	}
	free(tags);
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
			if (write(1, &format[i], 1) == -1 || format[i] == '%')
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
