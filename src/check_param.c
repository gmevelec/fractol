/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/21 04:47:13 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/21 04:47:13 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../libft/libft.h"

int		check_param(char *str)
{
	if (!ft_strcmp(str, "julia"))
	{
		g()->name = ft_strdup("julia");
		return (0);
	}
	else if (!ft_strcmp(str, "mandelbrot"))
	{
		g()->name = ft_strdup("mandelbrot");
		return (0);
	}
	else if (!ft_strcmp(str, "burningship"))
	{
		g()->name = ft_strdup("burningship");
		return (0);
	}
	return (1);
}
