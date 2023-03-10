/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:49:06 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/10 15:12:33 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_data(char **s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			while (s[i][j] == c)
				j++;
			if (s[i][j])
				count++;
			while (s[i][j] != c && s[i][j])
				j++;
		}
		i++;
	}
	return (count);
}

int	is_sorted(int *data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (data[i] > data[i + 1])
			return (0);
	}
	return (1);
}

int	is_duplicate(int *data, int size)
{
	int	i;
	int	j;
	int	num;

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

int	*get_data(char **argv, int *data, int size)
{
	int		i;
	int		j;
	int		k;
	int		num;
	char	*strs;

	data = (int *)malloc(sizeof(int) * size);
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
	return (data);
}
