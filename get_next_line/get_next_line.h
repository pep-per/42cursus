/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 07:57:45 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/24 17:51:50 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000;
# endif

typedef struct s_backup
{
	char	*start;
	//char	*end;
	size_t	length;
	
	//t_read	*next;
}	t_backup;

char	*get_next_line(int fd);
char	*ft_strjoin(t_backup *backup, char *buf, size_t read_num);
char	*ft_strdup(const char *s1);





#endif
