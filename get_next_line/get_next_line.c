/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:42 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/07 23:16:05 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(t_link *curr, char *result, int fd)
{
	while (curr->read_byte > 0)
	{
		if (curr->read_byte == -1 || curr->buf_idx >= BUFFER_SIZE)
		{
			curr->read_byte = read(fd, curr->buffer, BUFFER_SIZE);
			if (curr->read_byte < 0)
			{
				free_current_node(curr);
				return (0);
			}
			curr->buf_idx = 0;
		}
		result = ft_strjoin(curr, result);
	}
	return (result);
}
// 길이 0의 result가 들어와서 나올때는 개행 혹은 EOF까지의 문자열을 반환해야한다.
// curr->buf_idx는 새롭게 읽어야할 위치
// curr->read_byte는 ???

char	*get_next_line(int fd)
{
	static t_link	head = {0, 0, -1, -1, 0};
	t_link			*curr;
	char			*new_buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	curr = find_node_or_make_new(&head, fd);
	if (!curr)
		return (0);
	new_buf = malloc(1);
	if (!new_buf)
		return (0);
	new_buf[0] = 0;
	new_buf = read_buffer(curr, new_buf, fd);
	if (new_buf[0] == 0)
	{
		free(new_buf);
		free_current_node();
		return (0);
	}
	return (new_buf);
}
