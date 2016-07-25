/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 20:12:26 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/18 20:12:26 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../libft/libft.h"

void			launch_threads(void)
{
	pthread_create(&g()->thrds[0].thread, NULL, render_picture, (void*)0);
	pthread_create(&g()->thrds[1].thread, NULL, render_picture, (void*)1);
	pthread_create(&g()->thrds[2].thread, NULL, render_picture, (void*)2);
	pthread_create(&g()->thrds[3].thread, NULL, render_picture, (void*)3);
	pthread_join(g()->thrds[0].thread, NULL);
	pthread_join(g()->thrds[1].thread, NULL);
	pthread_join(g()->thrds[2].thread, NULL);
	pthread_join(g()->thrds[3].thread, NULL);
}

void			loading(double percent, int thread)
{
	int			i;

	g()->thrds[thread].loading = percent * 100;
	if (thread == 0)
	{
		ft_putstr("\033[s");
		i = 0;
		while (i < 4)
		{
			ft_putstr("[");
			ft_putnbr(g()->thrds[i].loading);
			ft_putstr(" / 100]  ");
			i++;
		}
		ft_putstr("                          ");
		ft_putstr("\033[u");
	}
}
