/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_num_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:28:31 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/17 14:28:37 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf_bonus.h"



// int	apply_type_p(void *arg, t_tags *tags)
// {
// 	int	width;
// 	int	len;

// 	width = tags->width;
// 	len = num_length_hexa((size_t)arg);
// 	if (width <= len)
// 		return (ft_put_hexa((size_t)arg, 0, 1));
// 	if (tags->minus == 1)
// 		if (ft_put_hexa((size_t)arg, 0, 1) == -1)
// 			return (-1);
// 	tags->width -= len;
// 	if (apply_option_width(tags) == -1)
// 		return (-1);
// 	if (tags->minus == 0)
// 		if (ft_put_hexa((size_t)arg, 0, 1) == -1)
// 			return (-1);
// 	return (width);
//	}

// int	apply_type_d(int n, t_tags *tags)
// {
// 	int	width;
// 	int	len;
// 	unsigned int	ui;

// 	width = tags->width;
// 	if (n == 0 && tags->precision == 0)
// 		return (width);
// 	ui = (unsigned int)n;
// 	if (apply_option_precision(&ui, num_length_i(ui), tags) == -1)
// 		return (-1);
// 	n = ui;
// 	if (n < 0)
// 		n = -ui;
// 	len = num_length_i(n);
// 	if (width <= len)
// 		return (ft_itoa(n));
// 	if (tags->minus == 1)
// 		if (ft_itoa(n) == -1)
// 			return (-1);
// 	tags->width -= len;
// 	if (apply_option_width(tags) == -1)
// 		return (-1);
// 	if (tags->minus == 0)
// 		if (ft_itoa(n) == -1)
// 			return (-1);
// 	return (width);
// }

// int	apply_type_u(unsigned int ui, t_tags *tags)
// {
// 	int	width;
// 	int	len;

// 	width = tags->width;
// 	if (ui == 0 && tags->precision == 0)
// 		return (width);
// 	if (apply_option_precision(&ui, num_length_ui(ui), tags) == -1)
// 		return (-1);
// 	len = num_length_ui(ui);
// 	if (width <= len)
// 		return (ft_uitoa(ui));
// 	if (tags->minus == 1)
// 		if (ft_uitoa(ui) == -1)
// 			return (-1);
// 	tags->width -= len;
// 	if (apply_option_width(tags) == -1)
// 		return (-1);
// 	if (tags->minus == 0)
// 		if (ft_uitoa(ui) == -1)
// 			return (-1);
// 	return (width);
// }

// int	apply_type_x(unsigned int ui, int is_upper, t_tags *tags)
// {
// 	int		width;
// 	int		len;

// 	if (tags->hash == 1)
// 		if (mark_0x(is_upper) == -1)
// 			return (-1);
// 	width = tags->width;
// 	if (ui == 0 && tags->precision == 0)
// 		return (width);
// 	if (apply_option_precision(&ui, num_length_hexa(ui), tags) == -1)
// 		return (-1);
// 	len = num_length_hexa(ui);
// 	if (width <= len)
// 		return (ft_put_hexa(ui, is_upper, 0));
// 	if (tags->minus == 1)
// 		if (ft_put_hexa(ui, is_upper, 0) == -1)
// 			return (-1);
// 	tags->width -= len;
// 	if (apply_option_width(tags) == -1)
// 		return (-1);
// 	if (tags->minus == 0)
// 		if (ft_put_hexa(ui, is_upper, 0) == -1)
// 			return (-1);
// 	return (width);
// }
