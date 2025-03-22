/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:39:11 by retahri           #+#    #+#             */
/*   Updated: 2025/03/22 02:20:09 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel2color(t_win *win, int x, int y, int color)
{
	int	line_len;
	int	pixel_bits;
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HIGHT)
		return ;
	line_len = win->image.line_len;
	pixel_bits = win->image.p_bits;
	offset = (y * line_len) + ((pixel_bits / 8) * x);
	*(unsigned int *)(win->image.add + offset) = color;
}
int	get_psychedelic_color(int iterations, int max_iterations)
{
	double	ratio;
	int		color_value;

	if (iterations == max_iterations)
		return (0x000000);
	ratio = (double)iterations / max_iterations;
	color_value = (int)(255 * ratio);
	// Ensure value is in proper range
	if (color_value > 255)
		color_value = 255;
	else if (color_value < 0)
		color_value = 0;
	// Using only one color gradient: purple to white
	// Purple component (r and b) increases with iterations
	return ((color_value << 16) | (0 << 8) | color_value);
}

int	make_fractal(t_fractal *fract, t_complex *n, int x, double y)
{
	int	idx;

	idx = 0;
	if (fract->type == MAND)
		idx = mandelbrot(fract, n);
	if (fract->type == JUL)
		idx = julia(fract, n);
	return (idx);
}
void	render(t_win *win)
{
	static t_complex	n;
	t_fractal			*fract;
	int					idx;
	int					x;
	int					y;
	int					color;

	fract = &win->fractal;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HIGHT)
		{
			n.real = ((x - WIDTH / 2.0) / (double)fract->zoom) + fract->off_x;
				// Calculate real part of complex number
			n.imag = ((y - HIGHT / 2.0) / (double)fract->zoom) + fract->off_y;
				// Calculate imaginary part of complex number
			idx = make_fractal(fract, &n, x, y);                              
				// Get iteration count
			color = get_psychedelic_color(idx, fract->iterations);            
				// Use a more visible color scheme
			pixel2color(win, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(win->mlx, win->window, win->image.img_ptr, 0, 0);
}
