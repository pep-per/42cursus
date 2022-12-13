/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tag_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:41:29 by jiyeolee          #+#    #+#             */
/*   Updated: 2022/12/10 18:23:55 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_num(char c)
{
	int	num;

	num = (int)c;
	return (num >= '0' && num <= '9');
}

int	is_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
			|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int	is_option(char c)
{
	return (c == '-' || c == '+' || c == '0' \
			|| c == '#' || c == ' ' || c == '.');
}
