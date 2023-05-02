/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:54 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/02 19:18:06 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
void	ft_hook(void *param)
{
	(void)param;
}

//
static void	ft_arrows(mlx_key_data_t keydata, t_fractol *f)
{
	double	move_r;
	double	move_i;

	move_r = f->min_real - f->max_real;
	move_i = f->min_imaginary - f->max_imaginary;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
	{
		f->max_real -= move_r * 0.1;
		f->min_real -= move_r * 0.1;
		ft_render(f);
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
	{
		f->max_real += move_r * 0.1;
		f->min_real += move_r * 0.1;
		ft_render(f);
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
{
		f->max_imaginary -= move_i * 0.1;
		f->min_imaginary -= move_i * 0.1;
		ft_render(f);
	}
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
{
		f->max_imaginary += move_i * 0.1;
		f->min_imaginary += move_i * 0.1;
		ft_render(f);
	}
}

//
void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		exit(0);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		((t_fractol *)param)->color++;
		ft_render((t_fractol *)param);
	}
	else
		ft_arrows(keydata, (t_fractol *)param);
}
