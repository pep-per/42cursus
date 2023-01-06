/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:10:24 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 19:10:25 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_null_strlen(char *arg, char *str)
{
	if (!arg)
		return ((int)ft_strlen(str));
	else
		return ((int)ft_strlen(arg));
}

int	handle_null_ft_put(char *arg, char *str, int len, \
						int (*ft_put)(void *p, unsigned int len))
{
	if (!arg)
		return (ft_put(str, len));
	else
		return (ft_put(arg, len));
}

static int	parse_type(va_list args, int type, \
						int (*ft_put[])(void *p, unsigned int len))
{
	long long		num;	
	unsigned int	len;
	char			*arg;
	char			*str;

	if (type == 'c')
	{
		num = (char)va_arg(args, int);
		if (write(1, &num, 1) == -1)
			return (-1);
	}
	else if (type == '%')
	{
		num = '%';
		if (write(1, &num, 1) == -1)
			return (-1);
	}
	else if (type == 's')
	{
		arg = va_arg(args, char *);
		str = ft_strdup("(null)");
		if (!str)
			return (-1);
		len = handle_null_strlen(arg, str);

	}
		return (convert_to_str(args, ft_put[0]));
	else if (type == 'p')
		return (convert_to_adress(args, ft_put[1]));
	else if (type == 'd' || type == 'i')
		return (convert_to_decimal(args, ft_put[4]));
	else if (type == 'u')
		return (convert_to_decimal(args, ft_put[5]));
	else if (type == 'x')
		return (convert_to_hexa(args, ft_put[2]));
	else
		return (convert_to_hexa(args, ft_put[3]));	
	return (1);		
}

static int	parse_format(char *format, va_list args, int *i)
{
	int		(*ft_put[6])(void *p, unsigned int len);

	ft_put[0] = &ft_putstr;
	ft_put[1] = &ft_put_address;
	ft_put[2] = &ft_put_hexa_lower;
	ft_put[3] = &ft_put_hexa_upper;
	ft_put[4] = &ft_itoa;
	ft_put[5] = &ft_uitoa;
	while (format[++(*i)])
	{
		if (is_type(format[*i]))
			return (parse_type(args, format[*i], ft_put));
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
