/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:41:29 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/17 15:28:01 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_tags(t_tags *tags)
{
	tags->type = 0;
	tags->width = 0;
	tags->precision = -1;
	tags->minus = 0;
	tags->plus = 0;
	tags->zero = 0;
	tags->hash = 0;
	tags->space = 0;
}

void	init_ft_put(int (*ft_put[])(void *))
{
	ft_put[0] = &ft_put_to_char;
	ft_put[1] = &ft_putstr_free;
	ft_put[2] = &ft_put_address;
	ft_put[3] = &ft_put_hexa_lower;
	ft_put[4] = &ft_put_hexa_upper;
	ft_put[5] = &ft_itoa;
	ft_put[6] = &ft_uitoa;
}

