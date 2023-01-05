/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:53:12 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/05 19:35:02 by jiyeolee         ###   ########.fr       */
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

void	parse_option(char c, t_tags *tags)
{
	if (!ft_isdigit((int)c) && !is_option(c))
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
