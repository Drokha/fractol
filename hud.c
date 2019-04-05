/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:04:38 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 19:47:52 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	clean_hud(t_info *info, int x, int y)
{
	void	*ptr;

	ptr = mlx_new_image(info->ptr, 500, 25);
	mlx_put_image_to_window(info->ptr, info->win, ptr, x, y);
	mlx_destroy_image(info->ptr, ptr);
}

static	void	put_fract_name(t_info *info)
{
	if (info->fract == 0)
		mlx_string_put(info->ptr, info->win, 950, 158, 95161, "Mandelbrot set");
	if (info->fract == 1)
		mlx_string_put(info->ptr, info->win, 950, 158, 95161, "Julia set");
	if (info->fract == 2)
		mlx_string_put(info->ptr, info->win, 950, 158, 95161, "Mandelbar set");
	if (info->fract == 3)
		mlx_string_put(info->ptr, info->win, 950, 158, 95161, "Julia Cube set");
	if (info->fract == 4)
		mlx_string_put(info->ptr, info->win, 950, 158, 95161, "Multibrot set");
}

void			draw_info(t_info *info)
{
	mlx_string_put(info->ptr, info->win, 950, 50, 95161, "Zoom +/-");
	mlx_string_put(info->ptr, info->win, 950, 68, 95161,
	"Change max_iter +/- numpad");
	mlx_string_put(info->ptr, info->win, 950, 86, 95161,
	"Z to B change julia preset");
	mlx_string_put(info->ptr, info->win, 950, 104, 95161,
	"A to H change colorset");
	mlx_string_put(info->ptr, info->win, 950, 122, 95161,
	"0 to reset settings");
	mlx_string_put(info->ptr, info->win, 950, 140, 95161,
	"Press mousewheel to unlock/lock julia");
	mlx_string_put(info->ptr, info->win, 950, 32, 95161,
	"| to stop HUD refresh");
	mlx_string_put(info->ptr, info->win, 950, 273, 95161,
	"[ or ] to decrease/increase power");
}

void			draw_param(t_info *info)
{
	char buff[50];

	clean_hud(info, 950, 158);
	put_fract_name(info);
	sprintf(buff, "%i", info->max_iter);
	clean_hud(info, 950, 176);
	mlx_string_put(info->ptr, info->win, 950, 176, 95161, "max iter =");
	mlx_string_put(info->ptr, info->win, 1060, 176, 95161, buff);
	sprintf(buff, "%f", 100 * (info->x2 - info->x1) / 4);
	clean_hud(info, 950, 194);
	mlx_string_put(info->ptr, info->win, 950, 194, 95161, "Zoom = ");
	mlx_string_put(info->ptr, info->win, 1020, 194, 95161, buff);
	sprintf(buff, "%f", info->z_r);
	clean_hud(info, 950, 212);
	mlx_string_put(info->ptr, info->win, 950, 212, 95161, "R part of C =");
	mlx_string_put(info->ptr, info->win, 1150, 212, 95161, buff);
	sprintf(buff, "%f", info->z_i);
	clean_hud(info, 950, 230);
	mlx_string_put(info->ptr, info->win, 950, 230, 95161, "I part of C =");
	mlx_string_put(info->ptr, info->win, 1150, 230, 95161, buff);
	sprintf(buff, "%f", info->p);
	clean_hud(info, 950, 248);
	mlx_string_put(info->ptr, info->win, 950, 248, 95161, "Power =");
	mlx_string_put(info->ptr, info->win, 1030, 248, 95161, buff);
}
