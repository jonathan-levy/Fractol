/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolevy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 10:47:26 by jolevy            #+#    #+#             */
/*   Updated: 2018/04/14 10:47:33 by jolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			hookers(t_fractol *fractol)
{
	mlx_hook(fractol->mlx.win, 2, 3, fractol_keys, fractol);
	mlx_hook(fractol->mlx.win, 4, 3, fractol_mouse, fractol);
	mlx_hook(fractol->mlx.win, 6, 3, fractol_manipulate, fractol);
	mlx_loop(fractol->mlx.init);
	return ;
}
