/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:01:08 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/20 22:32:08 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put_to_char(va_list args, t_tags *tags)
{
	char	c;
	int		i;
	int		width;

	c = (char)va_arg(args, int);
	if (tags->minus == 0)
		if (apply_option_width(tags) == -1)
			return (-1);
	if (ft_putchar(c) == -1)
		return (-1);
	if (tags->minus == 1)
		if (apply_option_width(tags) == -1)
			return (-1);
	return (1);
}


int	ft_putstr_free(va_list args, t_tags *tags)
{
	char	*str;
	int		i;
	int		len;
	int		width;
	int		precise_len;
	
	str = va_arg(args, char *);
	if (!str)
		str = ft_strdup("(null)");
	if (!str)
		return (-1);
	str[tags->precision] = 0;
	len = ft_strlen(str);
	if (apply_option_precision(tags, len) == -1)
		return (-1);
	width = tags->width;
	precise_len == tags->precision;
	if (width <= precise_len)
		return (width);
	tags->width -= precise_len;
	if (tags->minus == 0)
		if (apply_option_width(tags) == -1)
			return (-1);
	i = 0;
	while (str[i])
	{
		if (ft_putchar(str[i]) == -1)
		{
			free(str);
			return (-1);
		}
		i++;
	}
	if (tags->minus == 1)
		if (apply_option_width(tags) == -1)
			return (-1);
	free(str);
	return (width);
}
