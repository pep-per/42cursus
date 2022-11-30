/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:26:31 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/11/30 14:55:31 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

//# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_tags
{
	int	type;
	int	width;
	int	precision;
	int	zero;
	int	minus;
	int	plus;
	int	hash;
	int	space;
	//int	star;
}			t_tags;

#endif
