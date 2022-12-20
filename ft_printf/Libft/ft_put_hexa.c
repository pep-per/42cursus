/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:28:44 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/20 15:19:05 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	num_length_hexa(size_t n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	hexa_to_str(size_t n, char *hexa, int is_address)
{
	unsigned int	len;
	unsigned int	i;
	char			*str;

	len = num_length_hexa(n);
	if (is_address)
		len += 2;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	str[len] = 0;
	i = len - 1;
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i--] = hexa[n % 16];
		n /= 16;
	}
	if (is_address)
	{
		str[0] = '0';
		str[1] = 'x';
	}
	return (ft_putstr_free(str));
}

int	ft_put_address(va_list args)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	return (hexa_to_str((size_t)arg, hexa, 1));
}

int	ft_put_hexa_lower(void *arg)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	return (hexa_to_str(*((unsigned int *)arg), hexa, 0));
}

int	ft_put_hexa_upper(void *arg)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	return (hexa_to_str(*((unsigned int *)arg), hexa, 0));
}
