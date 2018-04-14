/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:48:09 by jolevy            #+#    #+#             */
/*   Updated: 2018/04/13 09:48:17 by jolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			rorscharch(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	cr = (fractol->mouse.pos_x - WIN_WIDTH) / ((double)WIN_WIDTH * 2) + 0.25;
	ci = (fractol->mouse.pos_y - WIN_HEIGHT) / ((double)WIN_HEIGHT) + 0.50;
	zi = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.yi;
	zr = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.xr;
	while (FT_SQUARE(zr) + FT_SQUARE(zi) < 4 \
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = fabs(zr);
		zr = FT_SQUARE(zr) - FT_SQUARE(zi) - cr;
		zi = (2 * zi) * tmp_zr - ci;
		fractol->fractal.depth += 1;
	}
	return (fractol->fractal.depth);
}

int			julia(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	cr = (fractol->mouse.pos_x - (210.0 / 2.0) - WIN_WIDTH) \
			/ ((double)WIN_WIDTH * 2) + 0.15;
	ci = (fractol->mouse.pos_y - (320.0 / 2.0) - WIN_HEIGHT) \
			/ (double)WIN_HEIGHT - 0.15;
	zi = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.yi;
	zr = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.xr;
	while (FT_SQUARE(zr) + FT_SQUARE(zi) < 4 \
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = FT_SQUARE(zr) - FT_SQUARE(zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractol->fractal.depth += 1;
	}
	return (fractol->fractal.depth);
}

int			mandelbrot(t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	fractol->fractal.depth = 0;
	zr = (fractol->mouse.pos_x - WIN_WIDTH) / ((double)WIN_WIDTH * 2) + 0.25;
	zi = (fractol->mouse.pos_y - WIN_HEIGHT) / ((double)WIN_HEIGHT) + 0.50;
	ci = fractol->fractal.width / fractol->fractal.scale + fractol->fractal.yi;
	cr = fractol->fractal.height / fractol->fractal.scale + fractol->fractal.xr;
	while (FT_SQUARE(zr) + FT_SQUARE(zi) < 4 \
			&& fractol->fractal.depth < fractol->fractal.iteration)
	{
		tmp_zr = zr;
		zr = FT_SQUARE(zr) - FT_SQUARE(zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		fractol->fractal.depth += 1;
	}
	return (fractol->fractal.depth);
}
