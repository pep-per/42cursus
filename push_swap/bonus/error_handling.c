/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:04:49 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/21 21:45:56 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error_exit(void)
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

void	invalid_data_error(char **strs, int *data)
{
	free_strs(strs);
	free(data);
	error_exit();
}

void	free_error(int *data)
{
	free(data);
	error_exit();
}
