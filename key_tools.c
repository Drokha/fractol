/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:12:54 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 19:14:19 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keyboard_zoom(t_info *info, int key)
{
	if (key == 24)
	{
		info->x1 += -1 * info->x1 / 10;
		info->x2 -= info->x2 / 10;
		info->y1 += -1 * info->y1 / 10;
		info->y2 -= info->y2 / 10;
		drawer(info);
	}
	if (key == 27)
	{
		info->x1 -= -1 * info->x1 / 10;
		info->x2 += info->x2 / 10;
		info->y1 -= -1 * info->y1 / 10;
		info->y2 += info->y2 / 10;
		drawer(info);
	}
}

void	arrow_keys(t_info *info, int key)
{
	if (key == 126)
	{
		info->decy += 0.1;
		img(info);
		drawer(info);
	}
	if (key == 124)
	{
		info->decx -= 0.1;
		drawer(info);
	}
	if (key == 125)
	{
		info->decy -= 0.1;
		drawer(info);
	}
	if (key == 123)
	{
		info->decx += 0.1;
		drawer(info);
	}
}

void	iter_mod(t_info *info, int key)
{
	if (key == 69)
	{
		info->max_iter += 1;
		drawer(info);
	}
	if (key == 78)
	{
		info->max_iter -= 1;
		drawer(info);
	}
}

void	julia_preset(t_info *info, int key)
{
	if (key == 6)
	{
		info->z_r = 0.285;
		info->z_i = 0.01;
	}
	if (key == 7)
	{
		info->z_r = 0.3;
		info->z_i = 0.5;
	}
	if (key == 8)
	{
		info->z_r = 0.285;
		info->z_i = 0.013;
	}
	if (key == 9)
	{
		info->z_r = -1.476;
		info->z_i = 0;
	}
	if (key == 11)
	{
		info->z_r = -0.4;
		info->z_i = 0.6;
	}
}

void	change_frac(t_info *info, int key)
{
	if (key == 18)
		info->fract = 0;
	if (key == 19)
		info->fract = 1;
	if (key == 20)
		info->fract = 2;
	if (key == 21)
		info->fract = 3;
	if (key == 23)
		info->fract = 4;
	drawer(info);
}
