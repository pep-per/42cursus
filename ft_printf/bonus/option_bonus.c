/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:53:12 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 05:27:48 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	fill_width(t_tags *tags, int total)
{
	int		w;
	char	*blank;	
	int		c;
	int		i;

	w = tags->width - total;
	if (w <= 0)
		return (1);
	blank = (char *)malloc(sizeof(char) * w);
	if (!blank)
		return (-1);
	c = ' ';
	if (tags->zero == 1 && tags->minus == 0 && tags->precision == -1 \
		&& tags->type != 'c' && tags->type != 's' && tags->type != 'p')
	{
		c = '0';
	}
	i = 0;
	while (i < w)
		blank[i++] = c;
	// blank = ft_memset(blank, c, w);
	if (ft_putstr_free(blank, w) == -1)
		return (-1);
	return (1);
}

int	fill_width_str(t_tags *tags, int total, char *str)
{
	if (tags->width < total)
		tags->width = total;
	if (fill_width(tags, total) == -1)
	{
		free(str);
		return (-1);
	}
	return (1);
}
//부호는 빼고 계산
// 오버플로우 일떄도 s 옵션은 출력

int	fill_width_hexa(t_tags *tags, int total, unsigned int num)
{
	if (tags->minus == 0 && !(tags->hash == 1 && tags->zero == 1 \
		&& tags->precision == -1))
	{
		if (fill_width(tags, total) == -1)
			return (-1);
	}
	if (tags->hash == 1 && num != 0)
		if (mark_0x(tags) == -1)
			return (-1);
	if (tags->minus == 0 && tags->hash == 1 && tags->zero == 1 \
		&& tags->precision == -1)
	{
		if (fill_width(tags, total) == -1)
			return (-1);
	}
	return (1);
}

int	handle_str_precision(t_tags *tags, int len)
{
	int	p;

	p = tags->precision;
	if (len == 0)
		return (0);
	else if (p == -1 || p >= len)
		return (len);
	else
		return (p);
	// if (tags->precision > len)
	// 	precise_len = tags->precision;
}

int	handle_digit_precision(t_tags *tags, int len, long long num)
{
	int	p;
	int	result;

	p = tags->precision;
	result = len;
	if (p > len)
		result = p;
	if (p == 0 && num == 0)
		result = 0;
	if (tags->type == 'x' || tags->type == 'X')
		if (tags->hash == 1 && num != 0)
			result += 2;
	if (tags->type == 'i' || tags->type == 'd')
		if (tags->plus || tags->space || (num < 0))
			result += 1;
	return (result);
}

int	fill_precision(t_tags *tags, int len)
{
	int	p;
	char			*blank;
	int		i;

	p = tags->precision - len;
	if (p <= 0)
		return (1);
	blank = (char *)malloc(sizeof(char) * p);
	if (!blank)
		return (-1);
	// blank = ft_memset(blank, '0', p);
	i = 0;
	while (i < p)
	{
		blank[i] = '0';
		i++;
	}
	if (ft_putstr_free(blank, p) == -1)
		return (-1);
	return (1);
}

void	parse_option(int c, t_tags *tags)
{
	if (!ft_isdigit(c) && !is_option(c))
		return ;
	if (c == '-')
	{
		tags->minus = 1;
		// if (tags->precision != -1)
		// 	tags->precision = -1;
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
