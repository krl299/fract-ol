/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:28:38 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/04/21 09:58:55 by cmoran-l         ###   ########.fr       */
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

void	ft_help_txt(void)
{
	ft_printf("\n+------------------------------------------------+\n");
	ft_printf("\n|                  FRACT'OL                      |\n");
	ft_printf("\n+------------------------------------------------+\n");
	ft_fractal_options();
	ft_color_options();
	ft_printf("\nExample ==> ./fractol <fractal> <keys> <color>");
	ft_printf("\n+------------------------------------------------+\n");
	exit(2);
}
