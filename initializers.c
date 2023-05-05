/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:29:30 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/05 11:57:24 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
void	ft_init_fractol(t_fractol *f)
{
	f->fractal = -1;
	f->color = 0;
	f->min_real = 0;
	f->max_real = 0;
	f->min_imaginary = 0;
	f->max_imaginary = 0;
	f->key_real = 0;
	f->key_imaginary = 0;
	f->z_r = 0;
	f->z_i = 0;
	f->c_r = 0;
	f->c_i = 0;
	f->mlx = NULL;
	f->img = NULL;
	f->ctrl = NULL;
	f->show = NULL;
}

//
void	ft_start(t_fractol *f)
{
	f->mlx = mlx_init(W_CTRL + W_SHOW, HEIGHT, "Fract'ol", false);
	if (!f->mlx)
		ft_exit(f);
	f->img = mlx_new_image(f->mlx, W_CTRL + W_SHOW, HEIGHT);
	if (!f->img)
		ft_exit(f);
	f->ctrl = mlx_new_image(f->mlx, W_CTRL, HEIGHT);
	if (!f->ctrl)
		ft_exit(f);
	f->show = mlx_new_image(f->mlx, W_SHOW, HEIGHT);
	if (!f->show)
		ft_exit(f);
	ft_print_controls(f);
	ft_render(f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	mlx_key_hook(f->mlx, ft_key_hook, f);
	mlx_scroll_hook(f->mlx, ft_scroll_hook, f);
	mlx_loop(f->mlx);
}
