/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/30 19:34:34 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (curr->backup)
		free(curr->backup);
	curr->backup = line;
	//free(save);
}

static char	*load_line(int fd, t_link *curr)
{
	ssize_t	read_num;
	ssize_t	newline_idx;
	ssize_t	len;
	char	*line;
	char	buf[BUFFER_SIZE + 1];

	read_num = read(fd, buf, BUFFER_SIZE);
	if (read_num < 0)
		return (0);
	buf[read_num] = 0;
	newline_idx = check_buffer_find_newline(buf, read_num);
	len = read_num;
	if (newline_idx != -1 || read_num < BUFFER_SIZE)
	{
		if (len > newline_idx + 1)
			len = newline_idx + 1;
		//buf[newline_idx + 1] = 0;
		if (!curr->backup)
			line = ft_strdup(curr, buf, len);
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
	char			*start;
	char			*result;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	head = (t_link *)malloc(sizeof(t_link));
	if (!head)
		return (0);
	curr = head->next;
	while (curr)
	{
		if (curr->fd == fd)
			break ;
		curr = curr->next;
	}
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
	}
	start = curr->backup;
	while (1)
	{
		result = load_line(fd, curr);
		if (result == NULL)
		{
			free_link(head);
			//free(head);
			return (0);
		}
		// 뉴라인 나오면 백업 업데이트. 이때까지 붙인거 리턴
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