/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:40:29 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/10 14:24:05 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	num_length(unsigned int n)
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

int	ft_uitoa(unsigned int n)
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	len = num_length(n);
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
