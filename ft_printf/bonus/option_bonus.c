/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:53:12 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/14 02:56:11 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	apply_option_width(t_tags *tags)
{
	int	w;

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

// int	apply_option_precision(t_tags *tags)
// {
// 	return (1);
// }
