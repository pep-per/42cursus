/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:16:04 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/14 16:01:44 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	uc;

	i = 0;
	str = (unsigned char *)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (*(str + i) == uc)
			return (str + i);
		i++;
	}
	return (0);
}
