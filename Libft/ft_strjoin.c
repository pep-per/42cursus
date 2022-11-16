/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:19:03 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/16 00:30:06 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len1;
	unsigned int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	if (!new)
		return (0);
	i = 0;
	while (i < len1)
	{
		new[i] = (char)s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		new[i++] = (char)s2[j++];
	}
	new[i] = 0;
	return (new);
}
