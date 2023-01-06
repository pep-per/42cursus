/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:41:29 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 11:10:28 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	initialize(t_tags *tags, int (*ft_put[])(void *p, unsigned int len))
{
	tags->type = 0;
	tags->width = 0;
	tags->precision = -1;
	tags->minus = 0;
	tags->plus = 0;
	tags->zero = 0;
	tags->hash = 0;
	tags->space = 0;
	ft_put[0] = &ft_putstr;
	ft_put[1] = &ft_put_address;
	ft_put[2] = &ft_put_hexa_lower;
	ft_put[3] = &ft_put_hexa_upper;
	ft_put[4] = &ft_itoa;
	ft_put[5] = &ft_uitoa;
}

int	is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
			|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	is_option(char c)
{
	return (c == '-' || c == '+' || c == '0' \
			|| c == '#' || c == ' ' || c == '.');
}
