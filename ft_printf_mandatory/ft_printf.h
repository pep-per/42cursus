/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:26:31 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/01/06 22:32:53 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./Libft/libft.h"

int	ft_printf(const char *format, ...);

int	ft_put_address(void *p, unsigned int len);
int	ft_put_hexa_lower(void *p, unsigned int len);
int	ft_put_hexa_upper(void *p, unsigned int len);
int	is_type(char c);

int	handle_null_strlen(char *arg, char *str);
int	handle_null_ft_put(char *arg, char *str, int len, \
						int (*ft_put)(void *p, unsigned int len));

#endif
