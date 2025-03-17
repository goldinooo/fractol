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

double ft_atof(char *s)
{
    double res = 0.0;
    double fraction = 0.0;
    double divider = 1.0;
    int sign = 1;
    int decimal_found = 0;
    
    // Skip whitespace
    while (ft_isspace(*s))
        s++;
    
    // Handle sign
    if (*s == '-' || *s == '+')
    {
        sign = (*s == '-') ? -1 : 1;
        s++;
    }
    
    // Process digits
    while (*s)
    {
        if (*s >= '0' && *s <= '9')
        {
            if (!decimal_found)
                res = res * 10 + (*s - '0');
            else
            {
                divider *= 10;
                fraction = fraction + (double)(*s - '0') / divider;
            }
        }
        else if (*s == '.' && !decimal_found)
            decimal_found = 1;
        else
            break;  // Stop at non-numeric character
        s++;
    }
    
    return sign * (res + fraction);
}