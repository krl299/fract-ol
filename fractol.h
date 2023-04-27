/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:22:46 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/04/27 18:43:31 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <math.h>
# include <stdio.h>
// DIMENSIONS
# define WIDTH 900
# define HEIGHT 900
# define W_CTRL 500
# define W_SHOW 250
# define MAX_ITERATIONS 60
//FRACTALS
# define JULIA 1
# define MANDELBROT 2
# define MANDELBOX 3

typedef struct	s_fractol
{
	char	fractal;
	int		color;
	int		color_pattern;
	int		*palette;
	double	min_real;
	double	max_real;
	double	min_imaginary;
	double	max_imaginary;
	double	key_real;
	double	key_imaginary;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	mlx_t	*mlx;
	mlx_image_t	*img;
	mlx_image_t	*ctrl;
	mlx_image_t	*show;
	int		screen_x;
	int		screen_y;
}	t_fractol;

void	ft_help_txt(t_fractol *f);
void	ft_init_fractol(t_fractol *f);
//void	ft_set_color(t_fractol *f, int argc, char **argv);
void	ft_start(t_fractol *f);
void	ft_render(t_fractol *f);
void	ft_color(t_fractol *f);
void	ft_hook(void *param);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_scroll_hook(double xdelta, double ydelta, void *param);
void	ft_print_controls(t_fractol *f);

//Fractals
void	ft_julia(t_fractol *f);
void	ft_mandelbrot(t_fractol *f);
void	ft_mandelbox(t_fractol *f);

//MATHS
void	ft_calc_complex_plane(t_fractol *f);

// UTILS
double	ft_atod(char *str);
int		ft_ishex(int c);
void	ft_exit(t_fractol *f);
double	ft_module(double r, double i);
#endif
