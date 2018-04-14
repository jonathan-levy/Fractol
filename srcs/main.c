/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:48:26 by jolevy            #+#    #+#             */
/*   Updated: 2018/04/13 09:49:07 by jolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		fractol_usage(char *argv0)
{
	ft_putstr("Usage: ");
	ft_putstr(ft_program_name(argv0));
	ft_putstr(" [ mandelbrot | julia | rorscharch | sphere | pipi | compass ");
	ft_putendl("| pikachu | birdie ]");
	ft_putendl("Keys:");
	ft_putendl("\t[I]               -> Zoom in");
	ft_putendl("\t[O]               -> Zoom out");
	ft_putendl("\t[J]               -> Iterations++");
	ft_putendl("\t[K]               -> Iterations--");
	ft_putendl("\t[R]               -> Reset values");
	ft_putendl("\t[SPACE]           -> Colorize");
	ft_putendl("\t[W][A][S][D]      -> Move");
	ft_putendl("\t[ESC]             -> Exit");
	ft_putendl("Mouse:");
	ft_putendl("\t[SCROLL]          -> Zoom");
	ft_putendl("\t[RIGHT CLK]       -> Colorize");
	ft_putendl("\t[MIDDLE CLK]      -> Reset values");
	ft_putendl("\t[LEFT CLK]        -> Manipulate fractal");
}

static int		fractol_selection(char *argument, t_fractol *fractol)
{
	fractol->fractal.type = 0;
	if (ft_strequ(ft_str_to_lowcase(argument), "mandelbrot"))
		fractol->fractal.type = 1;
	else if (ft_strequ(ft_str_to_lowcase(argument), "julia"))
		fractol->fractal.type = 2;
	else if (ft_strequ(ft_str_to_lowcase(argument), "rorscharch"))
		fractol->fractal.type = 3;
	else if (ft_strequ(ft_str_to_lowcase(argument), "sphere"))
		fractol->fractal.type = 4;
	else if (ft_strequ(ft_str_to_lowcase(argument), "pipi"))
		fractol->fractal.type = 5;
	else if (ft_strequ(ft_str_to_lowcase(argument), "compass"))
		fractol->fractal.type = 6;
	else if (ft_strequ(ft_str_to_lowcase(argument), "pikachu"))
		fractol->fractal.type = 7;
	else if (ft_strequ(ft_str_to_lowcase(argument), "birdie"))
		fractol->fractal.type = 8;
	else
	{
		ft_putstr(argument);
		ft_putendl(" is not a valid parameter! :(");
		ft_putendl("See usage for a list of valid parameters. ;)");
	}
	return (fractol->fractal.type);
}

void			fractol_init(t_fractol *fractol)
{
	fractol->fractal.xr = -2.60;
	fractol->fractal.yi = -1.20;
	fractol->fractal.scale = 300.00;
	fractol->fractal.iteration = 42;
	fractol->color.red = 0x42;
	fractol->color.green = 0x32;
	fractol->color.blue = 0x22;
	fractol->mouse.pos_x = WIN_WIDTH / 2;
	fractol->mouse.pos_y = WIN_HEIGHT / 2;
	if (fractol->fractal.type == 2 || fractol->fractal.type == 4 \
			|| fractol->fractal.type == 3)
	{
		fractol->fractal.xr = -2.10;
		fractol->mouse.state = 1;
		if (fractol->fractal.type == 2 || fractol->fractal.type == 4)
			fractol->fractal.iteration = 100;
		if (fractol->fractal.type == 3)
			fractol->fractal.iteration = 10;
	}
	if (fractol->fractal.type == 5)
	{
		fractol->fractal.xr = -2.20;
		fractol->fractal.yi = -1.60;
		fractol->fractal.iteration = 14;
	}
}

void			fractol_update(t_fractol *fractol)
{
	char *tmp_iteration;
	char *tmp_scale;
	char *tmp_join_iter;
	char *tmp_join_scale;

	tmp_iteration = ft_itoa(fractol->fractal.iteration);
	tmp_scale = ft_itoa((int)fractol->fractal.scale);
	tmp_join_iter = ft_strjoin("Number of iterations : ", tmp_iteration);
	tmp_join_scale = ft_strjoin("Zoom level: ", tmp_scale);
	if (fractol->fractal.iteration <= 0)
		fractol->fractal.iteration = 0;
	fractol_pthread(fractol);
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 5, 0xFFFFFF, \
	tmp_join_iter);
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 35, 0xFFFFFF, \
	tmp_join_scale);
	free(tmp_iteration);
	free(tmp_scale);
	free(tmp_join_iter);
	free(tmp_join_scale);
}

int				main(int argc, char *argv[])
{
	t_fractol	*fractol;
	char		*temp_title;

	if (argc == 2)
	{
		temp_title = TITLE(argv[1]);
		if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
			ft_puterror("Memory Allocation failed! :O", 1);
		if (!fractol_selection(argv[1], fractol))
			ft_puterror("Please, try again! :D", 2);
		fractol->mlx.init = mlx_init();
		fractol->mlx.win = mlx_new_window(fractol->mlx.init, WIN_WIDTH, \
			WIN_HEIGHT, temp_title);
		fractol->mlx.img = mlx_new_image(fractol->mlx.init, WIN_WIDTH, \
			WIN_HEIGHT);
		fractol->image.data = mlx_get_data_addr(fractol->mlx.img, \
			&fractol->image.bpp, &fractol->image.size, &fractol->image.endian);
		fractol_init(fractol);
		fractol_update(fractol);
		hookers(fractol);
		free(temp_title);
	}
	else
		fractol_usage(argv[0]);
	return (0);
}
