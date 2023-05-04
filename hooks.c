/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:54 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/04 11:43:58 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		ft_exit((t_fractol *)param);
	else if (keydata.key == MLX_KEY_C && keydata.action == MLX_RELEASE)
	{
		((t_fractol *)param)->color++;
		ft_render((t_fractol *)param);
	}
	else
		ft_arrows(keydata, (t_fractol *)param);
}

//
static void	ft_zoom(t_fractol *f, double zoom)
{
	double	zoom_r;
	double	zoom_i;

	zoom_r = f->min_real - f->max_real;
	zoom_i = f->max_imaginary - f->min_imaginary;
	printf("%f| %f\n", zoom_r, zoom_i);
	f->max_real += (zoom_r - zoom * zoom_r) / 2;
	f->min_real = f->max_real + zoom * zoom_r;
	f->min_imaginary += (zoom_i - zoom * zoom_i) / 2;
	f->max_imaginary = f->min_imaginary + zoom * zoom_i;

}

//
void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	(void)xdelta;
	int mouse_x, mouse_y;
	mlx_get_mouse_pos(((t_fractol *)param)->mlx, &mouse_x, &mouse_y);
	printf("X:%d|Y:%d\n", mouse_x, mouse_y);
	printf("%f\n", ydelta);
	if (ydelta > 0)
	{
		ft_zoom((t_fractol *)param, 0.5);
	}
	else if (ydelta < 0)
	{
		ft_zoom((t_fractol *)param, 2);
	}
	ft_render((t_fractol *)param);
}
