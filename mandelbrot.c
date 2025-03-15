/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:16:45 by retahri           #+#    #+#             */
/*   Updated: 2025/03/15 05:43:25 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_fractal *fractal, t_complex *n)
{
	t_complex x;
	int idx;
	double tmp;
	
	x.imag = 0.0;
	x.real = 0.0;
	idx = 0;
	while ((x.real * x.real + x.imag * x.imag) < 4 && idx < fractal->iterations)
	{
		if ((x.real * x.real+ x.imag * x.imag) > 4.0)
			break;
		tmp = x.real * x.real - x.imag * x.imag + n->real;
		x.imag = 2.0 * x.real * x.imag + n->imag;
		x.real = tmp;
		idx++;
	}
	return (idx);
}