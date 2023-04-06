/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:29:11 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/07 02:02:10 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (0);
	set_stack(&a, &argv[1]);
	if (a.size <= 3)
	{
		sort_small(&a);
	}
	else
	{
		initialize_b(&b, a.size, a.data);
		sort_complex(&a, &b);
		free(b.data);
	}
	free(a.data);
	return (0);
}
