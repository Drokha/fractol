/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:19:06 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 19:24:14 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	put_point(t_info *info, int x, int y, int c_value)
{
	int pos;

	if (x < info->iw && y < info->ih && x > 0 && y > 0)
	{
		pos = x * 4;
		pos += y * info->iw * 4;
		if (pos + 2 < info->iw * 4 * info->ih && pos >= 0)
		{
			info->addr[pos] = c_value >> 8;
			info->addr[pos + 1] = c_value >> 16;
			info->addr[pos + 2] = c_value;
		}
	}
}

void			color_set(t_info *info, int key)
{
	if (key == 0)
		info->c = 0;
	if (key == 1)
		info->c = 1;
	if (key == 2)
		info->c = 2;
	if (key == 3)
		info->c = 3;
	if (key == 5)
		info->c = 4;
	if (key == 4)
		info->c = 5;
	drawer(info);
}

int				color_selection(t_info *info, int x, int y)
{
	if (info->c == 0)
		put_point(info, x, y, RGB((info->iter) % 127, (info->iter) % 127 + 50,
		(info->iter * 10) % 127));
	if (info->c == 1)
		put_point(info, x, y, RGB(127 - (info->iter * 127 / info->max_iter),
		127 - (info->iter * 127 / info->max_iter), 127
		- (info->iter * 127 / info->max_iter)));
	if (info->c == 2)
	{
		put_point(info, x, y, RGB(10, info->iter * 7,
		10));
	}
	if (info->c == 3)
		put_point(info, x, y, RGB(info->iter * info->iter * info->iter % 127,
		info->iter * 10 % 127, info->iter * info->iter % 127));
	if (info->c == 4)
		put_point(info, x, y, RGB(10,
		10, 127 - info->iter * info->iter));
	if (info->c == 5)
		put_point(info, x, y, RGB(10, info->iter * info->iter + 30,
		info->iter * info->iter));
	return (1);
}
