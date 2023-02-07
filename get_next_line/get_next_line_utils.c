/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:39 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/07 22:48:42 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(t_link *curr, char *old)
{
	char	*new;
	ssize_t	i;
	ssize_t	j;
	ssize_t	len;

	len = 0;
	while (len < curr->read_byte && curr->buffer[len] == '\n')
		len++;
	new = (char *)malloc(len + ft_strlen(old) + 1);
	if (!new)
		return (0);
	i = -1;
	while (old[++i])
		new[i] = old[i];
	j = 0;
	while (j < len)
		new[i++] = curr->buffer[j++];
	new[i] = 0;
	if (new[i - 1] == '\n')
		curr->read_byte = -2;
	else
		curr->read_byte = BUFFER_SIZE;
	free(old);
	return (new);
}

char	*ft_strdup(char *buf, ssize_t len)
{
	char	*dst;
	ssize_t	i;

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
	return (dst);
}

t_link	*find_node_or_make_new(t_link *head, int fd)
{
	t_link	*new;
	t_link	*curr;

	curr = head;
	while (curr->next != NULL && curr->fd != fd)
		curr = curr->next;
	if (curr->fd == fd)
		return (curr);
	new = (t_link *)malloc(sizeof(t_link));
	if (!new)
		return (0);
	new->buffer[0] = 0;
	new->buf_idx = 0;
	new->read_byte = -1;
	new->fd = fd;
	new->next = NULL;
	curr->next = new;
	return (new);
}

ssize_t	find_newline_or_eof(char *buf, ssize_t read_num)
{
	ssize_t	i;

	if (read_num < BUFFER_SIZE)
		return (read_num - 1);
	i = 0;
	while (i < read_num)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (NO_NEWLINE);
}

char	*free_current_node(t_link *curr, char *buf)
{
	t_link	*tmp;

	free(buf);
	buf = NULL;
	tmp = curr->next;
	free(curr);

	return (0);
}

// void	free_all_node(t_link **head, t_link **curr, char *buf)
// {
// 	t_link	*curr;
// 	t_link	*tmp;

// 	free(head);
// 	head = 0;
// 	free(curr);
// 	curr = 0;
// 	free(buf);
// 	buf = 0;
// }

	temp = *head;
	while (temp->next != curr)
	{
		temp = temp->next;
		
	}
	temp->next = curr->next;
	
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
