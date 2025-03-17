/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:39:15 by retahri           #+#    #+#             */
/*   Updated: 2025/03/15 07:27:23 by retahri          ###   ########.fr       */
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
    
    // Set common parameters
    win->fractal.color = 256;
    win->fractal.off_x = -0.75;
    win->fractal.off_y = 0.0;
    win->fractal.zoom = 250;
    
    // Handle fractal-specific settings
    if (frac_type == JUL)
    {
        win->fractal.is_julia = true;
        win->fractal.mouse_x = -0.8;  // Classic Julia parameter
        win->fractal.mouse_y = 0.156; // Classic Julia parameter
        win->fractal.iterations = 200; // Higher iterations for Julia
    }
    else // MAND
    {
        win->fractal.is_julia = false;
        win->fractal.mouse_x = 0;
        win->fractal.mouse_y = 0;
        win->fractal.iterations = 100;
    }
    
    printf("Initialized %s with: zoom=%f, offset=(%f,%f)\n",
           (frac_type == JUL) ? "Julia" : "Mandelbrot",
           (double)win->fractal.zoom, win->fractal.off_x, win->fractal.off_y);
    
    if (frac_type == JUL)
        printf("Julia params: c = %.4f + %.4fi\n", win->fractal.mouse_x, win->fractal.mouse_y);
}

void launch(t_win *win, char *av)
{
    if (!win || !av)
        return;
    
    // First determine the fractal type
    int fractal_type = MAND;  // Default
    int len = ft_strlen(av);
    if (ft_strncmp(av, "mandelbrot", len) == 0)
        fractal_type = MAND;
    else if (ft_strncmp(av, "julia", len) == 0)
        fractal_type = JUL;
    else
        error_message("Wrong fractal :)\n", 1);
    
    // Then reset with the correct type
    reset_win(win, fractal_type);
    
    // Parse additional parameters if provided (for Julia)
    // This would need additional code to handle command-line parameters
    
    // Rest of your window setup
    win->mlx = mlx_init();
    if (!win->mlx)
        error_message("Wrong fractal :)\n", 1);
    win->window = mlx_new_window(win->mlx, WIDTH, HIGHT, "psychedelic Thinker");
    if (!win->window)
    {
        mlx_destroy_display(win->mlx);
        free(win->mlx);
        error_message("MLX ERROR can't create the object\n", 1);
    }
    win->image.img_ptr = mlx_new_image(win->mlx, WIDTH, HIGHT);
    if (!win->image.img_ptr)
    {
        mlx_destroy_window(win->mlx, win->window);
        mlx_destroy_display(win->mlx);
        free(win->mlx);
        error_message("MLX ERROR can't create the object\n", 1);
    }
    win->image.add = mlx_get_data_addr(win->image.img_ptr, &win->image.p_bits, \
                             &win->image.line_len, &win->image.endian);
}
