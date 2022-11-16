/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:26:36 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/16 20:48:15 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;
	char		c;

	num = (long long)n;
	if (num >= 0)
	{
		if (num >= 10)
			ft_putnbr_fd(num / 10, fd);
	}
	else
	{
		num = -num;
		write(fd, "-", 1);
		if (num >= 10)
			ft_putnbr_fd(num / 10, fd);
	}
	c = num % 10 + '0';
	write(fd, &c, 1);
}
