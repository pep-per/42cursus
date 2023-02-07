/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:45 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/07 22:07:01 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define NO_NEWLINE -1

typedef struct s_link
{
	char			buffer[BUFFER_SIZE];
	ssize_t			buf_idx;
	ssize_t			read_byte;
	int				fd;
	struct s_link	*next;
}	t_link;

char	*get_next_line(int fd);
// char	*ft_strjoin(t_link *curr, char *buf, size_t read_num);
char	*ft_strjoin(char *line, char *buf, ssize_t read_num);
char	*ft_strdup(char *buf, ssize_t len);
t_link	*find_node_or_make_new(t_link **head, int fd);
void	ft_bzero(void *s, size_t n);
ssize_t	find_newline_or_eof(char *buf, ssize_t read_num);
#endif
