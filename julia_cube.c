/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:39:51 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 19:30:06 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		op_count_ju(t_info *info, float x, float y)
{
	int		k;
	float	xtmp;

	k = 0;
	while (k < info->max_iter)
	{
		xtmp = powf(x * x + y * y, info->p / 2)
		* cos(info->p * atan2(y, x)) + info->z_r;
		y = powf(x * x + y * y, info->p / 2) *
		sin(info->p * atan2(y, x)) + info->z_i;
		x = xtmp;
		if ((x * x + y * y) > 4)
			break ;
		k++;
	}
	if (k == info->max_iter)
		return (k);
	return (k + 1 - log(log2(fabs(x * x + y * y))));
}

void			*julia_cube(void *thrds)
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
			info.iter = op_count_ju(&info, info.c_r, info.c_i);
			if (info.iter != info.max_iter)
				color_selection(&info, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
