/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:10:24 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/30 15:11:50 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	parse_type(int c, t_tags *tags, va_list args, int (*flag[])(t_tags *tags))
{
	if (c == 'c')
		return ();
	else if (c == 's')
		return ();

	if (str[i] == 'c')
		res_len += ft_putchar(va_arg(ap, int));
}

void	apply_flags(int (*flag[])(t_tags *tags))
{
	// 함수 포인터 배열 초기화
	flag[0] = &f_width;
	flag[1] = &f_precision;
	flag[2] = &f_num;
}

int	parse_flags(int c, t_tags *tags, va_list args)
{
	if (c == '0')
		tags->zero = 1;
}

int	parse_format(const char *format, t_tags *tags, va_list args)
{
	int		i;
	int		len;
	int		(*flag[3])(t_tags *tags);

	i = 0;
	len = 0;
	init_flags(flag);
	while (format[i])
	{
		if (format[i] == 'c' || format[i] == 'p' || format[i] == 'd' \
			|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u' \
			|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
			len += parse_type(format[i], tags, args, flag);
		else
		{

			// 구조체에 플래그 할당
			if (parse_flags(format[i], tags, args) == -1)
				return (-1);
			else

		}
		i++;
	}
	//write 실패 시  -1 리턴
	//해석 실패 시 - 1 리턴
	//오버플로우 - 1 리턴
	return (i);
}

int	input_format(const char *format, va_list args)
{
	int		len;
	int		i;
	t_tags	*tags;

	len = 0;
	i = 0;
	//tags 초기화
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			i = parse_format(format, tags, args);
			if (i == -1)
				return (-1);
			len += i;
			format += i;
			//tags 초기화
		}
		else
		{
			len += 1;
			if (write(1, format, 1) == -1)
				return (-1);
		}
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = input_format(format, args);
	va_end(args);
	free((char *)format);
	return (len);
}
