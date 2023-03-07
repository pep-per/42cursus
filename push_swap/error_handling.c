/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:04:49 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/07 22:16:56 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

// void	free_data(int *data)
// {
// 	int	i;

// 	i = 0;
// 	while (data[i])
// 	{
// 		free(data[i]);
// 		i++;
// 	}
// 	free(data);
// }

void	invalid_data_error(char **strs, int *data)
{
	free_strs(strs);
	free(data);
	display_error();
}

void	duplicate_data_error(int *data)
{
	int	i;

	i = 0;
	free(data);
	display_error();
}
