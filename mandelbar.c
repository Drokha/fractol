/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:34:28 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 19:16:25 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iter_count_bar(float r, float i, t_info *info)
{
	double	tmp;
	double	z_r;
	double	z_i;
	int		k;

	k = 0;
	z_r = 0;
	z_i = 0;
	while (k < info->max_iter)
	{
		tmp = z_r;
		z_r = ((z_r * z_r) - (z_i * z_i)) + r;
		z_i = -(2 * z_i * tmp) + i;
		if (z_i * z_i + z_r * z_r > 4)
			break ;
		k++;
	}
	return (k);
}

void		*mandelbar(void *thrds)
{
	t_info	info;
	t_thrd	thrd;
	double	x;
	double	y;

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
			info.iter = iter_count_bar(info.c_r, info.c_i, &info);
			if (info.iter != info.max_iter)
				color_selection(&info, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
