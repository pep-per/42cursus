/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:45:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/24 13:37:37 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	apply_type_char(va_list args, t_tags *tags)
{
	char	c;

	c = (char)va_arg(args, int);
	// if (tags->width > tags->precision)
	//tags->width = 1;
	tags->precision = 1;
	if (tags->width == 0)
		tags->width = 1;
	if (tags->minus == 0)
		if (apply_width(tags) == -1)
			return (-1);
	if (write(1, &c, 1) == -1)
		return (-1);
	if (tags->minus == 1)
		if (apply_width(tags) == -1)
			return (-1);
	return (tags->width);
}

int	handle_null_strlen(char *arg, char *str)
{
	if (!arg)
	{
		str = ft_strdup("(null)");
		if (!str)
			return (-1);
		return ((int)ft_strlen(str));
	}
	return ((int)ft_strlen(arg));
}

int	handle_null_ft_put(char *arg, char *str, int len, \
						int (*ft_put)(void *p, unsigned int len))
{
	if (!arg)
	{
		if (ft_put(str, (unsigned int)len) == -1)
			return (-1);
	}
	else
	{
		if (write(1, arg, len) == -1)
			return (-1);
	}
	return (1);
}

int	apply_type_str(va_list args, t_tags *tags, \
					int (*ft_put)(void *p, unsigned int len))
{
	char	*arg;
	char	*str;
	int		len;

	arg = va_arg(args, char *);
	str = 0;
	len = handle_null_strlen(arg, str);
	if (len == -1)
		return (-1);
	precise_len(tags, len);
	// if (tags->width <= tags->precision)
	// 	tags->width = tags->precision;
	if (tags->minus == 0)
		if (apply_width(tags) == -1)
			return (-1);
	if (handle_null_ft_put(arg, str, len, ft_put) == -1)
		return (-1);
	if (tags->minus == 1)
		if (apply_width(tags) == -1)
			return (-1);
	return (tags->width);
}

int	convert_to_decimal(va_list args, t_tags *tags, \
						int (*ft_put)(void *p, unsigned int len))
{
	long long	num;
	int			len;

	if (tags->type == 'u')
		num = (long long)va_arg(args, unsigned int);
	else
		num = (long long)va_arg(args, int);
	len = (int)num_length_i(num);
	precise_len(tags, len);
	if (tags->width <= tags->precision)
		tags->width = tags->precision;
	if (tags->plus || tags->space || (num < 0))
		tags->width += 1;
	if (tags->minus == 0)
		if (apply_width(tags) == -1)
			return (-1);
	if (apply_sign_precision(tags, len, num) == -1)
		return (-1);
	if (ft_put(&num, (unsigned int)len) == -1)
		return (-1);
	if (tags->minus == 1)
		if (apply_width(tags) == -1)
			return (-1);
	return (tags->width);
}

int	convert_to_hexa(va_list args, t_tags *tags, \
					int (*ft_put)(void *p, unsigned int len))
{
	unsigned int	num;
	int				len;

	num = va_arg(args, unsigned int);
	len = (int)num_length_hexa((size_t)num);
	if (tags->hash == 1)
	{
		if (mark_0x(tags) == -1)
			return (-1);
		else
			len += 2;
	}
	precise_len(tags, len);
	if (tags->width <= tags->precision)
		tags->width = tags->precision;
	if (tags->minus == 0)
		if (apply_width(tags) == -1)
			return (-1);
	if (ft_put(&num, (unsigned int)len) == -1)
		return (-1);
	if (tags->minus == 1)
		if (apply_width(tags) == -1)
			return (-1);
	return (tags->width);
}

int	convert_to_adress(va_list args, t_tags *tags, \
					int (*ft_put)(void *p, unsigned int len))
{
	int		len;
	void	*adress;

	adress = va_arg(args, void *);
	len = (int)num_length_hexa((size_t)adress);
	precise_len(tags, len);
	if (tags->width <= tags->precision)
		tags->width = tags->precision;
	if (tags->minus == 0)
		if (apply_width(tags) == -1)
			return (-1);
	if (ft_put(adress, (unsigned int)len) == -1)
		return (-1);
	if (tags->minus == 1)
		if (apply_width(tags) == -1)
			return (-1);
	return (tags->width);
}
