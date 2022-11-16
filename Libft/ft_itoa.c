/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:43:48 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/16 21:16:42 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	num_length(long long num)
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

char	*ft_itoa(int n)
{
	long long		num;
	unsigned int	len;
	unsigned int	i;
	char			*str;

	num = (long long)n;
	len = num_length(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
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
	return (str);
}
