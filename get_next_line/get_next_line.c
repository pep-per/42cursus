/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/24 18:21:28 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	define_tail(ssize_t newline_idx, ssize_t *read_num, char *buf)
// {
// 	*read_num = newline_idx + 1;
// }

static int	check_buffer_find_newline(char *buf, ssize_t read_num)
{
	ssize_t	i;

	i = 0;
	while (i < read_num)
	{
		if (buf[i] == '\n' || buf[i] == '\0')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static ssize_t	save_line(int fd, t_backup *backup)
{
	ssize_t	read_num;
	ssize_t	newline_idx;
	char	buf[BUFFER_SIZE + 1];
	char	*save;

	read_num = read(fd, buf, BUFFER_SIZE);
	if (read_num == -1)
		return (-1);
	if (read_num == 0)
	{
		return (0);
	}
	newline_idx = check_buffer_find_newline(buf, read_num);
	if (newline_idx != -1) //개행 만나면 그만 읽고 리턴 시키기 
	{
		//read_num = newline_idx + 1;
		buf[newline_idx + 1] = 0;
		if (!backup->start)
		{
			save = ft_strdup(buf);
			if (!save)
				return (-1);
			backup->start = save;
			return (0);
		}
		save = ft_strjoin(backup, buf, (size_t)newline_idx + 1);
		if (!save)
			return (-1);
		if (backup->start)
			free(backup->start);
		backup->start = save;
		return (0);
	}
	else
		buf[read_num] = 0;

	save = ft_strjoin(backup, buf, (size_t)read_num);
	if (!save)
		return (-1);
	if (backup->start)
		free(backup->start);
	backup->start = save;
	// if (read_num < BUFFER_SIZE)
	// 	return (0);
	// eof까지 읽으면 0
	return (read_num);
}

char	*get_next_line(int fd)
{
	static t_backup	backup;
	int				result;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	// backup.start = 0; 
	// backup.length = 0;
	while (1)
	{
		result = save_line(fd, &backup);
		if (result == -1)
		{
			return (0);

		}
		if (result == 0)
			break ;
	}
	return (backup.start);
}

// int	main(void)
// {

// }