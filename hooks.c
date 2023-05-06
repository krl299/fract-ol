/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:54 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/06 17:01:30 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Do it while press arrows
static void	ft_arrows(mlx_key_data_t keydata, t_fractol *f, \
		double move_r, double move_i)
{
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
	{
		f->max_real += move_r * 0.1;
		f->min_real += move_r * 0.1;
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
	{
		f->max_real -= move_r * 0.1;
		f->min_real -= move_r * 0.1;
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
	{
		f->max_imaginary += move_i * 0.1;
		f->min_imaginary += move_i * 0.1;
	}
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
	{
		f->max_imaginary -= move_i * 0.1;
		f->min_imaginary -= move_i * 0.1;
	}
	ft_render(f);
}

// Do while press keys
void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	double	move_r;
	double	move_i;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		ft_exit((t_fractol *)param);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE)
	{
		((t_fractol *)param)->color++;
		ft_render((t_fractol *)param);
	}
	else
	{
		move_r = ((t_fractol *)param)->min_real - \
					((t_fractol *)param)->max_real;
		move_i = ((t_fractol *)param)->min_imaginary - \
					((t_fractol *)param)->max_imaginary;
		ft_arrows(keydata, (t_fractol *)param, move_r, move_i);
	}
}
