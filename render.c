/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:39:11 by retahri           #+#    #+#             */
/*   Updated: 2025/03/15 07:34:20 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void pixel2color(t_win *win, int x, int y, int color)
{
    int line_len;
    int pixel_bits;
    int offset;
    
    if (x < 0 || x >= WIDTH || y < 0 || y >= HIGHT)
        return;
    
    line_len = win->image.line_len;
    pixel_bits = win->image.p_bits;
    offset = (y * line_len) + ((pixel_bits / 8) * x);
    *(unsigned int *)(win->image.add + offset) = color;
}

int make_fractal(t_fractal *fract, t_complex *n, int x, double y)
{
	int idx;

	idx = 0;
	if (fract->type == MAND)
		idx = mandelbrot(fract, n);
	return (idx);
}
void render(t_win *win)
{
    static t_complex n;
    t_fractal *fract;
    int idx;
    int x;
    int y;
    
    fract = &win->fractal;
    
    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HIGHT)
        {
            // Calculate the complex coordinates
            n.real = (x / (double)fract->zoom) + fract->off_x;
            n.imag = (y / (double)fract->zoom) + fract->off_y;
            
            // Get iteration count
            idx = mandelbrot(fract, &n);
            
            // Use a more visible color scheme
            int color;
            if (idx < fract->iterations) {
                // Point outside the set - give it a color based on iterations
                color = (idx * 0xFF0000) / fract->iterations; // Reddish gradient
            } else {
                // Point inside the set - black
                color = 0;
            }
            
            pixel2color(win, x, y, color);
            y++;
        }
        x++;
    }
    
    // Put image to window after all pixels are set
    mlx_put_image_to_window(win->mlx, win->window, win->image.img_ptr, 0, 0);
}
