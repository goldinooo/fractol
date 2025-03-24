/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 01:23:14 by retahri           #+#    #+#             */
/*   Updated: 2025/03/24 03:11:25 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H


//.......................** includes **.........................//
#include "MLX42/MLX42.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

//.......................** defines **.........................//
#define HEIGHT 600
#define WIDTH 600
#define MANDELBROT 0
#define JULIA 1

//.......................** structs **.........................//

typedef struct s_data
{
	void	*mlx;
	mlx_image_t *image;
	double off_x;
	double off_y;
	double zoom;
	int frac_type;
	int max_iter;
	double re;
	double im;
	int i;
	int r;
	int g;
	int b;
	int a;
} t_data;

typedef struct s_complex
{
	double real;
	double imag;
} t_complex;

typedef struct s_col
{
	int x;
	int y;
	int color;
} t_col;

//.......................** functions **.........................//


int			mandelbrot(double real, double img, int max_iter);
int 		julia(t_complex n, t_complex o, int max_iter);
void		error(void);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atof(char *s);
void		usage(void);
void 		render(t_data *data, int max_iter);
t_complex 	fractal(t_col *col , t_data *data);
void 		pixel2color(t_data *data, t_complex n, t_col *color, int max_iter);
int     	get_psychedelic(t_data *frac, int iterations, int max_iterations);
void 		key_hook(void *param);
void 		mouse_hook(double m_x, double m_y, void *param);
void		launch(t_data *data);

#endif