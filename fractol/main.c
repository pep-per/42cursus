/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:20:02 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/05/08 01:40:22 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	option_exit(void)
{
	write(1, "Please input right argument\n", 28);
	write(1, "1. julia [real number] [imaginary number]\n", 42);
	write(1, "2. mandelbrot\n", 14);
	exit(1);
}

void	error_exit(int ernum)
{
	perror(strerror(ernum));
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		option_exit();
	init_data(argc, argv, &data);
	set_hook(&data);
	make_fractol(&data);
	mlx_loop_hook(data.mlx, make_fractol, &data);
	mlx_loop(data.mlx); //rendering
	return (0);
}
