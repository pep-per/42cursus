/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:15:54 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/16 21:21:46 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_needle(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && haystack[i] == needle[i] && needle[i])
		i++;
	if (needle[i] == 0)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (find_needle(&haystack[i], needle, len - i))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
