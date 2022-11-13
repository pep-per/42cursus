/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:54:08 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/12 22:33:17 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	p = malloc(sizeof(count) * size);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		*(p + i) = 0;
		i++;
	}
	return ((void *)p);
}
