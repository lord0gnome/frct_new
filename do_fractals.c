/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:36:28 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/06 19:03:08 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	randomize_colors(t_f_data *d)
{
	d->frct->color.r += 2;
	modify_image(d);
	return(1);
}

void	do_fractals(t_f_data *data)
{
	srand(time(NULL));
	modify_image(data);
	mlx_loop_hook (data->init, &randomize_colors, data);
	mlx_hook(data->window, MotionNotify, PointerMotionMask, &mouse_pos, data);
	mlx_hook(data->window, KeyPress, KeyPressMask, &key_press, data);
	mlx_loop(data->init);
}
