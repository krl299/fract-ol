/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:29:30 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/04/25 16:19:22 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
void	ft_init_fractol(t_fractol *f)
{
	f->fractal = -1;
	f->color = 0;
	f->color_pattern = 0;
	f->palette = NULL;
	f->min_real = 0;
	f->max_real = 0;
	f->min_imaginary = 0;
	f->max_imaginary = 0;
	f->key_real = 0;
	f->key_imaginary = 0;
	f->mlx = NULL;
	f->img = NULL;
}

/*
static void	ft_complex_layout(t_fractol *f)
{
	if (f->fractal == MANDELBOX)
	{
		f->min_real = -4.0;
		f->max_real = 4.0;
		f->min_imaginary = -4.0;
		f->max_imaginary = f->min_imaginary + (f->max_real - f->min_real) * HEIGHT / WIDTH;
	}
	else if (f->fractal == JULIA)
	{
		f->min_real = -2.0;
		f->max_real = 2.0;
		f->min_imaginary = -2.0;
		f->max_imaginary = f->min_imaginary + (f->max_real - f->min_real) * HEIGHT / WIDTH;
	}
	else
	{
		f->min_real = -2.0;
		f->max_real = 1.0;
		f->max_imaginary = -1.5;
		f->min_imaginary = f->max_imaginary + (f->max_real - f->min_real) * HEIGHT / WIDTH;
	}
}
*/
//
void	ft_start(t_fractol *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "Fract'ol", false);
	if (!f->mlx)
		ft_exit(f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		ft_exit(f);
	mlx_put_string(f->mlx, "FRACT'OL", 200 / 2 - 80, 20);
	mlx_put_string(f->mlx, "Estas son las instrucciones:", 200/2 -80, 40);	
	mlx_image_to_window(f->mlx, f->img, 900, 0);
	mlx_loop_hook(f->mlx, ft_hook, f->mlx);
	mlx_loop(f->mlx);
	mlx_terminate(f->mlx);
}

