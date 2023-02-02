/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:45 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/02/02 20:58:13 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_link
{
	char			*backup;
	size_t			backup_len;
	int				fd;
	//t_node	*head;
	struct s_link	*next;
}	t_link;

char	*get_next_line(int fd);
char	*ft_strjoin(t_link *curr, char *buf, size_t read_num);
char	*ft_strdup(char *buf, size_t len);

void	free_current_node(t_link *head, int fd);
void	ft_bzero(void *s, size_t n);

#endif
