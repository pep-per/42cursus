/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:45:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/20 22:32:05 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// int	apply_type_c(char c, t_tags *tags)
// {
// 	int	width;

// 	width = tags->width;
// 	if (width == 0)
// 		return (ft_putchar(c));
// 	if (tags->minus == 1)
// 		if (ft_putchar(c) == -1)
// 			return (-1);
// 	tags->width -= 1;
// 	if (apply_option_width(tags) == -1)
// 		return (-1);
// 	if (tags->minus == 0)
// 		if (ft_putchar(c) == -1)
// 			return (-1);
// 	return (width);
// }


int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}		
	return (0);
}

int	is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
			|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	apply_type_char(va_list args, t_tags *tags, \
					int (*ft_put)(va_list args, t_tags *tags))
{
	unsigned int	width;

	width = tags->width;
	tags->width -= 1;
	if (ft_put(args, tags) == -1)
		return (-1);
	return (width);
}

int	apply_type_str(va_list args, t_tags *tags, \
					int (*ft_put)(va_list args, t_tags *tags))
{
	unsigned int	width;
	unsigned int	len;
	unsigned int	precise_len;
	char			*arg;
	char			*str;

	
	if (tags->precision != -1)
	{
		if (apply_option_precision(tags, len) == -1)
			return (-1);
	}
	precise_len == tags->precision;
	if (width <= precise_len)
		return (ft_put(args, tags));
	// if (ft_strncmp(str, "(null)", len) != 0)
	tags->width -= precise_len;
	if (ft_put(args, tags) == -1)
		return (-1);
	return (width);
}

int	convert_to_decimal(va_list args, t_tags *tags, int (*ft_put)(va_list args))
{
	unsigned int	width;
	unsigned int	len;
	unsigned int	ui;
	int				i;

	if (tags->type == 'u')
		len = num_length_ui(*((unsigned int *)args));
	else
		len = num_length_i(*((int *)arg));
	width = tags->width;
	if (*((int *)arg) == 0 && tags->precision == 0)
		return (width);
	if (tags->precision != -1)
		if (apply_option_precision(tags, len) == -1)
			return (-1);
	if (width <= (unsigned int)tags->precision)
		return (ft_put(arg));
	tags->width -= tags->precision;
	if (apply_option_width(arg, tags, ft_put) == -1)
		return (-1);
	return (width);
}

static int	mark_0x(t_tags *tags, unsigned int *len)
{
	char	mark[3];

	mark[0] = '0';
	if (tags->type == 'X')
		mark[1] = 'X';
	else
		mark[1] = 'x';
	mark[2] = 0;
	*len += 2;
	return (ft_putstr(mark));
}

int	convert_to_hexa(va_list args, t_tags *tags, int (*ft_put)(va_list args))
{
	unsigned int	width;
	unsigned int	len;
	size_t			num;

	num = va_arg(args, unsigned int);
	if (tags->type == 'p')
	len = num_length_hexa((size_t)num);
	width = tags->width;
	if (num == 0 && tags->precision == 0)
		return (width);
	if (tags->hash == 1 && tags->type != 'p')
		if (mark_0x(tags, &len) == -1)
			return (-1);
	if (tags->precision != -1 && tags->type != 'p')
		if (apply_option_precision(tags, len) == -1)
			return (-1);
	if (tags->width <= (int)len)
		return (ft_put(args));
	tags->width -= len;
	if (apply_option_width(args, tags, ft_put) == -1)
		return (-1);
	return (width);
}

// int	apply_type_s(char *str, t_tags *tags)
// {
// 	int	width;
// 	int	len;
// 	int	max;

// 	width = tags->width;
// 	len = ft_strlen(str);
// 	max = tags->precision;
// 	str[max] = 0;
// 	if (width <= len)
// 		return (ft_putstr_free(str));
// 	if (tags->minus == 1)
// 		if (ft_putstr_free(str) == -1)
// 			return (-1);
// 	tags->width -= len;
// 	if (apply_option_width(tags) == -1)
// 		return (-1);
// 	if (tags->minus == 0)
// 		if (ft_putstr_free(str) == -1)
// 			return (-1);
// 	return (width);
// }
