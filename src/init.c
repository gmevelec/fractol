/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/17 16:31:30 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/17 16:31:30 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/mlx.h"

void			init_data_addr(void)
{
	g()->img.img_data = mlx_get_data_addr(g()->img.img_ptr, &g()->e.bpp,
		&g()->e.sizeline, &g()->e.endian);
}

t_gen			*g(void)
{
	static t_gen	*gen = NULL;

	if (gen == NULL)
	{
		gen = (t_gen *)malloc(sizeof(t_gen));
		gen->img.res_x = 1024;
		gen->img.res_y = 768;
		gen->zoom = 1;
		gen->movex = 0;
		gen->movey = 0;
		gen->mousex = -0.7;
		gen->mousey = 0.27015;
		gen->pause = 0;
	}
	return (gen);
}
