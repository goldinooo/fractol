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
int get_psychedelic_color(int iterations, int max_iterations)
{
    // Points inside the set are black
    if (iterations == max_iterations)
        return (0x000000);
    
    double ratio = (double)iterations / max_iterations;
    int r, g, b;
    
    // Better color distribution:
    if (ratio < 0.25) {
        // Dark blue to medium blue
        r = 0;
        g = 0;
        b = 50 + 150 * (ratio/0.25);
    } else if (ratio < 0.5) {
        // Medium blue to purple
        r = 100 * ((ratio-0.25)/0.25);
        g = 0;
        b = 200;
    } else if (ratio < 0.75) {
        // Purple to red
        r = 100 + 155 * ((ratio-0.5)/0.25);
        g = 0;
        b = 200 - 200 * ((ratio-0.5)/0.25);
    } else {
        // Red to yellow
        r = 255;
        g = 255 * ((ratio-0.75)/0.25);
        b = 0;
    }
    
    // Range check
    r = (r > 255) ? 255 : (r < 0) ? 0 : r;
    g = (g > 255) ? 255 : (g < 0) ? 0 : g;
    b = (b > 255) ? 255 : (b < 0) ? 0 : b;
    
    return ((r << 16) | (g << 8) | b);
}
int make_fractal(t_fractal *fract, t_complex *n, int x, double y)
{
	int idx;

	idx = 0;
	if (fract->type == MAND)
		idx = mandelbrot(fract, n);
    if (fract->type == JUL)
        idx = julia(fract, n);
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
            // Calculate the complex coordinates using the same coordinate system as mouse_hooks
            n.real = ((x - WIDTH / 2.0) / (double)fract->zoom) + fract->off_x;
            n.imag = ((y - HIGHT / 2.0) / (double)fract->zoom) + fract->off_y;
            
            // Get iteration count
            idx = make_fractal(fract, &n, x, y);
            
            // Use a more visible color scheme
            int color = get_psychedelic_color(idx, fract->iterations);
            pixel2color(win, x, y, color);
            y++;
        }
        x++;
    }
    
    // Put image to window after all pixels are set
    mlx_put_image_to_window(win->mlx, win->window, win->image.img_ptr, 0, 0);
}

// This code should be placed wherever you initialize the fractal parameters
// Typically in your main function or init_fractal function

void init_fractal(t_win *win)
{
    // Initialize the fractal parameters
    win->fractal.zoom = 250;      // Reasonable initial zoom level
    win->fractal.off_x = -0.75;   // Center the real component (Mandelbrot bulb)
    win->fractal.off_y = 0.0;     // Center the imaginary component
    win->fractal.iterations = 100; // Reasonable starting iteration count
    
    // Other initialization as needed...
}
