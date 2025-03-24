/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:17:48 by retahri           #+#    #+#             */
/*   Updated: 2025/03/23 06:35:53 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	ft_putstr_fd("./fractol <type> [real imaginary]\n"\
	"\t<type>: mandelbrot | julia\n"\
	"\t[real imaginary]: Optional values for Julia\n", 2);
}

int	mandelbrot(double real, double img, int max_iter)
{
	double r;
	double i;
	int			idx;
	double		tmp;

	r = 0.0;
	i = 0.0;
	idx = 0;
	while ((r * r + i * i) <= 4 && idx < max_iter)
	{
		tmp = r * r - i * i + real;
		i = 2.0 * r * i + img;
		r = tmp;
		idx++;
	}
	return (idx);
}
// int julia(t_complex n, t_complex o, int max_iter)
// {
// 	int idx;
// 	double tmp;
	
// 	idx = 0;
// 	while (n.real * n.real + n.imag * n.real <= 4 && idx < max_iter)
// 	{
// 		tmp = n.real * n.real + n.imag * n.imag + o.real;
// 		n.imag = 2.0 * n.real * n.imag + o.imag;
// 		n.real = tmp;
// 		idx++;
// 	}
// 	return (idx);
// }
int	julia(t_complex n, t_complex o, int max_iter)
{
	int			idx;
	double		temp;

	idx = 0;
	while ((n.real * n.real + n.imag * n.imag) < 4 && idx < max_iter)
	{
		/* n = n² + c where c is the Julia parameter */
		temp = n.real * n.real - n.imag * n.imag + o.real;
		n.imag = 2.0 * n.real * n.imag + o.imag;
		n.real = temp;
		idx++;
	}
	return (idx);
}