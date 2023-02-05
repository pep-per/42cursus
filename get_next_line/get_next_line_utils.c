/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:39 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/05 09:48:21 by jiyeolee         ###   ########.fr       */
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

char	*ft_strjoin(char *line, char *buf, ssize_t read_num)
{
	char	*new;
	// char	*start;
	ssize_t	len;
	ssize_t	i;
	ssize_t	j;

	len = 0;
	while (line[len])
		len++;
	new = (char *)malloc(sizeof(char) * (len + read_num + 1));
	if (!new)
		return (0);
	// start = curr->backup;
	i = 0;
	while (i < len)
	{
		new[i] = line[i];
		i++;
	}
	j = 0;
	while (j < read_num)
	{
		new[i++] = buf[j++];
	}
	new[i] = 0;
	// curr->backup_len += read_num;
	return (new);
}

char	*ft_strdup(char *buf, ssize_t len)
{
	char	*dst;
	ssize_t	i;

	if (len == 0)
		return (0);
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
	// curr->backup_len += len;
	return (dst);
}

t_link	*find_node_or_make_new(t_link **head, int fd)
{
	t_link	*new;
	t_link	*curr;

	curr = *head;
	while (curr->next != NULL && curr->fd != fd)
		curr = curr->next;
	if (curr->fd == fd)
		return (curr);
	new = (t_link *)malloc(sizeof(t_link));
	if (!new)
		return (0);
	new->fd = fd;
	new->next = NULL;
	new->backup = NULL;
	new->backup_len = 0;
	curr->next = new;
	return (new);
}


void	free_current_node(t_link **curr, char *buf)
{
	free(buf);
	buf = NULL;
	free(*curr);
	*curr = NULL;
}

// void	free_all(t_link **head)
// {
// 	t_link	*curr;
// 	t_link	*tmp;

// 	curr = *head;
// 	while (curr)
// 	{
// 		tmp = curr;
// 		curr = curr->next;
// 		free(tmp);
// 	}
// 	*head = NULL;
// }

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = 0;
		i++;
	}
}
