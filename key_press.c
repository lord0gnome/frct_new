/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:47:45 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/06 19:47:09 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>
#include <time.h>
#include <stdio.h>
int	key_press(int keycode, t_f_data *data)
{
	srand(time(NULL));

	if (keycode == 53)
	{
		mlx_destroy_image(data->init, data->image);
		mlx_destroy_window(data->init, data->window);
		data->errno = -1;
		print_options(data);
	}
	if (keycode == 27)
		data->frct->iter--;
	if (keycode == 24)
		data->frct->iter++;
	if (keycode == 69) //plus
	{
	//	printf("megadata\nd->f->xoff = %lf\n d->f->yoff = %lf\n d->f->zoomx = %lf\n d->f->zoomy = %lf\n", data->frct->xoff, data->frct->yoff, data->frct->zoomx, data->frct->zoomy);
		data->frct->xoff += (data->mx - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff += (data->my - (data->wh / 2)) / data->frct->zoomy;
		data->frct->zoomy *= 1.25;
		data->frct->zoomx *= 1.25;
		data->frct->xoff -= (data->mx - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff -= (data->my - (data->wh / 2)) / data->frct->zoomy;
		data->zoomlevel++;
	}
	if (keycode == 78) //minus
	{
		data->frct->xoff += (data->mx - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff += (data->my - (data->wh / 2)) / data->frct->zoomy;
		data->frct->zoomy *= 0.75;
		data->frct->zoomx *= 0.75;
		if (data->zoomlevel != 0)
			data->zoomlevel--;
		data->frct->xoff -= (data->mx - (data->ww / 2)) / data->frct->zoomx;
		data->frct->yoff -= (data->my - (data->wh / 2)) / data->frct->zoomy;
	}
	if (keycode == 126)
		data->frct->yoff-= 14 / (data->frct->zoomy);
	if (keycode == 125)
		data->frct->yoff+= 14 / (data->frct->zoomy);
	if (keycode == 124)
		data->frct->xoff+= 14 / (data->frct->zoomx);
	if (keycode == 123)
		data->frct->xoff-= 14 / (data->frct->zoomx);
	modify_image(data);
	mlx_string_put(data->init, data->window, 0, 0, 0xffffff, ft_itoa(data->frct->iter));
	return (1);
}

int	mouse_pos(int x, int y, t_f_data *d)
{
	//ft_printf("x = %d, y = %d\n", x, y);
	d->mx = x;
	d->my = y;
	return(1);
}
