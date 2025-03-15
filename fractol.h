/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:39:34 by retahri           #+#    #+#             */
/*   Updated: 2025/03/15 06:25:41 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx_opengl_20191021/mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define HIGHT 400
#define WIDTH 400
#define MAND 1
#define JUL 2
# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"

typedef struct s_pixel
{
	int x;
	int y;
} t_pixel;

typedef struct s_complex
{
	double real;
	double imag;
}	t_complex;

typedef struct s_fractal
{
	int type;
	int zoom;
	u_int32_t color;
	double mouse_x;
	double mouse_y;
	double off_x;
	double off_y;
	int iterations;
	bool is_julia;

} t_fractal;


typedef struct s_image
{
	void	 *img_ptr;
	char	 *add;
	int		 p_bits;
	int 	line_len;
	int 	endian;
} 	t_image;

typedef struct s_win
{
	void *mlx;
	void *window;
	t_fractal fractal;
	t_image	image;

} t_win;

int		mandelbrot(t_fractal *fractal, t_complex *n);

// window management

void declare_type(t_win *win, char *s);
void reset_win(t_win *win, int frac_type);
void launch(t_win *win, char *av);

//rendering

void pixel2color(t_win *win, int x, int y, int color); // add_ptr cordinates 
int make_fractal(t_fractal *fract, t_complex *n, int x, double y);
void render(t_win *win);

//utils

void	error_message(char *text, int mode);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int 	ft_strlen(char *s);
void 	ft_putstr(char *s);
#endif