/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:39:15 by retahri           #+#    #+#             */
/*   Updated: 2025/03/20 02:13:56 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void declare_type(t_win *win, char *s)
{
	int len;
	if (!win || !s)
		return;
	len = ft_strlen(s);
	if (ft_strncmp(s, "mandelbrot", len) == 0)
		win->fractal.type = MAND;
	else if (ft_strncmp(s, "julia", len) == 0)
		win->fractal.type = JUL;
	else
		error_message("Wrong fractal :)\n", 1);
}

void reset_win(t_win *win, int frac_type)
{
    if (!win)
        return;
    win->fractal.type = frac_type;
    win->fractal.color = 256;
    win->fractal.zoom = 250;
    if (frac_type == JUL)
    {
        win->fractal.is_julia = true;
        win->fractal.n.real = -0.8;    // Classic Julia parameter
        win->fractal.n.imag = 0.156;   // Classic Julia parameter
        win->fractal.iterations = 200;  // Higher iterations for detail
        win->fractal.off_x = 0.0;       // Center Julia at origin
        win->fractal.off_y = 0.0;       // Center Julia at origin
    }
    else // MAND
    {
        win->fractal.is_julia = false;
        win->fractal.n.real = 0;
        win->fractal.n.imag = 0;
        win->fractal.iterations = 200;
        win->fractal.off_x = -0.75;     // Center Mandelbrot at main bulb
        win->fractal.off_y = 0.0;
    }
}

void launch(t_win *win, char *av)
{
    int fractal_type;
    int len;
	
    if (!win || !av)
        return;
	len = ft_strlen(av); 
    if (ft_strncmp(av, "mandelbrot", len) == 0)
        fractal_type = MAND;
    else if (ft_strncmp(av, "julia", len) == 0)
        fractal_type = JUL;
    else
        error_message("Wrong fractal :)\n", 1);
    reset_win(win, fractal_type);
    if (!(win->mlx = mlx_init()))
        error_message("Failed to build mlx :)\n", 1);
    if (!(win->window = mlx_new_window(win->mlx, WIDTH, HIGHT, "psychedelic Thinker")))
        clearup(win);
    if (!(win->image.img_ptr = mlx_new_image(win->mlx, WIDTH, HIGHT)))
        clearup(win);
    win->image.add = mlx_get_data_addr(win->image.img_ptr, &win->image.p_bits, \
                             &win->image.line_len, &win->image.endian);
}
