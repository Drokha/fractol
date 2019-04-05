/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:48:21 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 19:25:35 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	op_count(t_info *info, float z_r, float z_i)
{
	int		k;
	float	tmp;

	k = 0;
	while (k < info->max_iter)
	{
		tmp = z_r;
		z_r = ((z_r * z_r) - (z_i * z_i)) + info->z_r;
		z_i = (2 * z_i * tmp) + info->z_i;
		if ((z_i * z_i + z_r * z_r) > 4)
			break ;
		k++;
	}
	if (k == info->max_iter)
		return (k);
	return (k + 1 - log(log2(fabs(z_r * z_r + z_i * z_i))));
}

void		*julia(void *thrds)
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
			info.c_r = ((x / info.iw) * ((info.x2 - info.x1)) -
			(info.x2 - info.x1) / 2) + info.decx;
			info.c_i = ((y / info.ih) * ((info.y2 - info.y1)) -
			(info.y2 - info.y1) / 2) + info.decy;
			info.iter = op_count(&info, info.c_r, info.c_i);
			if (info.iter != info.max_iter)
				color_selection(&info, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
