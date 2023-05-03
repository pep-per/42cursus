/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:20:02 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/05/03 23:10:48 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

// int	mouse_hook(int button, int x, int y, t_data *data)
// {
// 	if (button == 0)
// 		;
// }

// 좌표에 맞는 색상 리턴
// 수렴하면 0
// 발산하면 depth에 따라 다른 색
int	set_color(int n)
{
	int	color;

	color = 0;
	if (n > 80)
		color += 100 << 8;
	if (n > 60)
		color += 100 << 16;
	if (n > 40)
		color += 100;
	return (color);
}

// 프렉탈은 z에 대한 점화식 z(n+1) = z(n)^2 + c를 수렴시킨다.
// x^2 + y^2 > 2^2면 발산한다.
// z = x + yi
// x, y는 실수
// c = a + bi;
// a, b는 실수
// c를 고정하고 점화식을 수렴시키는 x, y의 집합
// z를 그림
int	julia(double x, double y, t_data *data)
{
	double	tmp_x;
	int		n;

	n = 0;
	while (n < 100 && x * x + y * y <= 2 * 2)
	{
		tmp_x = x;
		x = x * x - y * y + data->rnum;
		y = 2 * tmp_x * y + data->inum;
		n++;
	}
	return (set_color(n));
}

// 정해진 x, y에 대해 점화식을 수렴시키는 c의 집합
// 복소수 c = a + bi;
// c를 그림
int	mandelbrot(double a, double b)
{
	double	x;
	double	y;
	double	tmp_x;
	int		n;

	x = 0;
	y = 0;
	n = 0;
	while (n < 100 && x * x + y * y <= 2 * 2)
	{
		tmp_x = x;
		x = x * x - y * y + a;
		y = 2 * tmp_x * y + b;
		n++;
	}
	return (set_color(n));
}

void	make_fractol(t_data *data)
{
	int		x;
	int		y;
	int		color;
	int		offset;
	char	*dst;

	x = 0;
	y = 0;
	while (x < SIZE_X)
	{
		while (y < SIZE_Y)
		{
			if (data->type == JULIA)
				color = julia((double)x, (double)y, data);
			else if (data->type == MANDELBROT)
				color = mandelbrot((double)x, (double)y);
			offset = y * data->line_length + x * (data->bits_per_pixel / 8);
			dst = data->addr + offset;
			*(unsigned int *)dst = color;
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

int	set_exit(void)
{
	exit(0);
}

void	set_hook(t_data *data)
{
	mlx_key_hook(data->win, key_hook, &data); //esc key press event
	// mlx_mouse_hook(data->win, mouse_hook, &data);
	mlx_hook(data->win, DESTROY, 0, set_exit, 0); //close button press event

}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		error_option();
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
