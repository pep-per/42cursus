/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:38:49 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/10 14:00:50 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putstr_free(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
		{
			free(s);
			return (-1);
		}
		i++;
	}
	free(s);
	return (i);
}
