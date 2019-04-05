/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotz3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:29:06 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 19:20:40 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	iter_count_2(float z_r, float z_i, t_info *info)
{
	float	tmp;
	float	x;
	float	y;
	int		k;

	k = 0;
	x = 0;
	y = 0;
	while (k < info->max_iter)
	{
		tmp = powf(x * x + y * y, info->p / 2) *
		cos(info->p * atan2(y, x)) + z_r;
		y = powf(x * x + y * y, info->p / 2) *
		sin(info->p * atan2(y, x)) + z_i;
		x = tmp;
		if (x * x + y * y > 4)
			break ;
		k++;
	}
	return (k);
}

void		*mandelbrot2(void *thrds)
{
	t_info	info;
	t_thrd	thrd;
	float	x;
	float	y;

	thrd = *(t_thrd*)thrds;
	info = *(thrd.info);
	x = (info.iw * thrd.id) / info.nb_thrd - 1;
	while (x < (info.iw * (thrd.id + 1) / info.nb_thrd))
	{
		y = 0;
		while (y < info.ih)
		{
			info.c_r = ((x / info.iw) * ((info.x2 - info.x1))
			- (info.x2 - info.x1) / 2) + info.decx;
			info.c_i = ((y / info.ih) * ((info.y2 - info.y1))
			- (info.y2 - info.y1) / 2) + info.decy;
			info.iter = iter_count_2(info.c_r, info.c_i, &info);
			if (info.iter != info.max_iter)
				color_selection(&info, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
