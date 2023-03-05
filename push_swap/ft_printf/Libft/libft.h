/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:45:17 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 22:32:53 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int				ft_isdigit(int c);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
int				hexa_to_str(size_t n, unsigned int len, char *hexa);
int				ft_itoa(void *p, unsigned int len);
int				ft_uitoa(void *p, unsigned int len);
unsigned int	num_length_hexa(size_t n);
unsigned int	num_length_i(long long num);
int				ft_putstr_free(void *p, unsigned int len);
int				ft_putstr(void *p, unsigned int len);

#endif