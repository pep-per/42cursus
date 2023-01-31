/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:39 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/31 23:51:52 by jiyeolee         ###   ########.fr       */
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

char	*ft_strjoin(t_link *curr, char *buf, size_t read_num)
{
	char	*new;
	char	*start;
	size_t	i;
	size_t	j;

	new = (char *)malloc(sizeof(char) * (curr->backup_len + read_num + 1));
	if (!new)
		return (0);
	start = curr->backup;
	i = 0;
	while (i < curr->backup_len)
	{
		new[i] = start[i];
		i++;
	}
	j = 0;
	while (j < read_num)
	{
		new[i++] = buf[j++];
	}
	new[i] = 0;
	curr->backup_len += read_num;
	return (new);
}

char	*ft_strdup(t_link *curr, char *buf, size_t len)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = buf[i];
		i++;
	}
	dst[i] = 0;
	curr->backup_len += len;
	return (dst);
}

void	free_link(t_link *head)
{
	t_link	*curr;
	t_link	*tmp;

	curr = head;
	while (curr->next)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	//free(head);
}
