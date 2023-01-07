/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:38:49 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/05 18:33:55 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_free(void *p, unsigned int len)
{
	if (write(1, (char *)p, len) == -1)
	{
		free(p);
		return (-1);
	}
	free(p);
	return (1);
}

int	ft_putstr(void *p, unsigned int len)
{
	return (write(1, (char *)p, len));
}
