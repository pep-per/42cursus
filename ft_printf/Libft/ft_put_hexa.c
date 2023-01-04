/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:28:44 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/04 22:13:39 by jiyeolee         ###   ########.fr       */
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

int	hexa_to_str(size_t n, unsigned int len, char *hexa)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);
	if (n == 0)
		str[0] = '0';
	str[len] = 0;
	i = len - 1;
	while (n > 0)
	{
		str[i--] = hexa[n % 16];
		n /= 16;
	}
	return (ft_putstr_free(str, len));
}
