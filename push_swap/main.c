/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:29:11 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/12 20:03:09 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_info	info;
	char	*output;

	if (argc <= 1)
		return (0);
	set_stack(&stack, &info, &argv[1]);
	output = (char *)malloc(sizeof(char *) * info.size);
	if (!output)
		free_error(stack.data);
	sort_stack(&stack, &info, output);
	print_operations(output);
	return (0);
}
