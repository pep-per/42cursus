/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:14:23 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 21:46:29 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include "../Libft/libft.h"

typedef struct s_tags
{
	int	type;
	int	width;
	int	precision;
	int	minus;
	int	plus;
	int	zero;
	int	hash;
	int	space;
}			t_tags;


#include <stdio.h>


int		ft_printf(const char *format, ...);

void	initialize(t_tags *tags, int (*ft_put[])(void *p, unsigned int len));
int		is_type(char c);
int		is_option(char c);

int		handle_str_precision(t_tags *tags, int len);
int		handle_digit_precision(t_tags *tags, int len, long long num);
int		fill_precision(t_tags *tags, int len);

int		fill_width(t_tags *tags, int total);
int		fill_width_str(t_tags *tags, int total, char *str);
int		fill_width_hexa(t_tags *tags, int total, unsigned int num);
int		fill_width_decimal(t_tags *tags, int total, long long num);

int		convert_to_char(va_list args, t_tags *tags);
int		convert_to_str(va_list args, t_tags *tags, \
						int (*ft_put)(void *p, unsigned int len));
int		convert_to_decimal(va_list args, t_tags *tags, \
							int (*ft_put)(void *p, unsigned int len));
int		convert_to_hexa(va_list args, t_tags *tags, \
						int (*ft_put)(void *p, unsigned int len));
int		convert_to_adress(va_list args, t_tags *tags, \
							int (*ft_put)(void *p, unsigned int len));

int		ft_put_address(void *p, unsigned int len);
int		ft_put_hexa_lower(void *p, unsigned int len);
int		ft_put_hexa_upper(void *p, unsigned int len);

int		handle_null_strlen(char *arg, char *str);
int		handle_null_ft_put(char *arg, char *str, int len, \
						int (*ft_put)(void *p, unsigned int len));
void	atoi_handle_overflow(int *num, char c, t_tags *tags);
int		handle_format_overflow(t_tags *tags, int type);

#endif
