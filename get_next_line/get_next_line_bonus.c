/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/09 13:45:40 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static ssize_t	find_newline(t_link *curr, ssize_t *newline_idx)
{
	*newline_idx = curr->idx;
	while (*newline_idx < curr->read_byte)
	{
		if (curr->buffer[*newline_idx] == '\n')
		{
			curr->is_newline = 1;
			return (*newline_idx + 1);
		}
		(*newline_idx)++;
	}
	return (curr->read_byte);
}

static char	*ft_strjoin(t_link *curr, char *old)
{
	char	*new;
	ssize_t	i;
	ssize_t	j;
	ssize_t	newline_idx;
	ssize_t	newline_len;

	newline_len = find_newline(curr, &newline_idx);
	new = (char *)malloc(newline_len + ft_strlen(old) + 1);
	if (!new)
	{
		free_line(old);
		return (0);
	}
	i = -1;
	while (old[++i])
		new[i] = old[i];
	j = curr->idx;
	while (j < newline_len)
		new[i++] = curr->buffer[j++];
	new[i] = 0;
	curr->idx = newline_idx + 1;
	free_line(old);
	return (new);
}

static char	*read_n_join(t_link *curr, char *line)
{
	if (curr->idx == -1 || curr->idx == curr->read_byte + 1)
	{
		curr->idx = 0;
		curr->read_byte = read(curr->fd, curr->buffer, BUFFER_SIZE);
		if (curr->read_byte < 0)
		{
			free_line(line);
			return (0);
		}
	}
	line = ft_strjoin(curr, line);
	if (!line)
		return (0);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_link	head = {{0, }, -1, -1, -1, 0, 0};
	t_link			*curr;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	curr = find_node_or_make_new(&head, fd);
	if (!curr)
		return (0);
	line = malloc(1);
	if (!line)
		return (free_current_node(&head, curr));
	line[0] = 0;
	while (curr->read_byte != 0 && !curr->is_newline)
	{
		line = read_n_join(curr, line);
		if (!line)
			return (free_current_node(&head, curr));
	}
	if (line[0] == '\0')
	{
		free_line(line);
		return (free_current_node(&head, curr));
	}
	curr->is_newline = 0;
	return (line);
}
