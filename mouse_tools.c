/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:46:25 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 18:20:41 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	button_p(t_info *info, int button, float x, float y)
{
	if (button == 4)
	{
		info->x1 += -1 * info->x1 / 20;
		info->x2 -= info->x2 / 20;
		info->y1 += -1 * info->y1 / 20;
		info->y2 -= info->y2 / 20;
		info->decx += ((x / info->iw) * (info->x2 - info->x1) - info->x2) / 2;
		info->decy += ((y / info->ih) * (info->y2 - info->y1) - info->y2) / 2;
		drawer(info);
	}
	if (button == 5)
	{
		info->x1 -= -1 * info->x1 / 20;
		info->x2 += info->x2 / 20;
		info->y1 -= -1 * info->y1 / 20;
		info->y2 += info->y2 / 20;
		info->decx += ((x / info->iw) * (info->x2 - info->x1) - info->x2) / 2;
		info->decy += ((y / info->ih) * (info->y2 - info->y1) - info->y2) / 2;
		drawer(info);
	}
}
