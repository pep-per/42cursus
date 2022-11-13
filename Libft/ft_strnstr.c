/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:15:54 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/12 23:21:50 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_needle(const char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i] && haystack[i] == needle[i])
	{
		if (needle[i] != haystack)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == 0 || len == 0)
		return (haystack);
	i = 0;
	while (haystack[i] && len)
	{
		if(find_needle(&haystack[i], needle))
			return (&haystack[i]);
		len--;
		i++;
	}
	return (0);	
}
