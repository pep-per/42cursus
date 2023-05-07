/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:19:36 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/05/08 03:50:00 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
			*num += (double)(str[i] - '0') / div;
			div *= 10;
			i++;
		}
	}
	else if (str[i] != '\0')
		return (0);
	return (1);
}

void	init_data(int argc, char **argv, t_data *data)
{
	if (ft_strncmp(argv[1], "julia", ft_strlen(argv[1])) == 0 && argc == 4)
	{
		data->rnum = 0.0;
		data->inum = 0.0;
		if (!check_argument(argv[2], &data->rnum, 10) \
			|| !check_argument(argv[3], &data->inum, 10))
			option_exit();
		data->type = JULIA;
	}
	else if (ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])) == 0)
		data->type = MANDELBROT;
	else
		option_exit();
	data->mlx = mlx_init(); //그래픽 시스템에 연결. 연결 식별자.
	if (!data->mlx)
		error_exit(ENOMEM);
	data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "fractol"); //창 식별자
	if (!data->win)
		error_exit(ENOMEM);
	data->img = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	if (!data->img)
		error_exit(ENOMEM);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	data->mid_x = (double)SIZE_X / 2;
	data->mid_y = (double)SIZE_Y / 2;
	data->scale = 1.0;
}
