/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:53:12 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 22:59:10 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		c = '0';
	i = 0;
	while (i < w)
		blank[i++] = c;
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

int	fill_width_hexa(t_tags *tags, int total, unsigned int num)
{
	if (tags->minus == 0 && !(tags->hash == 1 && tags->zero == 1 \
		&& tags->precision == -1))
		if (fill_width(tags, total) == -1)
			return (-1);
	if (tags->hash == 1 && num != 0)
	{
		if (tags->type == 'X')
		{
			if (write(1, "0X", 2) == -1)
				return (-1);
		}
		else
		{
			if (write(1, "0x", 2) == -1)
				return (-1);
		}
	}
	if (tags->minus == 0 && tags->hash == 1 && tags->zero == 1 \
		&& tags->precision == -1)
		if (fill_width(tags, total) == -1)
			return (-1);
	return (1);
}

int	handle_sign_option(t_tags *tags, int is_minus)
{
	int	c;

	c = '+';
	if (is_minus)
		c = '-';
	else
	{
		if (tags->space == 1)
			c = ' ';
	}
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	fill_width_decimal(t_tags *tags, int total, long long num)
{
	if (tags->minus == 0 && !(tags->zero == 1 && tags->precision == -1))
		if (fill_width(tags, total) == -1)
			return (-1);
	if ((tags->type != 'u' && (tags->plus || tags->space)) || (num < 0))
		if (handle_sign_option(tags, (num < 0)) == -1)
			return (-1);
	if (tags->minus == 0 && tags->zero == 1 && tags->precision == -1)
		if (fill_width(tags, total) == -1)
			return (-1);
	return (1);
}
