/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:29:51 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/04/18 19:06:50 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
static void	ft_help_text(void)
{
	ft_printf("\n+-----------------------------------------------------------------------+\n");
	ft_printf("\n|				FRACT'OL				|\n");
	ft_printf("\n+-----------------------------------------------------------------------+\n");

}

//
int main(int argc, char *argv[])
{
	(void)argv;
	if (argc < 2)
		ft_help_text();
	return (0);
}