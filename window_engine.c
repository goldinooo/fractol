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
#include "minilibx_opengl_20191021/mlx.h"

void declare_type(t_win *win, char *s)
{
	int len;
	if (!win || !s)
		return;
	len = ft_strlen(s);
	if (ft_strncmp(s, "mandelbrot", len) == 0)
		win->fractal.type = MAND;
}

void reset_win(t_win *win, int frac_type)
{
	if (!win)
		return;
	win->fractal.type = frac_type;
	win->fractal.color = 256;
	win->fractal.is_julia = false;
	win->fractal.mouse_x = 0;
	win->fractal.mouse_y = 0;
	win->fractal.off_x = -2;
	win->fractal.off_y = -2;
	win->fractal.iterations = 256;
	win->fractal.zoom = 400 / 4;
}
void launch(t_win *win, char *av)
{
	int p_b;
	int line_len;
	int endian;
	if (!win || !av)
		return;
	reset_win(win, MAND);
	declare_type(win, av);
	win->mlx = mlx_init();
	if (!win->mlx)
		error_message("Wrong fractal :)\n", 1);
	win->window = mlx_new_window(win->mlx, HIGHT, WIDTH, "psychedelic Thinker");
	win->image.img_ptr = mlx_new_image(win->mlx, WIDTH, HIGHT);
	if (!win->window || !win->image.img_ptr)
	{
		mlx_destroy_image(win->mlx, win->image.img_ptr);
		mlx_destroy_window(win->mlx, win->window);
		error_message("MLX ERROR can't create the object\n", 1);
	}
	win->image.add = mlx_get_data_addr(win->image.img_ptr, &win->image.p_bits, \
							 &win->image.line_len, &win->image.endian);

}