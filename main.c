/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:39:28 by retahri           #+#    #+#             */
/*   Updated: 2025/03/20 23:25:46 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int close_window(void *param)
{
    t_win *win = (t_win *)param;
    clearup(win); // Ensure cleanup before exiting
    exit(0);
}

int main(int ac, char **av)
{
    t_win window;
    
    if (ac < 2)
        error_message("Usage: ./fractol [mandelbrot|julia] [julia_real julia_imag]\n", 1);
    launch(&window, av[1]);
    if (ac >= 4 && window.fractal.type == JUL)
    {
        window.fractal.n.real = ft_atof(av[2]);
        window.fractal.n.imag = ft_atof(av[3]);
    }
    render(&window);
    mlx_key_hook(window.window, key_hooks, &window);
    mlx_mouse_hook(window.window, mouse_hooks, &window);
    mlx_hook(window.window, 17, 0, close_window, NULL);
    mlx_loop(window.mlx);
    return (0);
}
