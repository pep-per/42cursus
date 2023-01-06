/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:45:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 19:06:28 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	convert_to_char(va_list args, t_tags *tags)
{
	int	c;

	if (tags->type == '%')
		c = '%';
	else
		c = (char)va_arg(args, int);
	if (tags->minus == 0)
		if (fill_width(tags, 1) == -1)
			return (-1);
	if (write(1, &c, 1) == -1)
		return (-1);
	if (tags->minus == 1)
		if (fill_width(tags, 1) == -1)
			return (-1);
	if (tags->width > 1)
		return (tags->width);
	return (1);
}

int	convert_to_str(va_list args, t_tags *tags, \
					int (*ft_put)(void *p, unsigned int len))
{
	char	*arg;
	char	*str;
	int		len;
	int		total;

	arg = va_arg(args, char *);
	str = ft_strdup("(null)");
	if (!str)
		return (-1);
	len = handle_null_strlen(arg, str);
	total = handle_str_precision(tags, len);
	if (tags->minus == 0)
		if (fill_width_str(tags, total, str) == -1)
			return (-1);
	if (handle_null_ft_put(arg, str, total, ft_put) == -1)
	{
		free(str);
		return (-1);
	}
	if (tags->minus == 1)
		if (fill_width_str(tags, total, str) == -1)
			return (-1);
	free(str);
	return (tags->width);
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

int	convert_to_decimal(va_list args, t_tags *tags, \
						int (*ft_put)(void *p, unsigned int len))
{
	long long	num;
	int			len;
	int			total;

	if (tags->type == 'u')
		num = (long long)va_arg(args, unsigned int);
	else
		num = (long long)va_arg(args, int);
	len = (int)num_length_i(num);
	total = handle_digit_precision(tags, len, num);
	if (tags->minus == 0 && !(tags->zero == 1 && tags->precision == -1))
		if (fill_width(tags, total) == -1)
			return (-1);
	if ((tags->type != 'u' && (tags->plus || tags->space)) || (num < 0))
		if (handle_sign_option(tags, (num < 0)) == -1)
			return (-1);
	if (tags->minus == 0 && tags->zero == 1 && tags->precision == -1)
		if (fill_width(tags, total) == -1)
			return (-1);
	if (fill_precision(tags, len) == -1)
		return (-1);
	// if (tags->precision == 0 && num == 0)
	// 	len = 0;
	if (!(tags->precision == 0 && num == 0))
		if (ft_put(&num, (unsigned int)len) == -1)
			return (-1);
	if (tags->minus == 1)
		if (fill_width(tags, total) == -1)
			return (-1);
	if (tags->width < total)
		return (total);
	return (tags->width);
}

int	convert_to_hexa(va_list args, t_tags *tags, \
					int (*ft_put)(void *p, unsigned int len))
{
	unsigned int	num;
	int				len;
	int				total;

	num = va_arg(args, unsigned int);
	len = (int)num_length_hexa(num);
	total = handle_digit_precision(tags, len, num);
	if (fill_width_hexa(tags, total, num) == -1)
		return (-1);
	if (fill_precision(tags, len) == -1)
		return (-1);
	if (!(tags->precision == 0 && num == 0))
		if (ft_put(&num, (unsigned int)len) == -1)
			return (-1);
	if (tags->minus == 1)
		if (fill_width(tags, total) == -1)
			return (-1);
	if (tags->width < total)
		return (total);
	return (tags->width);
}

int	convert_to_adress(va_list args, t_tags *tags, \
					int (*ft_put)(void *p, unsigned int len))
{
	void	*adress;
	int		len;

	adress = va_arg(args, void *);
	len = (int)num_length_hexa((size_t)adress);
	if (tags->minus == 0)
		if (fill_width(tags, len + 2) == -1)
			return (-1);
	if (mark_0x(tags) == -1)
		return (-1);
	if (ft_put(adress, (unsigned int)len) == -1)
		return (-1);
	if (tags->minus == 1)
		if (fill_width(tags, len + 2) == -1)
			return (-1);
	if (tags->width < len + 2)
		return (len + 2);
	return (tags->width);
}
