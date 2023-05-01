/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:10:15 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/01 16:33:17 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
void	ft_render(t_fractol *f)
{
	if (f->fractal == JULIA)
		ft_julia(f);
	else if (f->fractal == MANDELBROT)
		ft_mandelbrot(f);
	else if (f->fractal == MANDELBOX)
		ft_mandelbox(f);
	mlx_image_to_window(f->mlx, f->show, 0, 0);
}

//
void	ft_julia(t_fractol *f)
{
	int		iterations;
	double	tmp_r;

	f->screen_y = 0;
	iterations = 0;
	while (f->screen_y < HEIGHT)
	{
		f->screen_x = 0;
		while (f->screen_x < WIDTH)
		{
			ft_calc_complex_plane_julia(f);
			f->z_r = 0;
			f->z_i = 0;
			while (++iterations < MAX_ITERATIONS && ft_module(f->z_r, f->z_i) < 4)
			{
				tmp_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
				f->z_i = 2 * f->z_r * f->z_i + f->c_i;
				f->z_r = tmp_r;
			}
			mlx_put_pixel(f->show, f->screen_x, f->screen_y, 0);
			f->screen_x++;
		}
		f->screen_y++;
	}
}

//
void	ft_mandelbox(t_fractol *f)
{
	(void)f;
}

//
void	ft_mandelbrot(t_fractol *f)
{
	int		iterations;
	double	tmp_r;

	f->screen_y = 0;
	iterations = 0;
	while (f->screen_y < HEIGHT)
	{
		f->screen_x = 0;
		while (f->screen_x < WIDTH)
		{
			ft_calc_complex_plane(f);
			f->z_r = 0;
			f->z_i = 0;
			while (++iterations < MAX_ITERATIONS && ft_module(f->z_r, f->z_i) < 4)
			{
				tmp_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
				f->z_i = 2 * f->z_r * f->z_i + f->c_i;
				f->z_r = tmp_r;
			}
			mlx_put_pixel(f->show, f->screen_x, f->screen_y, 0);
			f->screen_x++;
		}
		f->screen_y++;
	}
}
