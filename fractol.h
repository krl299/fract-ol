/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:22:46 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/04/21 11:57:10 by cmoran-l         ###   ########.fr       */
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
# define MAX_ITERATIONS 60
//FRACTALS
# define JULIA 1
# define MANDELBROT 2
# define MANDELBOX 3
//KEYS
# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32
# define KEY_ONE 49
# define KEY_TWO 50
# define KEY_THREE 51
# define KEY_FOUR 52
# define KEY_FIVE 53
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_BTN 3
# define MOUSE_BTN 1
# define MOUSE_BTN_2 3
# define KEY_K 107

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
	void	*mlx;
	void	*win;
	void	*img;
	void	*buff;
}	t_fractol;

void	ft_help_txt();
void	ft_init_fractol(t_fractol *f);
//vo t_fd	ft_check_args(t_fr, t_fractol *f, char **argv);
void	ft_set_color(t_fractol *f, int argc, char **argv);
void	ft_start(t_fractol *f);
void	ft_render(t_fractol *f);
void	ft_print_controls();

// UTILS
double	ft_atod(char *str);
int		ft_ishex(int c);
#endif
