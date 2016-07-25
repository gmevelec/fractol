/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 16:23:52 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/21 06:10:09 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_X 1024
# define WIN_Y 768

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

/*
** t_bool
*/
typedef short	t_bool;

/*
** t_threads
*/
typedef struct	s_threads
{
	pthread_t	thread;
	int			loading;

}				t_threads;

/*
** t_color
** r / 100
** g / 100
** b / 100
*/
typedef struct	s_color
{
	double		r;
	double		g;
	double		b;

}				t_color;

/*
** t_fractal
*/
typedef struct	s_fractal
{
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		pre;
	double		pim;
	int			nbiter;
}				t_fractal;

/*
** t_img
*/
typedef struct	s_img
{
	void	*img_ptr;
	char	*img_data;
	int		res_x;
	int		res_y;

}				t_img;

/*
** t_env
*/
typedef struct	s_env
{
	void		*mlx;
	void		*win;

	int			bpp;
	int			sizeline;
	int			endian;

}				t_env;

/*
** t_gen
*/
typedef struct	s_gen
{
	t_env		e;
	t_threads	*thrds;
	t_img		img;
	char		*name;
	t_bool		reload_screen;
	double		zoom;
	double		movex;
	double		movey;
	double		mousex;
	double		mousey;
	int			pause;

}				t_gen;

/*
** main.c
*/
t_gen			*g(void);
void			*render_picture(void *plus);
int				expose_hook(void);
int				key_hook(int keycode);
int				mouse_hook(int button, int x, int y);
int				pointer_hook(int x, int y);

/*
** error.c
*/
void			error(char *str);

/*
** init.c
*/
void			init_data_addr(void);

/*
** thread.c
*/
void			launch_threads(void);
void			*render_picture(void *plus);
void			loading(double percent, int thread);

/*
** color_convert.c
*/
unsigned int	rgb_to_hex(t_env e, int r, int g, int b);
void			hsv_to_rgb(t_color *color, double h, double s, double v);

/*
** draw_fractal.c
*/
void			put_pixel(char *data, int y, int x, t_color color);
void			draw_julia(int y, int x);
void			draw_mandelbrot(int y, int x);
void			draw_burningship(int y, int x);

/*
** check_param.c
*/
int				check_param(char *str);

/*
** render.c
*/
void			render_mandelbrot(int y, void *plus);
void			render_julia(int y, void *plus);
void			render_burningship(int y, void *plus);

/*
** render.c
*/
void			moveup(void);
void			movedown(void);
void			moveleft(void);
void			moveright(void);

#endif
