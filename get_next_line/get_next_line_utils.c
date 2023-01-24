/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:39 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/24 12:37:38 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

char	*ft_strjoin(t_backup *backup, char *buf, size_t read_num)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = (char *)malloc(sizeof(char) * (backup->length + read_num + 1));
	if (!new)
		return (0);
	i = 0;
	while (i < backup->length)
	{
		new[i] = backup->start[i];
		i++;
	}
	j = 0;
	while (j < read_num)
	{
		new[i++] = buf[j++];
	}
	new[i] = 0;
	backup->length += read_num;
	//free(buf);
	//buf = 0;
	return (new);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
