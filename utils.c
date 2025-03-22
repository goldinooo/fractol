/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:39:20 by retahri           #+#    #+#             */
/*   Updated: 2025/03/21 00:22:27 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(char *text, int mode)
{
	if (mode == 0)
		perror(text);
	else if (text)
		ft_putstr(text);
	exit(EXIT_FAILURE);
}
static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
static int	skip(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}
double ft_atof(char *s)
{
    int i;
    int sign;
    double result;
    double fraction;

    sign = 1;
    fraction = 0.1;
    result = 0;
    i = skip(s, &sign);
    while(s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10 + (s[i] - '0');
        i++;
    }
    if (s[i] == '.')
    {
        i++;
        while(s[i] >= '0' && s[i] <= '9')
        {
            result = result + (s[i] - '0') * fraction;
            fraction /= 10;
            i++;
        }
    }
    return (result * sign);
}
void clearup(t_win *win)
{
    if (!win)
        return;
    if (win->image.img_ptr)
        mlx_destroy_image(win->mlx, win->image.img_ptr);
    if (win->window)
        mlx_destroy_window(win->mlx, win->window);
    if (win->mlx)
        free(win->mlx);
	exit(0);
}