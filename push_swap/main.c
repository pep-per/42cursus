/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:29:11 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/18 20:48:57 by jiyeolee         ###   ########.fr       */
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
	if (a.len <= 3)
	{
		sort_three(&a);
		return (0);
	}
	initialize_b(&b, a.size, a.data);
	if (a.len <= 5)
		sort_five(&a, &b);
	else
		sort_big(&a, &b);
	free(b.data);
	free(a.data);
	return (0);
}
