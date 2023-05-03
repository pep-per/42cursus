/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:55:38 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/05/03 22:57:55 by jiyeolee         ###   ########.fr       */
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

# define SIZE_X 1920
# define SIZE_Y 1080

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
}	t_data;

enum e_type
{
	JULIA,
	MANDELBROT
};

enum e_hook
{
	ESC = 53,
	DESTROY = 17
};

#endif