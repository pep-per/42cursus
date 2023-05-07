/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeolee <jiyeolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:16:55 by jiyeolee          #+#    #+#             */
/*   Updated: 2023/05/08 06:55:34 by jiyeolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_event(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	mouse_event(int button, int x, int y, t_data *data)
{
	if (button == SCROLL_UP)
	{
		data->scale *= 1.05;
		data->mid_x += ((double)x - data->mid_x) / 20;
		data->mid_y += ((double)y - data->mid_y) / 20;
	}
	else if (button == SCROLL_DOWN)
	{
		data->scale *= 0.95;
		data->mid_x -= ((double)x - data->mid_x) / 20;
		data->mid_y -= ((double)y - data->mid_y) / 20;
	}
	return (0);
}

int	window_event(void)
{
	exit(0);
}

void	set_hook(t_data *data)
{
	mlx_key_hook(data->win, key_event, data); //esc key press event
	mlx_mouse_hook(data->win, mouse_event, data);
	mlx_hook(data->win, DESTROY, 0, window_event, data); //close button press event
}
