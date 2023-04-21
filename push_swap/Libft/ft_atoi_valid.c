/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:50:48 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/21 22:25:41 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_valid(const char *str, int *result)
{
	long long	num;
	int			i;
	int			sign;

	num = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = (num * 10) + sign * (str[i] - '0');
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	*result = num;
	return (1);
}
