/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:17:52 by retahri           #+#    #+#             */
/*   Updated: 2025/03/23 06:29:05 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void launch(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Psychedelic thinker", false);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	render(data, data->max_iter);
	mlx_loop_hook(data->mlx, key_hook, data);
	mlx_scroll_hook(data->mlx, mouse_hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
int main(int ac, char **av)
{
	t_data data;
	
	data = (t_data){0 ,0 ,0 ,0 ,0.5 ,0 ,100 ,0 ,0 ,0 ,255 , 0, 255, 255};
	if (ac < 2)
		return (usage(), 1);
	if (!ft_strncmp(av[1], "mandelbrot",11) && ac == 2)
		data.frac_type = MANDELBROT;
	else if (!ft_strncmp(av[1], "julia",6) && ac == 4)
	{
		data.frac_type = JULIA;
		data.re = ft_atof(av[2]);
		data.im = ft_atof(av[3]);
	}
	else
		return (usage(), 1);
	launch(&data);
	return (0);
}
