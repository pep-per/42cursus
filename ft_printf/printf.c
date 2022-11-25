/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:10:24 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/26 04:36:04 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			while (/* condition */)
			{
				/* code */
			}
			if (/* condition */)
			{
				va_end(ap);
				return (-1);
				/* code */
			}
			
		}
		else
		{
			len += 1;
		}
	}
	va_end(ap);
	return (len);
}
