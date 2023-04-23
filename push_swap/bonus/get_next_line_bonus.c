/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/23 21:13:04 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static ssize_t	find_newline(char *line, ssize_t read_byte)
{
	ssize_t	i;

	i = 0;
	while (i < read_byte)
	{
		if (line[i] == '\n')
			return (i + 1);
		i++;
	}
	return (read_byte);
}

static char	*make_line(char *line, ssize_t read_byte)
{
	char	*new;
	ssize_t	i;
	ssize_t	newline_len;

	newline_len = find_newline(line, read_byte);
	new = (char *)malloc(newline_len + 1);
	if (!new)
	{
		free(line);
		return (0);
	}
	i = 0;
	while (i < newline_len)
	{
		new[i] = line[i];
		i++;
	}
	new[i] = 0;
	free(line);
	return (new);
}

static char	*read_line(char *line)
{
	ssize_t	read_byte;

	read_byte = read(0, line, 5);
	if (read_byte < 0)
	{
		free(line);
		return (0);
	}
	line = make_line(line, read_byte);
	if (!line)
		return (0);
	return (line);
}

char	*get_next_line(int *error)
{
	char	*line;

	line = malloc(5);
	if (!line)
	{
		*error = 1;
		return (0);
	}
	line[0] = 0;
	line = read_line(line);
	if (!line)
	{
		*error = 1;
		return (0);
	}
	if (line[0] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}
