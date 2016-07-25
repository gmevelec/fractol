/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 21:01:43 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/18 21:01:44 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../libft/libft.h"

void		error(char *str)
{
	ft_putstr("\033[31mError: ");
	ft_putendl(str);
	ft_putstr("\033[0m");
	_exit(-1);
}
