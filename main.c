/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:54:53 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 19:21:47 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int		mouse_move(int x, int y, t_info *info)
{
	float	a;
	float	b;

	if (info->cap == 0 && (info->fract == 1 || info->fract == 3))
	{
		a = x * 1.0;
		b = y * 1.0;
		a = a / info->ww * info->iw;
		b = b / info->wh * info->ih;
		info->z_r = ((a / info->iw) * (2 - (-2))) - (2 - (-2)) / 2;
		info->z_i = ((b / info->ih) * (2 - (-2))) - (2 - (-2)) / 2;
		drawer(info);
	}
	return (0);
}

static	int		mouse_key(int button, int x, int y, t_info *info)
{
	float xf;
	float yf;

	xf = x;
	yf = y;
	if (button == 3)
	{
		if (info->cap)
			info->cap = 0;
		else
			info->cap = 1;
	}
	if (button == 4 || button == 5)
		button_p(info, button, x, y);
	if (button == 1)
	{
		info->decx += ((xf / info->iw) * (info->x2 - info->x1) - info->x2) / 2;
		info->decy += ((yf / info->ih) * (info->y2 - info->y1) - info->y2) / 2;
		drawer(info);
	}
	return (0);
}

static	int		deal_key(int key, t_info *info)
{
	if (key == 53)
	{
		exit(0);
	}
	if (key == 29)
	{
		info->z_i = 0;
		info->z_r = 0;
		set_info(info);
		drawer(info);
	}
	if (key >= 18 && key <= 23)
		change_frac(info, key);
	if (key == 42)
	{
		if (info->infcap)
			info->infcap = 0;
		else
			info->infcap = 1;
	}
	return (0);
}

static	int		key_press(int key, t_info *info)
{
	if (key >= 0 && key <= 5)
		color_set(info, key);
	if (key == 69 || key == 78)
		iter_mod(info, key);
	if (key == 24 || key == 27)
		keyboard_zoom(info, key);
	if (key <= 126 && key >= 123)
		arrow_keys(info, key);
	if (key == 30)
	{
		info->p += 0.1;
		drawer(info);
	}
	if (key == 33)
	{
		info->p -= 0.1;
		drawer(info);
	}
	if (key >= 6 && key <= 11)
	{
		julia_preset(info, key);
		info->cap = 1;
		drawer(info);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_info info;

	if (ac != 2)
	{
		write(1, "bad arguments : try ./fractol <fractal name>\n", 45);
		exit(0);
	}
	if (!(av_check(av[1], &info)))
	{
		write(1, "wrong argument, try:\nmandelbrot\n", 32);
		write(1, "julia\njulia2\nmandelbar\nmandelbrot2\n", 35);
		exit(0);
	}
	info.ptr = mlx_init();
	set_info(&info);
	info.win = mlx_new_window(info.ptr, info.ww, info.wh, "fractol");
	draw_info(&info);
	drawer(&info);
	mlx_key_hook(info.win, deal_key, &info);
	mlx_hook(info.win, BUTTONPRESS, 0, mouse_key, &info);
	mlx_hook(info.win, MOTIONNOTIFY, 0, mouse_move, &info);
	mlx_hook(info.win, KEYPRESS, 0, key_press, &info);
	mlx_loop(info.ptr);
	return (0);
}
