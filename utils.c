/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:18:10 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/05/03 10:40:11 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
static int	ft_isneg(char *str, int *neg)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		*neg = -1;
		i++;
	}
	return (i);
}

//
double	ft_atod(char *str)
{
	int		i;
	int		neg;
	double	nb;
	double	div;

	nb = 0;
	div = 0.1;
	neg = 1;
	i = ft_isneg(str, &neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (nb * neg);
}

//
int	ft_ishex(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	c = ft_toupper(c);
	if (c >= 'A' && c <= 'F')
		return (c);
	else
		return (0);
}

//
void	ft_exit(t_fractol *f)
{
	if (!f)
		exit(0);
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->ctrl && f->mlx)
		mlx_delete_image(f->mlx, f->ctrl);
	if (f->show && f->mlx)
		mlx_delete_image(f->mlx, f->show);
	if (f->mlx)
		mlx_terminate(f->mlx);
	exit(0);
}

double	ft_module(double r, double i)
{
	return ((r * r) + (i * i));
}
