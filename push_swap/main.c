/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:29:11 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/03/28 17:47:42 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_info	info;

	if (argc <= 1)
		return (0);
	set_stack(&stack, &info, &argv[1]);
	sort_stack(&stack, &info);
	return (0);
}
