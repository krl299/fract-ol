/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:54 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/04 18:46:41 by cmoran-l         ###   ########.fr       */
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
		f->max_real += move_r * 0.1;
		f->min_real += move_r * 0.1;
		ft_render(f);
	}
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
	{
		f->max_real -= move_r * 0.1;
		f->min_real -= move_r * 0.1;
		ft_render(f);
	}
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
{
		f->max_imaginary += move_i * 0.1;
		f->min_imaginary += move_i * 0.1;
		ft_render(f);
	}
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
{
		f->max_imaginary -= move_i * 0.1;
		f->min_imaginary -= move_i * 0.1;
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
//static void	ft_zoom_mouse(t_fractol *f, double zoom_r, double zoom_i, double percent)
//{
//
//}

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
static void	ft_zoom(t_fractol *f, double zoom, int x, int y)
{
	double	zoom_r;
	double	zoom_i;
//	double	percent_x;
//	double	percent_y;

	zoom_r = f->min_real - f->max_real;
	zoom_i = f->max_imaginary - f->min_imaginary;
	f->max_real += (zoom_r - zoom * zoom_r) / 2;
	f->min_real = f->max_real + zoom * zoom_r;
	f->min_imaginary += (zoom_i - zoom * zoom_i) / 2;
	f->max_imaginary = f->min_imaginary + zoom * zoom_i;
	printf("%f\n", ft_percent(950, x));
	double	percent = ft_percent(950, x);
	if(x > 500)
	{
		if (x < 950)
		{
			f->max_real += zoom_r * percent;
			f->min_real += zoom_r * percent;
		}
		else
		{
			f->max_real -= zoom_r * percent;
			f->min_real -= zoom_r * percent;
		}
		percent = ft_percent(350, y);
		if (y < 350)
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
}

//
void	ft_scroll_hook(double xdelta, double ydelta, void *param)
{
	(void)xdelta;
	int mouse_x, mouse_y;
	mlx_get_mouse_pos(((t_fractol *)param)->mlx, &mouse_x, &mouse_y);
//	printf("X:%d|Y:%d\n", mouse_x, mouse_y);
//	printf("%f\n", ydelta);
	if (ydelta > 0)
	{
		ft_zoom((t_fractol *)param, 0.5, mouse_x, mouse_y);
	}
	else if (ydelta < 0)
	{
		ft_zoom((t_fractol *)param, 2, mouse_x, mouse_y);
	}
	ft_render((t_fractol *)param);
}
