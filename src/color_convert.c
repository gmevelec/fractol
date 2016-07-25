/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 04:37:18 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/21 04:38:20 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "math.h"

unsigned int	rgb_to_hex(t_env e, int r, int g, int b)
{
	unsigned int	hexa;

	hexa = ((r & 0xFF) << e.bpp / 2) + ((g & 0xFF) << e.bpp / 4) + (b & 0xFF);
	return (hexa);
}

static void		set_rgb_color(t_color *color, double a, double b, double c)
{
	color->r = a;
	color->g = b;
	color->b = c;
}

void			hsv_to_rgb(t_color *color, double h, double s, double v)
{
	int		i;
	double	f;
	double	p;
	double	q;
	double	t;

	h /= 60;
	i = floor(h);
	f = h - i;
	p = v * (1 - s);
	q = v * (1 - s * f);
	t = v * (1 - s * (1 - f));
	if (i == 0)
		set_rgb_color(color, v, t, p);
	else if (i == 1)
		set_rgb_color(color, q, v, p);
	else if (i == 2)
		set_rgb_color(color, p, v, t);
	else if (i == 3)
		set_rgb_color(color, p, q, v);
	else if (i == 4)
		set_rgb_color(color, t, p, v);
	else
		set_rgb_color(color, v, p, q);
}
