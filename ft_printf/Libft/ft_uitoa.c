/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:40:29 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/17 10:14:24 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	num_length_ui(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_uitoa(void *arg)
{
	unsigned int	n;
	unsigned int	len;
	unsigned int	i;
	char			*str;

	n = *((unsigned int *)arg);
	len = num_length_ui(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	if (n == 0)
		str[0] = '0';
	str[len] = 0;
	i = len - 1;
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (ft_putstr_free(str));
}
