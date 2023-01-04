/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:53:12 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/04 18:24:49 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	apply_width(t_tags *tags, int len)
{
	int	w;

	// w = tags->width - tags->precision;
	w = tags->width - len;
	while (w-- > 0)
	{
		if (tags->zero == 1 && tags->minus == 0 && tags->precision == -1 \
			&& tags->type != 'c' && tags->type != 's' && tags->type != 'p')
		{
			if (write(1, "0", 1) == -1)
				return (-1);
		}
		else
		{
			if (write(1, " ", 1) == -1)
				return (-1);
		}
	}
	return (1);
}

int	apply_width_str(t_tags *tags, int len, char *str)
{
	if (apply_width(tags, len) == -1)
	{
		free(str);
		return (-1);
	}
	return (1);
}
//부호는 빼고 계산
// 오버플로우 일떄도 s 옵션은 출력

int	check_precise_len(t_tags *tags, int len)
{
	int	p;
	int	precise_len;

	p = tags->precision;
	if (len == 0)
	{
		precise_len = 0;
	}
	else if (p == -1 || p >= len)
	{
		precise_len = len;
	}
	else
	{
		precise_len = p;
	}
	if (tags->width < precise_len)
		tags->width = precise_len;
	// if (tags->precision > len)
	// 	precise_len = tags->precision;

	return (precise_len);
}

int	apply_precision(t_tags *tags, int len)
{
	int		p;

	p = tags->precision - len;
	while (p-- > 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
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
	long long	total;

	total = 10 * (*num) + (c - '0');
	if (total >= 2147483647)
	{
		tags->type = -1;
		if (tags->precision == -1)
			tags->width = -1;
	}
	else
		*num = total;
}

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
	if (c == '.' && tags->precision == -1)
		tags->precision = 0;
	if (c == '0' && tags->width == 0 && tags->precision == -1)
		tags->zero = 1;
	else if (ft_isdigit((int)c) && tags->precision == -1)
		atoi_handle_overflow(&tags->width, c, tags);
	else if (ft_isdigit((int)c))
		atoi_handle_overflow(&tags->precision, c, tags);
}
