/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:15:23 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/09/18 18:58:19 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 좌표에 맞는 색상 리턴
// 수렴하면 0
// 발산하면 depth에 따라 다른 색
int	set_color(int n)
{
	int	r;
	int	g;
	int	b;

	r = 209 * n / ITERATION_MAX;
	g = (255 - 100) * n / ITERATION_MAX;
	b = (255 - 150) * n / ITERATION_MAX;
	if (n > 0)
	{
		g += 100;
		b += 155;
	}
	return (r << 16 | g << 8 | b);
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
	while (n < ITERATION_MAX && x * x + y * y <= 2 * 2)
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

	x = 0.0;
	y = 0.0;
	n = 0;
	while (n < ITERATION_MAX && x * x + y * y <= 2 * 2)
	{
		tmp_x = x;
		x = x * x - y * y + a;
		y = 2 * tmp_x * y + b;
		n++;
	}
	return (set_color(n));
	// return (set_color(n));
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// 윈도우 좌측 위의 꼭짓점을 중앙으로 바꾸고 SIZE_X : SIZE_Y = 4 : 4 비율 맞추기
// 윈도우의 좌표를 실제 좌표계 4X4의 좌표로 바꾸고 프렉탈 계산
int	make_fractol(t_data *data)
{
	double		x;
	double		y;
	int			color;

	x = 0.0;
	y = 0.0;
	while (x < SIZE_X)
	{
		y = 0.0;
		while (y < SIZE_Y)
		{
			if (data->type == JULIA)
				color = julia((x - data->mid_x) / SIZE_X * 4 * data->scale, \
							(data->mid_y - y) / SIZE_Y * 4 * data->scale, data);
			else if (data->type == MANDELBROT)
				color = mandelbrot((x - data->mid_x) / SIZE_X * 4 * data->scale, \
								(data->mid_y - y) / SIZE_Y * 4 * data->scale);
			put_pixel(data, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
