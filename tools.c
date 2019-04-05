/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:58:07 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 18:52:54 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_info(t_info *info)
{
	info->z_i = 0;
	info->z_r = 0;
	info->wh = 900;
	info->ww = 1400;
	info->ih = 900;
	info->iw = 900;
	info->max_iter = 20;
	info->x1 = -2;
	info->x2 = 2;
	info->y1 = -2;
	info->y2 = 2;
	info->decx = 0;
	info->decy = 0;
	info->cap = 0;
	info->nb_thrd = 20;
	info->p = 2;
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

void	img(t_info *info)
{
	int bpp;
	int size_l;
	int endian;

	bpp = 32;
	size_l = info->iw * 4;
	endian = 0;
	info->img = mlx_new_image(info->ptr, info->iw, info->ih);
	info->addr = mlx_get_data_addr(info->img, &bpp, &size_l, &endian);
}

void	drawer(t_info *info)
{
	img(info);
	ft_multithreading(info);
	mlx_put_image_to_window(info->ptr, info->win, info->img, 0, 0);
	if (info->infcap == 0)
		draw_param(info);
}

int		av_check(char *input, t_info *info)
{
	if (ft_strcmp(input, "mandelbrot") == 0)
		info->fract = 0;
	else if (ft_strcmp(input, "julia") == 0)
		info->fract = 1;
	else if (ft_strcmp(input, "mandelbar") == 0)
		info->fract = 2;
	else if (ft_strcmp(input, "julia2") == 0)
		info->fract = 3;
	else if (ft_strcmp(input, "mandelbrot2") == 0)
		info->fract = 4;
	else
		return (0);
	return (1);
}
