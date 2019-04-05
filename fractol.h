/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trabut <trabut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:08:15 by trabut            #+#    #+#             */
/*   Updated: 2019/04/02 19:29:57 by trabut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "math.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define KEYPRESS 2
# define KEYRELEASE 3
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define NB_THREADS 20

typedef struct s_thrd	t_thrd;
typedef struct s_mthrds	t_mthrds;
typedef	struct s_info	t_info;

struct					s_thrd
{
	int					id;
	t_info				*info;
	int					n;
};

struct					s_mthrds
{
	pthread_t			threads[NB_THREADS];
	t_thrd				thrd[NB_THREADS];
};

struct					s_info
{
	void				*ptr;
	void				*win;
	char				*addr;
	void				*img;
	int					cap;
	int					iter;
	int					max_iter;
	int					ww;
	int					wh;
	int					iw;
	int					ih;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	int					c;
	double				decy;
	double				decx;
	int					fract;
	double				z_r;
	double				z_i;
	double				c_i;
	double				c_r;
	int					infcap;
	int					nb_thrd;
	float				p;
	t_mthrds			mthrds;
};

void					ft_multithreading(t_info *info);
void					*mandelbrot(void	*thrd);
void					img(t_info *info);
int						mouse_button(int button, int x, int y, t_info *info);
int						ft_strcmp(const char *s1, const char *s2);
void					drawer(t_info *info);
void					*mandelbar(void *thrds);
void					*julia_cube(void *thrds);
void					color_set(t_info *info, int key);
int						color_selection(t_info *info, int x, int y);
void					keyboard_zoom(t_info *info, int key);
void					arrow_keys(t_info *info, int key);
void					iter_mod(t_info *info, int key);
void					button_p(t_info *info, int button, float x, float y);
void					set_info(t_info *info);
int						av_check(char *input, t_info *info);
void					*mandelbrot2(void *thrds);
void					*julia(void *thrds);
void					julia_preset(t_info *info, int key);
void					draw_info(t_info *info);
void					change_frac(t_info *info, int key);
void					draw_param(t_info *info);
int						iter_count_mult(float z_r, float z_i, t_info *info);
void					*multibrot(void *thrds);

#endif
