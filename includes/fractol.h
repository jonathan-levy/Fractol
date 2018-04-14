/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:43:02 by jolevy            #+#    #+#             */
/*   Updated: 2018/04/14 10:58:01 by jolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include <time.h>

# include "mlx.h"
# include "keys.h"
# include "mouse.h"
# include "libft.h"

# define WIN_WIDTH			(1280)
# define WIN_HEIGHT			(720)
# define TITLE(fractal)		(ft_strjoin("Fractol - ", ft_strcap(fractal)))
# define THREADS			(8)
# define SCALE_LIMIT		(500000000)
# define SCALE_PRECISION	(1.042)

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_type
{
	int		type;
	int		depth;
	int		iteration;
	double	width;
	double	height;
	double	scale;
	double	limit;
	double	xr;
	double	yi;
}				t_type;

typedef struct	s_mouse
{
	int		state;
	int		pos_x;
	int		pos_y;
}				t_mouse;

typedef struct	s_fractol
{
	t_mlx	mlx;
	t_image	image;
	t_color	color;
	t_type	fractal;
	t_mouse	mouse;
}				t_fractol;

void			fractol_init(t_fractol *fractol);
void			fractol_update(t_fractol *fractol);
void			hookers(t_fractol *fractol);

int				fractol_keys(int keycode, t_fractol *fractol);
int				fractol_mouse(int mousecode, int x, int y, t_fractol *fractol);

void			fractol_pthread(t_fractol *fractol);
int				fractol_manipulate(int x, int y, t_fractol *fractol);

int				mandelbrot(t_fractol *fractol);
int				julia(t_fractol *fractol);
int				rorscharch(t_fractol *fractol);

int				sphere(t_fractol *fractol);
int				pipi(t_fractol *fractol);
int				compass(t_fractol *fractol);
int				pikachu(t_fractol *fractol);
int				birdie(t_fractol *fractol);

#endif
