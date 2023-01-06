/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:01:08 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 20:45:26 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put_address(void *p, unsigned int len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	return (hexa_to_str((size_t)p, len, hexa));
}

int	ft_put_hexa_lower(void *p, unsigned int len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	return (hexa_to_str(*((unsigned int *)p), len, hexa));
}

int	ft_put_hexa_upper(void *p, unsigned int len)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	return (hexa_to_str(*((unsigned int *)p), len, hexa));
}
