/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:10:15 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/02 18:22:41 by cmoran-l         ###   ########.fr       */
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
	mlx_image_to_window(f->mlx, f->show, W_CTRL, 0);
}

//
void	ft_julia(t_fractol *f)
{
	int		iterations;
	double	tmp_r;

	f->screen_y = 0;
	while (f->screen_y < HEIGHT)
	{
		f->screen_x = 0;
		while (f->screen_x < W_SHOW)
		{
			ft_calc_complex_plane_julia(f);
			f->c_r = f->key_real;
			f->c_i = f->key_imaginary;
			iterations = 0;
			while (++iterations < MAX_ITERATIONS && ft_module(f->z_r, f->z_i) < 4)
			{
				tmp_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
				f->z_i = 2 * f->z_r * f->z_i + f->c_i;
				f->z_r = tmp_r;
			}
			mlx_put_pixel(f->show, f->screen_x, f->screen_y, ft_color(f->color, iterations));
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
	while (f->screen_y < HEIGHT)
	{
		f->screen_x = 0;
		while (f->screen_x < W_SHOW)
		{
			ft_calc_complex_plane(f);
			f->z_r = f->key_real;
			f->z_i = f->key_imaginary;
			iterations = 0;
			while (iterations < MAX_ITERATIONS && (ft_module(f->z_r, f->z_i) < 4))
			{
				tmp_r = (f->z_r * f->z_r) - (f->z_i * f->z_i) + f->c_r;
				f->z_i = 2 * f->z_r * f->z_i + f->c_i;
				f->z_r = tmp_r;
				iterations++;
			}
			if (iterations == 0)
				iterations = 1;
			mlx_put_pixel(f->show, f->screen_x, f->screen_y, ft_color(f->color, iterations));
			f->screen_x++;
		}
		f->screen_y++;
	}
}

//
int	ft_color(int color, int iterations)
{
	int	color_kit[5];

	color_kit[0] = 0x1932c2ff;
	color_kit[1] = 0x8a601dff;
	color_kit[2] = 0x80ff80ff;
	color_kit[3] = 0x0fd697ff;
	color_kit[4] = 0xd9331aff;
	if (iterations >= MAX_ITERATIONS - 1)
		return (0x000000ff);
	else
		return (color_kit[(color % 5)] + (iterations * 0x03030000));
}
