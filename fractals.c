/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:26:45 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/06 21:00:01 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color init_color(t_color c)
{
c.r = 9;
c.g = 27;
c.b = 49;
c.rup = 1;
c.gup = 0;
c.bup = 0;
return (c);
}

t_color	det_color(t_color c, int curri, int maxi)
{
	if (c.rup)
		c.r = curri;
	else
		c.r = curri;
	if (c.r >= 0xff)
		c.rup = 0;
	if (c.r <= 0)
		c.rup = 1;
	if (c.gup)
		c.g = curri;
	else
		c.g = curri;
	if (c.g == 0xff)
		c.gup = 0;
	if (c.g == 0)
		c.gup = 1;
	if (c.bup)
		c.b= curri;
	else
		c.b= curri;
	if (c.b == 0xff)
		c.bup = 0;
	if (c.b == 0)
		c.bup = 1;
	if (curri == maxi)
	{
		c.r = c.r/1.5;
		c.g = c.g/1.5;
		c.b = c.b/1.5;
	}
	return (c);
}

t_f		init_mandelbrot(t_f f, t_f_data *d)
{
			f.c_r = (f.x - (d->ww/2)) / f.zoomx + f.xoff;
			f.c_i = (f.y - (d->wh/2)) / f.zoomy + f.yoff;
			f.z_r = 0;
			f.z_i = 0;
			f.i = 0;
	return (f);
}
t_f		init_julia(t_f f, t_f_data *d)
{
			f.c_r = (f.x - (d->ww/2)) / (f.zoomx) + f.xoff;
			f.c_i = (f.y - (d->wh/2)) / (f.zoomy) + f.yoff;
			f.z_r = 0;
			f.z_i = 0;
			f.i = 0;
	return (f);
}

void	*julia(void	*data)
{
	t_tids		*t;
	t_f			*ff;
	t_f			f;
	t_f_data	*d;

	t = (t_tids *)data;
	d = (t_f_data *)t->data;
	ff = (t_f *)d->frct;
	f = (*ff);
	f.x = 0;
	f.color = init_color(f.color);
	f.len = (t->index) * (d->wh / d->threads);
	while (f.x < d->ww)
	{
		f.y = (t->index - 1) * (d->wh / d->threads);
		while (f.y < f.len)
		{
			f = init_julia(f, d);
			while (f.i < f.iter && f.z_r * f.z_r + f.z_i * f.z_i > 4)
			{
				f.tmp = f.z_r;
				f.tmp2 = f.z_i;
				f.z_r = f.tmp * f.tmp - f.tmp2 + f.c_r;
				f.z_i = 2 * f.tmp * f.tmp2 + f.c_i;
				f.i++;
			}
				f.color = det_color(f.color, f.i, f.iter);
			if (f.y > 0 && f.x > 0 && f.y < d->wh && f.x < d->ww)
				ft_putpixel_frct(f.x, f.y, f.color, d);
			f.y++;
		}
		f.x++;
	}
	return (NULL);
}
void	*mandelbrot(void	*data)
{
	t_tids		*t;
	t_f			*ff;
	t_f			f;
	t_f_data	*d;

	t = (t_tids *)data;
	d = (t_f_data *)t->data;
	ff = (t_f *)d->frct;
	f = (*ff);
	f.x = 0;
	f.color = init_color(f.color);
	f.len = (t->index) * (d->wh / d->threads);
	while (f.x < d->ww)
	{
		f.y = (t->index - 1) * (d->wh / d->threads);
		while (f.y < f.len)
		{
			f = init_mandelbrot(f, d);
			while (f.z_r * f.z_r + f.z_i * f.z_i < 4 && f.i < f.iter)
			{
				f.tmp = f.z_r;
				f.z_r = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
				f.z_i = 2 * f.tmp * f.z_i + f.c_i;
				f.i++;
			}
				f.color = det_color(f.color, f.i, f.iter);
			if (f.y > 0 && f.x > 0 && f.y < d->wh && f.x < d->ww)
				ft_putpixel_frct(f.x, f.y, f.color, d);
			f.y++;
		}
		f.x++;
	}
	return (NULL);
}
void	*det_frct(void *data)
{
t_tids *t;
t_f_data *d;

t = (t_tids *)data;
d = t->data;

if (!ft_strcmp("mandelbrot",d->name))
	mandelbrot(data);
else if (!ft_strcmp("julia", d->name))
	julia(data);
	pthread_exit(0);	
}


void	modify_image(t_f_data *d)
{
	int		index;

	index = 0;
	if (d->threads)
	{
		while (index < d->threads)
		{
			d->tids[index].index = index + 1;
			d->tids[index].data = (t_f_data *)d;
			pthread_create(&d->tids[index].thread, NULL, det_frct, (void *)&d->tids[index]);
			index++;
		}
		index = 0;
		while (index < d->threads)
			pthread_join((d->tids[index++].thread), NULL);
	}
	mlx_put_image_to_window(d->init, d->window, d->image, 0 , 0);
}

