/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:00:56 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/16 21:17:23 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_backward(char *s1, char *s2, size_t len, size_t i)
{
	s1 += len;
	s2 += len;
	while (i < len)
	{
		*(s1 - i - 1) = *(s2 - i - 1);
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*s1;
	char	*s2;

	if (dst == src)
		return (dst);
	s1 = (char *)dst;
	s2 = (char *)src;
	i = 0;
	if (s2 < s1)
	{
		copy_backward(s1, s2, len, i);
	}
	else
	{
		while (i < len)
		{
			*(s1 + i) = *(s2 + i);
			i++;
		}
	}
	return (dst);
}
