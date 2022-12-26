/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:45:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/27 08:11:28 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	apply_type_char(va_list args, t_tags *tags)
{
	char	c;

	c = (char)va_arg(args, int);
	if (tags->width == 0)
		tags->width = 1;
	if (tags->minus == 0)
		if (apply_width(tags, 1) == -1)
			return (-1);
	if (write(1, &c, 1) == -1)
		return (-1);
	if (tags->minus == 1)
		if (apply_width(tags, 1) == -1)
			return (-1);
	return (tags->width);
}


int	apply_type_str(va_list args, t_tags *tags, \
					int (*ft_put)(void *p, unsigned int len))
{
	char	*arg;
	char	*str;
	int		len;
	int		precise_len;

	arg = va_arg(args, char *);
	str = ft_strdup("(null)");
	if (!str)
		return (-1);
	len = handle_null_strlen(arg, str);
	precise_len = check_precise_len(tags, len);
	if (tags->minus == 0)
		if (apply_width_str(tags, precise_len, str) == -1)
			return (-1);
	if (handle_null_ft_put(arg, str, precise_len, ft_put) == -1)
	{
		free(str);
		return (-1);
	}
	if (tags->minus == 1)
		if (apply_width_str(tags, precise_len, str) == -1)
			return (-1);
	free(str);
	return (tags->width);
}

int	convert_to_decimal(va_list args, t_tags *tags, \
						int (*ft_put)(void *p, unsigned int len))
{
	long long	num;
	int			len;
	int			precise_len;
	char		c;

	if (tags->type == 'u')
		num = (long long)va_arg(args, unsigned int);
	else
		num = (long long)va_arg(args, int);
	len = (int)num_length_i(num);
	precise_len = len;
	if (tags->precision > len)
		precise_len = tags->precision;
	if ((tags->type != 'u' && (tags->plus || tags->space)) || (num < 0))
		precise_len += 1;
//	precise_len = check_precise_len(tags, len);
	if (tags->minus == 0 && (tags->zero == 0 || tags->precision != -1))
		if (apply_width(tags, precise_len) == -1)
			return (-1);
	if ((tags->type != 'u' && (tags->plus || tags->space)) || (num < 0))
	{
		c = '+';
		if (num < 0)
			c = '-';
		else
		{
			if (tags->space == 1)
				c = ' ';
		}
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	if (tags->minus == 0 && tags->zero == 1 && tags->precision == -1)
		if (apply_width(tags, precise_len) == -1)
			return (-1);
	if (apply_precision(tags, len) == -1)
		return (-1);
	if (ft_put(&num, (unsigned int)len) == -1)
		return (-1);
	if (tags->minus == 1)
		if (apply_width(tags, precise_len) == -1)
			return (-1);
	if (tags->width < precise_len)
		return (precise_len);
	return (tags->width);
}

int	convert_to_hexa(va_list args, t_tags *tags, \
					int (*ft_put)(void *p, unsigned int len))
{
	unsigned int	num;
	int				len;
	int				precise_len;

	num = va_arg(args, unsigned int);
	len = (int)num_length_hexa((size_t)num);
	precise_len = check_precise_len(tags, len);
	if (tags->minus == 0)
		if (apply_width(tags, precise_len) == -1)
			return (-1);
	if (tags->hash == 1)
	{
		if (mark_0x(tags) == -1)
			return (-1);
		precise_len += 2;
	}
	if (apply_precision(tags, precise_len) == -1)
		return (-1);
	if (ft_put(&num, (unsigned int)precise_len) == -1)
		return (-1);
	if (tags->minus == 1)
		if (apply_width(tags, precise_len) == -1)
			return (-1);
	return (tags->width);
}

int	convert_to_adress(va_list args, t_tags *tags, \
					int (*ft_put)(void *p, unsigned int len))
{
	void	*adress;
	int		len;

	adress = va_arg(args, void *);
	len = (int)num_length_hexa((size_t)adress);
	// precise_len = check_precise_len(tags, len);
	// if (tags->width < len)
	// 	tags->width = len;
	if (tags->minus == 0)
		if (apply_width(tags, len + 2) == -1)
			return (-1);
	if (mark_0x(tags) == -1)
		return (-1);
	// if (tags->precision != -1)
	// 	if (apply_precision(tags, len) == -1)
	// 		return (-1);
	if (ft_put(adress, (unsigned int)len) == -1)
		return (-1);
	// printf("1*")
	if (tags->minus == 1)
		if (apply_width(tags, len + 2) == -1)
			return (-1);
	if (len + 2 < tags->width)
		return (tags->width);
	return (len + 2);
}
