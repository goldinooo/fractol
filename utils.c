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