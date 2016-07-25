/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 05:34:28 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/21 05:36:18 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../libft/libft.h"

void		render_mandelbrot(int y, void *plus)
{
	int		x;

	while (y < g()->img.res_y)
	{
		x = 0;
		loading(y / (double)g()->img.res_y, (size_t)plus);
		while (x < g()->img.res_x)
		{
			draw_mandelbrot(y, x);
			x++;
		}
		y += 4;
	}
}

void		render_julia(int y, void *plus)
{
	int		x;

	while (y < g()->img.res_y)
	{
		x = 0;
		loading(y / (double)g()->img.res_y, (size_t)plus);
		while (x < g()->img.res_x)
		{
			draw_julia(y, x);
			x++;
		}
		y += 4;
	}
}

void		render_burningship(int y, void *plus)
{
	int		x;

	while (y < g()->img.res_y)
	{
		x = 0;
		loading(y / (double)g()->img.res_y, (size_t)plus);
		while (x < g()->img.res_x)
		{
			draw_burningship(y, x);
			x++;
		}
		y += 4;
	}
}

void		*render_picture(void *plus)
{
	int			y;

	y = (size_t)plus;
	if (!ft_strcmp(g()->name, "mandelbrot"))
		render_mandelbrot(y, plus);
	else if (!ft_strcmp(g()->name, "julia"))
		render_julia(y, plus);
	else if (!ft_strcmp(g()->name, "burningship"))
		render_burningship(y, plus);
	return (NULL);
}
