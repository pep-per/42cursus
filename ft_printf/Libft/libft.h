/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:45:17 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/24 09:46:37 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_isdigit(int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
int				hexa_to_str(size_t n, unsigned int len, char *hexa, \
				int is_address);
int				ft_itoa(void *p, unsigned int len);
int				ft_uitoa(void *p, unsigned int len);
unsigned int	num_length_hexa(size_t n);
unsigned int	num_length_i(long long num);
int				ft_putstr_free(void *p, unsigned int len);

#endif