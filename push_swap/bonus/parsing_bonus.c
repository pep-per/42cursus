/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:49:06 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/23 20:47:42 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	plus_count(char *s, char c, int *count)
{
	int	j;
	int	is_blank;

	j = 0;
	is_blank = 1;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j])
		{
			(*count)++;
			is_blank = 0;
		}
		while (s[j] != c && s[j])
			j++;
	}
	if (is_blank)
		error_exit();
}

int	count_data(char **s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!s[i][0])
			error_exit();
		plus_count(s[i], c, &count);
		i++;
	}
	return (count);
}

int	is_sorted(int *data, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (data[i] > data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(int *data, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (data[i] == data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	get_data(char **argv, int *data, int size)
{
	int		i;
	int		j;
	int		k;
	int		num;
	char	**strs;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		strs = ft_split(argv[j++], ' ');
		k = 0;
		while (strs[k])
		{
			if (!ft_atoi_valid(strs[k++], &num))
				invalid_data_error(strs, data);
			data[i++] = num;
		}
		free_strs(strs);
	}
}
