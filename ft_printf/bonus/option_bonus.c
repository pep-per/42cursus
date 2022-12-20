/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:53:12 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/20 22:31:59 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	apply_option_width(t_tags *tags)
{
	int		w;

	w = tags->width;
	while (w--)
	{
		if (tags->zero == 1 && tags->minus == 0
			&& tags->type != 'c' && tags->type != 's' && tags->type != 'p')
		{
			if (ft_putchar('0') == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(' ') == -1)
				return (-1);
		}
	}
	return (1);
}


int	apply_option_precision(t_tags *tags, int len)
{
	int	p;

	p = tags->precision;
	if (p == 0)
		tags->zero = 0;
	else if (p > len)
	{
		while (p-- == len)
		{
			if (ft_putchar('0') == -1)
				return (-1);
		}
		// if (len != 0)
		// 	tags->width -= tags->precision;
	}
	else
	{
		tags->precision += len;
	}
	return (1);
}

// int	apply_option_width(va_list args, t_tags *tags, int (*ft_put)(va_list args))
// {
// 	int		w;

// 	if (tags->minus == 1)
// 		if (ft_put(args) == -1)
// 			return (-1);
// 	w = tags->width;
// 	while (w--)
// 	{
// 		if (tags->zero == 1 && tags->minus == 0
// 			&& tags->type != 'c' && tags->type != 's' && tags->type != 'p')
// 		{
// 			if (ft_putchar('0') == -1)
// 				return (-1);
// 		}
// 		else
// 		{
// 			if (ft_putchar(' ') == -1)
// 				return (-1);
// 		}
// 	}
// 	if (tags->minus == 0)
// 		if (ft_put(args) == -1)
// 			return (-1);
// 	return (1);
// }

// int	apply_option_precision(t_tags *tags, unsigned int len)
// {
// 	unsigned int	p;

// 	p = tags->precision;
// 	if (p == 0)
// 		tags->zero = 0;
// 	else if (p > len)
// 	{
// 		while (p-- == len)
// 		{
// 			if (ft_putchar('0') == -1)
// 				return (-1);
// 		}
// 		// if (len != 0)
// 		// 	tags->width -= tags->precision;
// 	}
// 	else
// 	{
// 		tags->precision += len;
// 	}
// 	return (1);
// }

void	atoi_handle_overflow(int *num, char c, t_tags *tags)
{
	int	total;

	total = 10 * (*num) + (c - '0');
	if (total < 0)
		tags->type = -1;
	else
		*num = total;
}

int	is_option(char c)
{
	return (c == '-' || c == '+' || c == '0' \
			|| c == '#' || c == ' ' || c == '.');
}

void	parse_option(char c, t_tags *tags)
{
	if (!ft_isdigit((int)c) && !is_option(c))
		return ;
	if (c == '-')
	{
		tags->minus = 1;
		if (tags->precision != -1)
			tags->precision = -1;
	}
	if (c == '+')
		tags->plus = 1;
	if (c == '#')
		tags->hash = 1;
	if (c == ' ')
		tags->space = 1;
	if (c == '.')
		tags->precision = 0;
	if (c == '0' && tags->width == 0 && tags->precision == -1)
		tags->zero = 1;
	else if (ft_isdigit((int)c) && tags->precision == -1)
		atoi_handle_overflow(&tags->width, c, tags);
	else if (ft_isdigit((int)c))
		atoi_handle_overflow(&tags->precision, c, tags);
}
