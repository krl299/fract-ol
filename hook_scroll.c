/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_scroll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:03:47 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/05 11:28:25 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//
double	ft_percent(int origen, int mouse_pos)
{
	double	percent;
	int		a;

	a = mouse_pos - origen;
	if (a < 0)
		a *= -1;
	percent = 0.000222222 * a;
	return (percent);
}

//
static void	ft_zoom_mouse(t_fractol *f, double zoom_r, double zoom_i)
{
	double	percent;

	percent = ft_percent(950, f->mouse_x);
	if (f->mouse_x < 950)
	{
		f->max_real += zoom_r * percent;
		f->min_real += zoom_r * percent;
	}
	else
	{
		f->max_real -= zoom_r * percent;
		f->min_real -= zoom_r * percent;
	}
	percent = ft_percent(350, f->mouse_y);
	if (f->mouse_y < 350)
	{
		f->max_imaginary += zoom_i * percent;
		f->min_imaginary += zoom_i * percent;
	}
	else
	{
		f->max_imaginary -= zoom_i * percent;
		f->min_imaginary -= zoom_i * percent;
	}
}

//
static void	ft_zoom(t_fractol *f, double zoom, double zoom_r, double zoom_i)
{
	f->max_real += (zoom_r - zoom * zoom_r) / 2;
	f->min_real = f->max_real + zoom * zoom_r;
	f->min_imaginary += (zoom_i - zoom * zoom_i) / 2;
	f->max_imaginary = f->min_imaginary + zoom * zoom_i;
	if (f->mouse_x > 500)
		ft_zoom_mouse(f, zoom_r, zoom_i);
}

//
void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	double	zoom_r;
	double	zoom_i;

	(void)xdelta;
	mlx_get_mouse_pos(((t_fractol *)param)->mlx, \
			&((t_fractol *)param)->mouse_x, \
			&((t_fractol *)param)->mouse_y);
	zoom_r = ((t_fractol *)param)->min_real - ((t_fractol *)param)->max_real;
	zoom_i = ((t_fractol *)param)->max_imaginary - \
			((t_fractol *)param)->min_imaginary;
	if (ydelta > 0)
	{
		ft_zoom((t_fractol *)param, 0.5, zoom_r, zoom_i);
	}
	else if (ydelta < 0)
	{
		ft_zoom((t_fractol *)param, 2, zoom_r, zoom_i);
	}
	ft_render((t_fractol *)param);
}
