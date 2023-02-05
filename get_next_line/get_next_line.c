/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/05 09:57:36 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	find_newline(char *buf, ssize_t read_num)
{
	ssize_t	i;

	i = 0;
	while (i < read_num)
	{
		if (buf[i] == '\n' || buf[i] == '\0')
			break ;
		i++;
	}
	if (i == read_num)
		return (-1);
	return (i);
}

int	is_newline(ssize_t newline_idx)
{
	return (newline_idx != -1);
}

static ssize_t	load_backup_find_newline(t_link *curr, char *buf, ssize_t read_num)
{
	ssize_t	newline_idx;

	// if (read_num < BUFFER_SIZE)
	// 	return (read_num - 1);
	buf[read_num] = 0;
	newline_idx = -1;
	if (curr->backup_len == 0)
		newline_idx = find_newline(buf, read_num);
	else
		newline_idx = find_newline(curr->backup, curr->backup_len);
	return (newline_idx);
}

static char	*complete_line(t_link *curr, char *buf, ssize_t newline_idx, ssize_t read_num)
{
	char	*line;

	if (read_num == 0)
	{
		line = ft_strdup(curr->backup, newline_idx + 1);
		if (!line)
			return (0);
		curr->backup = &curr->backup[newline_idx + 1];
		// save_line(curr->backup, curr, newline_idx);
		curr->backup_len -= (newline_idx + 1);
		return (line);
	}
	if (curr->backup == NULL)
		line = ft_strdup(buf, newline_idx + 1);
	else
		line = ft_strjoin(curr->backup, buf, newline_idx + 1);
	if (!line)
		return (0);
	curr->backup = &buf[newline_idx + 1];
	// save_line(buf, curr, newline_idx);
	curr->backup_len = read_num - (newline_idx + 1);
	// if (curr->backup_len <= 0)
	// 	curr->backup = 0;
	return (line);
}

static char	*concatenate_lines(char *buf, ssize_t read_num, char *line)
{
	if (line == NULL)
		line = ft_strdup(buf, read_num);
	else
		line = ft_strjoin(line, buf, read_num);
	if (!line)
		return (0);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_link	*head;
	t_link			*curr;
	char			*line;
	char			*buf;
	ssize_t			read_num;
	ssize_t			newline_idx;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (head == NULL)
	{
		head = (t_link *)malloc(sizeof(t_link));
		if (!head)
			return (0);
		head->next = NULL;
		head->backup = NULL;
		head->fd = -1;
		head->backup_len = 0;
	}
	curr = find_node_or_make_new(&head, fd);
	if (!curr)
	{
		// free(&curr);
		// curr = 0;
		free(head);
		head = 0;
		// free_all(&head);
		return (0);
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free_current_node(&curr, buf);
		// free_current_node(&curr, buf);
		return (0);
	}
	ft_bzero(buf, BUFFER_SIZE + 1);
	newline_idx = -1;
	line = NULL;
	while (!is_newline(newline_idx))
	{
		read_num = read(fd, buf, BUFFER_SIZE);
		if (read_num < 0 || (read_num == 0 && curr->backup_len == 0))
		{
			free(head);
			head = 0;
			free(curr);
			curr = 0;
			if (buf != NULL)
			{
				free(buf);
				buf = 0;
			}
			
			// free_current_node(&head, buf);
			// free_current_node(&curr, buf);
			return (0);
		}
		newline_idx = load_backup_find_newline(curr, buf, read_num);
		if (is_newline(newline_idx) || read_num == 0)
			line = complete_line(curr, buf, newline_idx, read_num);
		else
			line = concatenate_lines(buf, read_num, line);
		if (line == NULL)
		{
			free_current_node(&curr, buf);
			return (0);
		}
		if (read_num == 0)
			break ;
	}
	// free(buf);
	// buf = 0;
	return (line);
}
