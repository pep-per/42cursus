/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:43:48 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/17 12:42:19 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	num_length_i(long long num)
{
	unsigned int	len;

	len = 0;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	else if (num == 0)
		len = 1;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int	ft_itoa(void *arg)
{
	long long		num;
	unsigned int	len;
	unsigned int	i;
	char			*str;

	num = *((long long *)arg);
	len = num_length_i(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	else if (num == 0)
		str[0] = '0';
	str[len] = 0;
	i = len - 1;
	while (num > 0)
	{
		str[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (ft_putstr_free(str));
}
