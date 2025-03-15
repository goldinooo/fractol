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


int main(int ac, char **av)
{
	t_win window;
	launch(&window, av[1]);
	render(&window);
	mlx_loop(window.mlx);
	return (0);
}