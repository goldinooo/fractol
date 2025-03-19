/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:39:20 by retahri           #+#    #+#             */
/*   Updated: 2025/03/15 03:39:21 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractal(t_win *win)
{
    // Initialize the fractal parameters
    win->fractal.zoom = 250;      // Reasonable initial zoom level
    win->fractal.off_x = -0.75;   // Center the real component (Mandelbrot bulb)
    win->fractal.off_y = 0.0;     // Center the imaginary component
    win->fractal.iterations = 100; // Reasonable starting iteration count
    
    // Other initialization as needed...
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while ((s1[idx] || s2[idx]) && idx < n)
	{
		if ((unsigned char)s1[idx] != (unsigned char)s2[idx])
			return ((unsigned char)s1[idx] - ((unsigned char)s2[idx]));
		idx++;
	}
	return (0);
}

int ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
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
