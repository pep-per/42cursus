/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:20:02 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/05/02 23:07:19 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_key_hook(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	set_mouse_hook(t_data *data)
{

}

int	julia(int x, int y, t_data *data)
{
	int	i;
	
	// 좌표에 맞는 색상 리턴
	// 수렴하면 0
	// 발산하면 색칠, 깊이에 따라 변화.
}

int	set_color(int x, int y)
{

}

int	mandelbrot(int x, int y, t_data *data)
{
	int		color;
	int		depth;
	double	a;
	double	b;

	a = data->rnum;
	b = data->inum;
	depth = 0;
	while (depth < 10)
	{
		x = x * x - y * y + a;
		y = 2 * x * y + b;
		if (x * x + y * y > 2 * 2)
			break ;
		depth++;
	}
	color = set_color(x, y);
	return (color);
}

void	make_fractol(t_data *data)
{
	int		x;
	int		y;
	int		color;
	int		offset;
	char	*dst;

	dst = data->addr;
	x = 0;
	y = 0;
	while (x < SIZE_X)
	{
		while (y < SIZE_Y)
		{
			if (data->type == JULIA)
				color = julia(x, y, data);
			else if (data->type == MANDELBROT)
				color = mandelbrot(x, y, data);
			offset = y * data->line_length + x * (data->bits_per_pixel / 8);
			dst += offset;
			*dst = color;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	check_argument(char *str, double *num, long long div)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		div = -10;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] != '0')
		return (0);
	if (str[++i] == '.')
	{
		if (!ft_isdigit(str[++i]))
			return (0);
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			*num += (double)((str[i] - '0') / div);
			div /= 10;
			i++;
		}
	}
	else if (str[i] != '\0')
		return (0);
	return (1);
}

void	error_option(void)
{
	write(1, "Please input right argument\n", 28);
	write(1, "1. Julia [real number] [imaginary number]\n", 42);
	write(1, "2. Mandelbrot\n", 14);
	exit(1);
}

void	init_data(int argc, char **argv, t_data *data)
{
	if (ft_strncmp(argv[1], "Julia", ft_strlen(argv[1])) == 0 && argc == 4)
	{
		data->rnum = 0.0;
		data->inum = 0.0;
		if (!check_argument(argv[2], &data->rnum, 10) \
			|| !check_argument(argv[3], &data->inum, 10))
			error_option();
		data->type = JULIA;
	}
	else if (ft_strncmp(argv[1], "Mandelbrot", ft_strlen(argv[1])) == 0)
		data->type = MANDELBROT;
	else
		error_option();
}

void	error(void)
{
	perror(strerror(errno));
	exit(1);
}

void	set_hook(t_data *data)
{
	mlx_key_hook(data->win, set_key_hook, &data); //esc key press event
	mlx_mouse_hook(data->win, set_mouse_hook, &data);
	mlx_hook(data->win, DESTROY, 0, exit(0), 0); //close button press event

}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(argc, argv, &data);
	data.mlx = mlx_init(); //그래픽 시스템에 연결. 연결 식별자.
	if (!data.mlx)
		error();
	data.win = mlx_new_window(data.mlx, SIZE_X, SIZE_Y, "fractol"); //창 식별자
	if (!data.win)
		error();
	data.img = mlx_new_image(data.mlx, SIZE_X, SIZE_Y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	make_fractol(&data);
	set_hook(&data);
	mlx_loop(data.mlx); //rendering
	return (0);
}
