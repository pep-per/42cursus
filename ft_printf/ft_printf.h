/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:26:31 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/01 19:54:48 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./Libft/libft.h"

typedef struct s_tags
{
	int	type;
	int	width;
	int	dot;
	int	precision;
	int	minus;
	int	zero;
	int	hash;
	int	space;
	//int	star;
}			t_tags;

#endif
