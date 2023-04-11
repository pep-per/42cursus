/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:50:48 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/11 19:04:22 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	check_sign(const char *str, int *i)
// {
// 	int	sign;

// 	sign = 1;
// 	if (str[*i] == '-' || str[*i] == '+')
// 	{
// 		if (str[*i] == '-')
// 			sign = -1;
// 		(*i)++;
// 		if (!ft_isdigit(str[*i]))
// 			sign = 0;
// 	}
// 	return (sign);
// }

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
