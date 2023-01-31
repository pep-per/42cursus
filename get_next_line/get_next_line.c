/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/31 23:52:10 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



#include <stdio.h>


static int	check_buffer_find_newline(char *buf, ssize_t read_num)
{
	ssize_t	i;

	i = 0;
	while (i < read_num)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	save_line(char *line, t_link *curr)
{
	size_t	i;

	i = 0;
	if (curr->backup != NULL)
		free(curr->backup);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	curr->backup = &line[i + 1];
}

static char	*load_line(int fd, t_link *curr)
{
	ssize_t	read_num;
	ssize_t	newline_idx;
	ssize_t	len;
	char	*line;
	char	buf[BUFFER_SIZE + 1];

	read_num = read(fd, buf, BUFFER_SIZE);
	if (read_num < 1)
		return (0);
	buf[read_num] = 0;
	newline_idx = check_buffer_find_newline(buf, read_num);
	len = read_num;
	if (newline_idx != -1 || read_num < BUFFER_SIZE)
	{
		if (len > newline_idx + 1)
			len = newline_idx;
		//buf[newline_idx + 1] = 0;
		if (curr->backup == NULL)
			line = ft_strdup(curr, buf, read_num);
		else
			line = ft_strjoin(curr, buf, len);
		if (!line)
			return (0);
		save_line(line, curr);
		return (line);
	}
	if (!curr->backup)
		line = ft_strdup(curr, buf, len);
	else
		line = ft_strjoin(curr, buf, len);
	if (!line)
		return (0);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_link	*head;
	t_link			*curr;
	t_link			*tmp;
	char			*start;
	char			*result;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	head = (t_link *)malloc(sizeof(t_link));
	if (!head)
		return (0);
	head->next = NULL;
	curr = head;
	while (curr->next != NULL)
	{
		if (curr->fd == fd)
			break ;
		curr = curr->next;
	}
	tmp = curr;
	curr = curr->next;
	if (!curr)
	{
		curr = (t_link *)malloc(sizeof(t_link));
		if (!curr)
		{
			free_link(head);
			return (0);
		}
		curr->fd = fd;
		curr->next = NULL;
		curr->backup = NULL;
		curr->backup_len = 0;
		tmp->next = curr;
	}
	start = curr->backup;
	while (1)
	{
		result = load_line(fd, curr);
		if (result == NULL)
		{
			free_link(head);
			return (0);
		}
		if (curr->backup != start)
		{
			free_link(head);
			return (result);
		}
	}
}

// int	main(void)
// {

// }