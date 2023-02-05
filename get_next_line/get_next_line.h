/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:45 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/05 09:08:33 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_link
{
	char			*backup;
	ssize_t			backup_len;
	int				fd;
	//t_node	*head;
	struct s_link	*next;
}	t_link;

char	*get_next_line(int fd);
// char	*ft_strjoin(t_link *curr, char *buf, size_t read_num);
char	*ft_strjoin(char *line, char *buf, ssize_t read_num);
char	*ft_strdup(char *buf, ssize_t len);
t_link	*find_node_or_make_new(t_link **head, int fd);
// void	free_all(t_link **head);
void	free_current_node(t_link **curr, char *buf);

void	ft_bzero(void *s, size_t n);

#endif
