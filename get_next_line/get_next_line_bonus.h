/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:45 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/09 13:45:42 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define NO_NEWLINE -1

typedef struct s_link
{
	char			buffer[BUFFER_SIZE + 1];
	ssize_t			idx;
	ssize_t			read_byte;
	int				fd;
	int				is_newline;
	struct s_link	*next;
}	t_link;

char	*get_next_line(int fd);

t_link	*find_node_or_make_new(t_link *head, int fd);
char	*free_current_node(t_link *head, t_link *curr);
ssize_t	ft_strlen(char *str);
void	free_line(char *line);

#endif
