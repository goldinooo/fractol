/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:39:28 by retahri           #+#    #+#             */
/*   Updated: 2025/03/15 06:28:05 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int close_window(void *param)
{
    exit(0);
    return (0);
}

int main(int ac, char **av)
{
    t_win window;
    
    if (ac < 2)
        error_message("Usage: ./fractol [mandelbrot|julia] [julia_real julia_imag]\n", 1);
    
    // Initialize with default parameters first
    launch(&window, av[1]);
    
    // Set Julia parameters if provided
    if (ac >= 4 && window.fractal.type == JUL) {
        // Convert string parameters to double (use your ft_atof)
        window.fractal.mouse_x = ft_atof(av[2]);
        window.fractal.mouse_y = ft_atof(av[3]);
        
        // Debug print AFTER setting parameters
        printf("Updated Julia params: c = %.4f + %.4fi\n", 
               window.fractal.mouse_x, window.fractal.mouse_y);
    }
    
    // Continue with rendering and hook setup
    render(&window);
    mlx_key_hook(window.window, key_hooks, &window);
    mlx_mouse_hook(window.window, mouse_hooks, &window);
    mlx_hook(window.window, 17, 0, close_window, NULL);
    mlx_hook(window.window, 6, 0, hook_jul, &window);
    mlx_loop(window.mlx);
    return (0);
}