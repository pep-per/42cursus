/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:39 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/09 13:45:40 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	*new->buffer = 0;
	new->idx = -1;
	new->read_byte = -1;
	new->fd = fd;
	new->is_newline = 0;
	new->next = 0;
	curr->next = new;
	return (new);
}

char	*free_current_node(t_link *head, t_link *curr)
{
	t_link	*tmp;

	tmp = head;
	while (tmp->next != curr)
		tmp = tmp->next;
	tmp->next = curr->next;
	free(curr);
	return (0);
}

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_line(char *line)
{
	free(line);
	line = 0;
}
