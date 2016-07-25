/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 18:57:28 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/15 18:57:28 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../libft/libft.h"
#include "../inc/mlx.h"
#include "math.h"

int				expose_hook(void)
{
	if (g()->reload_screen)
	{
		g()->reload_screen = 0;
		launch_threads();
	}
	mlx_put_image_to_window(g()->e.mlx, g()->e.win, g()->img.img_ptr, 0, 0);
	return (0);
}

int				key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
		moveup();
	else if (keycode == 125)
		movedown();
	else if (keycode == 124)
		moveright();
	else if (keycode == 123)
		moveleft();
	else if (keycode == 49)
	{
		if (!g()->pause)
			g()->pause = 1;
		else
			g()->pause = 0;
	}
	return (0);
}

int				mouse_hook(int button, int x, int y)
{
	if (button == 5 || button == 1)
	{
		g()->zoom += 1;
		g()->reload_screen = 1;
		expose_hook();
	}
	else if (button == 4 || button == 2)
	{
		if (g()->zoom > 1)
		{
			g()->zoom -= 1;
			g()->reload_screen = 1;
			expose_hook();
		}
	}
	return (0);
}

int				pointer_hook(int x, int y)
{
	if (x > 0 && x < g()->img.res_x && y > 0 && y < g()->img.res_y
		&& !g()->pause)
	{
		g()->mousex = x * 0.001;
		g()->mousey = y * 0.001;
		g()->reload_screen = 1;
		expose_hook();
	}
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc != 2)
		error("wrong usage ! ./fractol [julia, mandelbrot, burningship]");
	if (check_param(argv[1]))
		error("Wrong param ! ./fractol [julia, mandelbrot, burningship]");
	g()->reload_screen = 1;
	g()->e.mlx = mlx_init();
	if (!g()->e.mlx)
		error("Mlx can't init !");
	g()->e.win = mlx_new_window(g()->e.mlx, g()->img.res_x,
		g()->img.res_y, g()->name);
	g()->img.img_ptr = mlx_new_image(g()->e.mlx,
									g()->img.res_x, g()->img.res_y);
	g()->thrds = (t_threads*)malloc(sizeof(t_threads) * 4);
	init_data_addr();
	mlx_key_hook(g()->e.win, key_hook, &g()->e);
	mlx_mouse_hook(g()->e.win, mouse_hook, &g()->e);
	if (!ft_strcmp(g()->name, "julia"))
		mlx_hook(g()->e.win, 6, 1, pointer_hook, &g()->e);
	mlx_expose_hook(g()->e.win, expose_hook, NULL);
	mlx_loop(g()->e.mlx);
	return (0);
}
