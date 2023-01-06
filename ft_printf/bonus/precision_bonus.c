/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:52:07 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 21:05:28 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_str_precision(t_tags *tags, int len)
{
	int	p;

	p = tags->precision;
	if (len == 0)
		return (0);
	else if (p == -1 || p >= len || tags->type == -1)
		return (len);
	else
		return (p);
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
	int		p;
	char	*blank;
	int		i;

	p = tags->precision - len;
	if (p <= 0)
		return (1);
	blank = (char *)malloc(sizeof(char) * p);
	if (!blank)
		return (-1);
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
