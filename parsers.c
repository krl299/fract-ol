/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:02:38 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/04/21 10:45:43 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
static int	ft_set_hexcolor(/*t_fractol *f,*/ char *color)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (color[i] && ft_ishex(color[i]))
	{
		if (ft_isdigit(color[i]))
			nb = (nb * 16) + (color[i] - '0');
		else
			nb = (nb * 16) + (ft_toupper(color[i]) - 'A' + 10);
		i++;
	}
	if (i == 6 && !color[i])
		return (nb);
	else
		ft_help_txt();
	return (-1);
}


//
void	ft_set_color(t_fractol *f, int argc, char **argv)
{
	if (f->fractal == JULIA && argc == 5)
		f->color = ft_set_hexcolor(argv[4]);
	else if (f->fractal != JULIA && argc == 3)
		f->color = ft_set_hexcolor(argv[3]);
	if (argc == 2 || (f->fractal == JULIA && argc == 4))
		f->color = 0x9966FF;
}
