/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:37:09 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/06 16:51:05 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Transforms the cartesian coordinates to the complex plane
void	ft_calc_complex_plane(t_fractol *f)
{
	f->c_r = f->min_real + f->screen_x * (f->max_real - f->min_real) \
			/ (W_SHOW - 1);
	f->c_i = f->max_imaginary - f->screen_y * (f->max_imaginary - \
			f->min_imaginary) / (HEIGHT - 1);
}

// Transforms the cartesian coordinates to the complex plane for Julia fractal
void	ft_calc_complex_plane_julia(t_fractol *f)
{
	f->z_r = f->min_real + f->screen_x * (f->max_real - f->min_real) \
			/ (W_SHOW - 1);
	f->z_i = f->max_imaginary - f->screen_y * (f->max_imaginary - \
			f->min_imaginary) / (HEIGHT - 1);
}
