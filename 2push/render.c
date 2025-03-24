/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:17:50 by retahri           #+#    #+#             */
/*   Updated: 2025/03/24 04:08:26 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_psychedelic(t_data *frac, int iterations, int max_iterations)
{
	double	ratio;
	int		r;
	int 	g;
	int		b;
	int color_period;

	color_period = max_iterations / 2;
	ratio = (double)iterations / max_iterations;
	// r = (int)(ratio * frac->r);
	// g = (int)(ratio * frac->g);
	// b = (int)(ratio * frac->b);

	r = (iterations % color_period) * 255 / color_period;
	g = ((iterations + color_period/3) % color_period) * 255 / color_period;
	b = ((iterations + color_period*2/3) % color_period) * 255 / color_period;
	
	// Apply user color preferences
	r = r * frac->r / 255;
	g = g * frac->g / 255;
	b = b * frac->b / 255;
	return (r << 24 | g << 16 | b << 8 | frac->a);
}
void pixel2color(t_data *data, t_complex n, t_col *color, int max_iter)
{
	int idx;
	
	idx = 0;
	if (data->frac_type == MANDELBROT)
		idx = mandelbrot(n.real, n.imag, max_iter);
	else if (data->frac_type == JULIA)
		idx = julia(n , (t_complex){data->re , data->im}, max_iter);
	if (idx == max_iter)
		color->color = 0x000000FF;
	else
		color->color = get_psychedelic(data, idx, max_iter);
	mlx_put_pixel(data->image, color->x, color->y, color->color);
}
t_complex fractal(t_col *col , t_data *data)
{
	t_complex n;

	n.real = (col->x - HEIGHT / 2.0) / (0.5 * data->zoom * HEIGHT) + data->off_x;
	n.imag = (col->y - WIDTH / 2.0) / (0.5 * data->zoom * WIDTH) + data->off_y; 
	return (n);
}
void render(t_data *data, int max_iter)
{
	t_col color;
	t_complex n;
	
	color.y = 0;
	while (color.y < HEIGHT)
	{
		color.x = 0;
		while (color.x < WIDTH)
		{
			n = fractal(&color, data);
			pixel2color(data, n, &color,  max_iter);
			color.x++;
		}
		color.y++;
	}
}
