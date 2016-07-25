/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 17:00:33 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/21 17:00:34 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../inc/mlx.h"

void		moveup(void)
{
	g()->movey -= 0.1 / g()->zoom;
	g()->reload_screen = 1;
	expose_hook();
}

void		movedown(void)
{
	g()->movey += 0.1 / g()->zoom;
	g()->reload_screen = 1;
	expose_hook();
}

void		moveleft(void)
{
	g()->movex -= 0.1 / g()->zoom;
	g()->reload_screen = 1;
	expose_hook();
}

void		moveright(void)
{
	g()->movex += 0.1 / g()->zoom;
	g()->reload_screen = 1;
	expose_hook();
}
