/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:55:38 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/04/28 21:41:41 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./Libft/libft.h"

typedef struct s_id
{
	void	*win;
	void	*mlx;
}	t_id;

typedef struct s_img
{
	double	real;
	double	imaginary;
}	t_img;

enum e_cmd
{
	JULIA,
	MANDELBROT
};

#endif