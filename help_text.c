/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:28:38 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/02 11:12:51 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
static void	ft_fractal_options(void)
{
	ft_printf("\n+------------Available Fractals------------------+\n");
	ft_printf("\tWhich fractal would you like to see?\n");
	ft_printf("\tJulia ==> 'J'/'j'/'1'\n");
	ft_printf("\tMandelbrot ==> 'M'/'m'/'2'\n");
}

static void	ft_color_options(void)
{
	ft_printf("\n+------------Available Colors--------------------+\n");
	ft_printf("Pick a display color providing a hexadecimal code.\n");
	ft_printf("The hex color code must be formatted as RRGGBB:\n");
	ft_printf("\tWhite:\tFFFFFF\tBlack:\t000000\n");
	ft_printf("\tRed:\tFF0000\tBlue:\t0000FF\n");
	ft_printf("\tGreen:\t00FF00\tYellow:\tFFFF00\n");
}

void	ft_help_txt(t_fractol *f)
{
	ft_printf("\n+------------------------------------------------+\n");
	ft_printf("\n|                  FRACT'OL                      |\n");
	ft_printf("\n+------------------------------------------------+\n");
	ft_fractal_options();
	ft_color_options();
	ft_printf("\nExample ==> ./fractol <fractal> <keys> <color>");
	ft_printf("\n+------------------------------------------------+\n");
	ft_exit(f);
}

//
static void	ft_background(t_fractol *f, int height)
{
	int	x;
	int	y;
	int	z;

	x = -1;
	y = -1;
	z = 0 << 24 | 0 << 16 | 0 << 8 | 255;
	while (++y < height)
	{
		while (++x < W_CTRL)
			mlx_put_pixel(f->ctrl, x, y, z);
		x = -1;
	}
	mlx_image_to_window(f->mlx, f->ctrl, 0, 0);
}

//
void	ft_print_controls(t_fractol *f)
{
	int	cont;

	cont = 1;
	ft_background(f, HEIGHT);
	mlx_put_string(f->mlx, "CONTROLS", 40, 20);
	mlx_put_string(f->mlx, "________", 40, 21);
	mlx_put_string(f->mlx, "Move:	Use arrows to move the view.", 40, (++cont) * 30);
	mlx_put_string(f->mlx, "Zoom:	+/- to zoom in or out.", 40, ++cont * 30);
	mlx_put_string(f->mlx, "		you can use mouse scroll too.", 40, ++cont * 30);
	mlx_put_string(f->mlx, "Iteracts:", 40, ++cont * 30);
	mlx_put_string(f->mlx, "* to icnrease the iterations.", 40, ++cont * 30);
	mlx_put_string(f->mlx, "/ to decrease the iterations.", 40, ++cont * 30);
	mlx_put_string(f->mlx, "Exit:	ESC", 40, ++cont * 30);
}
