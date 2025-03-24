/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:17:55 by retahri           #+#    #+#             */
/*   Updated: 2025/03/24 03:08:23 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mouse_hook(double m_x, double m_y, void *param)
{
	t_data *data;
	
	data = param;
	(void)m_x;
	if (m_y > 0)
		data->zoom *= 1.1;
	if (m_y < 0)
		data->zoom *= 0.9;
	render(data, data->max_iter);
}
void key_hook(void *param)
{
	t_data *data;
	
	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}