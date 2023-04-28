/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:20:02 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/28 21:53:53 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_id *id)
{
	if (key == 53)
	{
		mlx_destroy_window(id->mlx, id->win);
		exit(0);
	}
	return (0);
}

void	make_julia(t_id *id, t_img *img)
{

}

void	make_Mandelbrot(t_id *id)
{

}

int	ft_atod(char *str, double *result)
{
	double	num;
	int		i;
	int		dot;
	
	num = 0;
	i = 0;
	dot = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		num = (num * 10) + (str[i] - '0');
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	*result = num;
	return (1);
}

void	display_option()
{
	write(1, "available set : Julia, Mandelbrot\n", 34);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_id	id;
	t_img	img;
	
	if (argc < 2)
		display_option();
	id.mlx = mlx_init(); //연결 식별자
	if (!id.mlx)
		return (1);
	id.win = mlx_new_window(id.mlx, 500, 500, "fractol"); //창 식별자
	if (!id.win)
		return (1);
	if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0)
	{
		if (!ft_atod(argv[2], &img.real) || !ft_atod(argv[3], &img.imaginary))
			return (1);
		make_julia(&id, &img);
	}
	else if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) == 0)
		make_Mandelbrot(&id);
	else
		display_option();
	mlx_key_hook(id.win, key_hook, &id); //esc key press event
	mlx_hook(id.win, 17, 0, exit(0), 0); //close button press event
	mlx_loop(id.mlx);
	return (0);
}
