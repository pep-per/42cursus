/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:55:38 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/05/08 07:03:37 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./Libft/libft.h"

# define SIZE_X 1000
# define SIZE_Y 1000
# define ITERATION_MAX 200

typedef struct s_data
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		type;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	rnum;
	double	inum;
	double	mid_x;
	double	mid_y;
	double	scale;
}	t_data;

enum e_type
{
	JULIA,
	MANDELBROT
};

enum e_xevent
{
	ESC = 53,
	DESTROY = 17,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5
};

int		check_argument(char *str, double *num, long long div);
void	init_data(int argc, char **argv, t_data *data);

int		set_color(int n);
int		julia(double x, double y, t_data *data);
int		mandelbrot(double a, double b);
void	put_pixel(t_data *data, int x, int y, int color);
int		make_fractol(t_data *data);

int		key_event(int key, t_data *data);
int		mouse_event(int button, int x, int y, t_data *data);

int		window_event(void);
void	set_hook(t_data *data);

void	option_exit(void);
void	error_exit(int ernum);
int		main(int argc, char **argv);

#endif