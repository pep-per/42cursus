/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:45:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/14 05:06:53 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	apply_type_c(char c, t_tags *tags)
{
	int	width;

	width = tags->width;
	if (width == 0)
		return (ft_putchar(c));
	if (tags->minus == 1)
		if (ft_putchar(c) == -1)
			return (-1);
	tags->width -= 1;
	if (apply_option_width(tags) == -1)
		return (-1);
	if (tags->minus == 0)
		if (ft_putchar(c) == -1)
			return (-1);
	return (width);
}

int	apply_type_s(char *str, t_tags *tags)
{
	int	width;
	int	len;
	int	max;

	if (!str)
		str = ft_strdup("(null)");
	width = tags->width;
	len = ft_strlen(str);
	max = tags->precision;
	str[max] = 0;
	if (width == 0 || width <= len)
		return (ft_putstr(str));
	if (tags->minus == 1)
		if (ft_putstr(str) == -1)
			return (-1);
	tags->width -= len;
	if (apply_option_width(tags) == -1)
		return (-1);
	if (tags->minus == 0)
		if (ft_putstr(str) == -1)
			return (-1);
	return (width);
}

int	apply_type_p(void *arg, t_tags *tags)
{
	int	width;
	int	len;

	if (!arg)
		return (ft_put_hexa(0, 0, 1));
	width = tags->width;
	len = num_length((size_t)arg);
	if (width == 0 || width <= len)
		return (ft_put_hexa((size_t)arg, 0, 1));
	if (tags->minus == 1)
		if (ft_put_hexa((size_t)arg, 0, 1) == -1)
			return (-1);
	tags->width -= len;
	if (apply_option_width(tags) == -1)
		return (-1);
	if (tags->minus == 0)
		if (ft_put_hexa((size_t)arg, 0, 1) == -1)
			return (-1);
	return (width);
}

int	apply_type_d(int n, t_tags *tags)
{
	int	width;

	return (ft_itoa(n));
}

int	apply_type_u(unsigned int ui, t_tags *tags)
{
	return (ft_uitoa(ui));

}

int	apply_type_x(unsigned int ui, int is_upper, t_tags *tags)
{
	return (ft_put_hexa(ui, is_upper, 0));

}
