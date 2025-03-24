/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:17:44 by retahri           #+#    #+#             */
/*   Updated: 2025/03/23 02:41:19 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	skip(char *s, int *is_neg)
{
	int	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || s[i] == '\f'
		|| s[i] == '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}
double	ft_atof(char *s)
{
	int		i;
	int		sign;
	double	result;
	double	fraction;

	sign = 1;
	fraction = 0.1;
	result = 0;
	i = skip(s, &sign);
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			result = result + (s[i] - '0') * fraction;
			fraction /= 10;
			i++;
		}
	}
	return (result * sign);
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
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
