/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:06:20 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 23:00:45 by jiyeolee         ###   ########.fr       */
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

void	atoi_handle_overflow(int *num, char c, t_tags *tags)
{
	long long	total;

	total = 10 * (long long)(*num) + (c - '0');
	if (total > 2147483647)
	{
		if (tags->precision == -1)
			tags->width = -1;
		tags->type = -1;
	}
	else
	{
		*num = total;
	}
}

int	handle_format_overflow(t_tags *tags, int type)
{
	if (tags->type == -1 && (type != 's' || tags->width == -1))
	{
		free(tags);
		return (-1);
	}
	return (1);
}
