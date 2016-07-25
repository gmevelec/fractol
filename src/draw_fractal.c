/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 04:40:38 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/21 04:44:06 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/mlx.h"
#include <math.h>

static void		init_fractal(t_fractal *fractal, int i)
{
	fractal->nbiter = i;
}

void			draw_julia(int y, int x)
{
	t_fractal	julia;
	t_color		color;
	int			i;

	init_fractal(&julia, 100);
	julia.pre = -0.7 + g()->mousex;
	julia.pim = 0.27015 + g()->mousey;
	julia.newre = 1.5 * (x - (g()->img.res_x / 2)) /
				(0.5 * g()->zoom * g()->img.res_y) + g()->movex;
	julia.newim = (y - g()->img.res_y / 2) /
				(0.5 * g()->zoom * g()->img.res_y) + g()->movey;
	i = -1;
	while (++i < julia.nbiter)
	{
		julia.oldre = julia.newre;
		julia.oldim = julia.newim;
		julia.newre = julia.oldre * julia.oldre -
					julia.oldim * julia.oldim + julia.pre;
		julia.newim = 2 * julia.oldre * julia.oldim + julia.pim;
		if ((julia.newre * julia.newre + julia.newim * julia.newim) > 4)
			break ;
	}
	hsv_to_rgb(&color, i % 256, 1, 255 * (i < julia.nbiter));
	put_pixel(g()->img.img_data, y, x, color);
}

void			draw_mandelbrot(int y, int x)
{
	t_fractal	mandel;
	t_color		color;
	int			i;

	init_fractal(&mandel, 128);
	mandel.pre = 1.5 * (x - (g()->img.res_x / 2)) /
				(0.5 * g()->zoom * g()->img.res_y) + g()->movex;
	mandel.pim = (y - g()->img.res_y / 2) /
				(0.5 * g()->zoom * g()->img.res_y) + g()->movey;
	mandel.newre = 0;
	mandel.newim = 0;
	i = -1;
	while (++i < mandel.nbiter)
	{
		mandel.oldre = mandel.newre;
		mandel.oldim = mandel.newim;
		mandel.newre = mandel.oldre * mandel.oldre -
					mandel.oldim * mandel.oldim + mandel.pre;
		mandel.newim = 2 * mandel.oldre * mandel.oldim + mandel.pim;
		if ((mandel.newre * mandel.newre + mandel.newim * mandel.newim) > 4)
			break ;
	}
	hsv_to_rgb(&color, i % 256, 1, 255 * (i < mandel.nbiter));
	put_pixel(g()->img.img_data, y, x, color);
}

void			draw_burningship(int y, int x)
{
	t_fractal	ship;
	t_color		color;
	int			i;

	init_fractal(&ship, 128);
	ship.pre = 1.5 * (x - (g()->img.res_x / 2)) /
			(0.5 * g()->zoom * g()->img.res_y) + g()->movex;
	ship.pim = (y - g()->img.res_y / 2) /
			(0.5 * g()->zoom * g()->img.res_y) + g()->movey;
	ship.oldre = ship.pre;
	ship.oldim = ship.pim;
	ship.newre = fabs(ship.oldre) * fabs(ship.oldre);
	ship.newim = fabs(ship.oldim) * fabs(ship.oldim);
	i = -1;
	while (++i < ship.nbiter)
	{
		ship.oldim = 2 * fabs(ship.oldre) * fabs(ship.oldim) + ship.pim;
		ship.oldre = fabs(ship.newre) - fabs(ship.newim) + ship.pre;
		ship.newre = ship.oldre * ship.oldre;
		ship.newim = ship.oldim * ship.oldim;
		if ((ship.newre + ship.newim) > 4)
			break ;
	}
	hsv_to_rgb(&color, i % 256, 1, 255 * (i < ship.nbiter));
	put_pixel(g()->img.img_data, y, x, color);
}

void			put_pixel(char *data, int y, int x, t_color color)
{
	unsigned int	hex_color;
	unsigned int	hexa;
	int				i;

	hexa = rgb_to_hex(g()->e, color.r, color.g, color.b);
	hex_color = mlx_get_color_value(g()->e.mlx, hexa);
	i = y * g()->e.sizeline + (g()->e.bpp / 8) * x;
	data[i] = (hex_color & 0xFF);
	data[i + 1] = (hex_color & 0xFF00) >> 8;
	data[i + 2] = (hex_color & 0xFF0000) >> 16;
}
