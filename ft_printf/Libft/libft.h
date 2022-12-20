/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:45:17 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/20 21:01:39 by jiyeolee         ###   ########.fr       */
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
int				ft_itoa(va_list args);

int				ft_putchar(char c);
int				ft_put_to_char(va_list args);
int				ft_putstr(va_list args);
int				ft_putstr_free(va_list args);
int				ft_uitoa(va_list args);
int				ft_put_address(va_list args);
int				ft_put_hexa_lower(va_list args);
int				ft_put_hexa_upper(va_list args);
unsigned int	num_length_hexa(size_t n);
unsigned int	num_length_ui(unsigned int n);
unsigned int	num_length_i(long long num);

#endif