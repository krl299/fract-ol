/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:2:51 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/04 19:41:58 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Set fractal to deploy
static void	ft_set_fractal(t_fractol *f, char **argv)
{
	if ((argv[1][0] == 'J' || argv[1][0] == 'j' || argv[1][0] == '1') \
			&& argv[1][1] == '\0')
	{
		f->fractal = JULIA;
	}
	else if ((argv[1][0] == 'M' || argv[1][0] == 'm' || argv[1][0] == '2') \
			&& argv[1][1] == '\0')
	{
		f->fractal = MANDELBROT;
	}
	else if ((argv[1][0] == 'X' || argv[1][0] == 'x' || argv[1][0] == '3') \
			&& argv[1][1] == '\0')
	{
		f->fractal = MANDELBOX;
	}
	else
		ft_help_txt(f);
}

// Set key values
void	ft_set_key_values(t_fractol *f, int argc, char **argv)
{
	if (f->fractal != JULIA || argc == 2)
	{
		f->key_real = -0.766667;
		f->key_imaginary = -0.090000;
		return ;
	}
	if (argc == 3)
		ft_help_txt(f);
	if (!ft_strchr(argv[2], '.'))
		ft_help_txt(f);
	if (!ft_strchr(argv[3], '.'))
		ft_help_txt(f);
	f->key_real = ft_atod(argv[2]);
	f->key_imaginary = ft_atod(argv[3]);
	if (f->key_real > 2.0 || f->key_real < -2.0)
		ft_help_txt(f);
	if (f->key_imaginary >= 2.0 || f->key_imaginary <= -2.0)
		ft_help_txt(f);
}

//
static void	ft_set_complex_layout(t_fractol *f)
{
	if (f->fractal == JULIA)
	{
		f->min_real = -1.7;
		f->max_real = 1.7;
		f->min_imaginary = -1.2;
		f->max_imaginary = f->min_imaginary + (f->max_real - f->min_real) \
							* HEIGHT / WIDTH;
	}
	else if (f->fractal == MANDELBOX)
	{
		f->min_real = -4.0;
		f->max_real = 4.0;
		f->min_imaginary = -4.0;
		f->max_imaginary = f->min_imaginary + (f->max_real - f->min_real) \
							* HEIGHT / WIDTH;
	}
	else
	{
		f->min_real = -2.0;
		f->max_real = 1.0;
		f->max_imaginary = -1.0;
		f->min_imaginary = 1.0;
	}
}

// Check arguments and set fractal requirements
static void	ft_check_args(t_fractol *f, int argc, char **argv)
{
	ft_set_fractal(f, argv);
	if (f->fractal != JULIA && argc > 3)
		ft_help_txt(f);
	else if (f->fractal == JULIA && argc > 5)
		ft_help_txt(f);
	ft_set_key_values(f, argc, argv);
	ft_set_complex_layout(f);
}

// 
int	main(int argc, char *argv[])
{
	t_fractol	f;

	if (argc < 2)
		ft_help_txt(&f);
	ft_init_fractol(&f);
	ft_check_args(&f, argc, argv);
	ft_start(&f);
}
