/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/02 23:24:27 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



#include <stdio.h>


static int	find_newline(char *buf, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i < len)
	{
		if (buf[i] == '\n' && buf[i] != '\0')
			return (i);
		i++;
	}
	return (-1);
}

static void	save_line(char *buf, t_link *curr)
{
	size_t	i;

	// if (curr->backup) 
	// 	free(curr->backup);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	curr->backup = &buf[i + 1];
}

// static char	*split_line(t_link *curr, ssize_t read_num)
// {
	
// }

static char	*load_line(t_link *curr, char *buf, ssize_t read_num)
{
	ssize_t	newline_idx;
	ssize_t	len;
	char	*line;
	// char	*buf;

	if (read_num == 0)
	{
		len = curr->backup_len;
		newline_idx = find_newline(curr->backup, len);
		if (len > newline_idx + 1)
			len = newline_idx + 1;
		line = ft_strdup(curr->backup, len);
		if (!line)
			return (0);
		save_line(curr->backup, curr);
		curr->backup_len -= (newline_idx + 1);
		return (line);
	}
	buf[read_num] = 0;
	newline_idx = find_newline(buf, read_num);
	len = read_num;
	if (newline_idx != -1 || read_num < BUFFER_SIZE)
	{
		if (len > newline_idx + 1)
			len = newline_idx + 1;
		//buf[newline_idx + 1] = 0;
		if (curr->backup == NULL)
			line = ft_strdup(buf, len);
		else
			line = ft_strjoin(curr, buf, len);
		if (!line)
		{
			// free(buf);
			return (0);
		}
		curr->backup_len = 0;//////
		save_line(buf, curr);
		// free(buf);
		return (line);
	}
	if (!curr->backup)
		line = ft_strdup(buf, len);
	else
		line = ft_strjoin(curr, buf, len);
	if (!line)
	{
		// free(buf);
		return (0);
	}
	curr->backup_len += len;
	// free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_link	*head;
	t_link			*curr;
	t_link			*new;
	char			*result;
	char			*buf;
	ssize_t	read_num;


	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (!head)
	{
		head = (t_link *)malloc(sizeof(t_link));
		if (!head)
			return (0);
		head->next = NULL;
		head->backup = NULL;
		head->fd = -1;
		head->backup_len = -1;
	}	
	curr = head;
	while (curr->next != NULL && curr->fd != fd)
		curr = curr->next;
	if (curr->fd != fd)
	{
		new = (t_link *)malloc(sizeof(t_link));
		if (!new)
			return (0);
		new->fd = fd;
		new->next = NULL;
		new->backup_len = -1;
		curr->next = new;
		curr = new;
	}
	// start = curr->backup;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	ft_bzero(buf, BUFFER_SIZE + 1);
	while (curr->backup_len != 0)
	{
		read_num = read(fd, buf, BUFFER_SIZE);
		if (read_num < 0)
		{
			free(buf);
			free_current_node(head, fd);
			return (0);
		}
		result = load_line(curr, buf, read_num);
		if (result == NULL)
		{
			free(buf);
			free_current_node(head, fd);
			return (0);
		}
		if (read_num == 0)
			break ;
	}
	buf = 0;
	free(buf);
	return (result);
}

// int	main(void)
// {

// }