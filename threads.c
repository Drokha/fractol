/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:38:05 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 19:22:52 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*choose(t_info *info)
{
	if (info->fract == 0)
		return (mandelbrot);
	if (info->fract == 1)
		return (julia);
	if (info->fract == 2)
		return (mandelbar);
	if (info->fract == 3)
		return (julia_cube);
	if (info->fract == 4)
		return (mandelbrot2);
	return (NULL);
}

void		ft_multithreading(t_info *info)
{
	t_mthrds	*mthrds;
	int			i;

	mthrds = &info->mthrds;
	i = -1;
	while (++i < info->nb_thrd)
	{
		mthrds->thrd[i].id = i;
		mthrds->thrd[i].info = info;
		pthread_create(&mthrds->threads[i], NULL, \
		choose(info), &mthrds->thrd[i]);
	}
	i = -1;
	while (++i < info->nb_thrd)
	{
		pthread_join(mthrds->threads[i], NULL);
	}
}
