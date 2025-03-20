/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retahri <retahri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:39:34 by retahri           #+#    #+#             */
/*   Updated: 2025/03/20 02:15:44 by retahri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include "minilibx/mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define HIGHT 800
#define WIDTH 1000
#define MAND 1
#define JUL 2
# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"
#define SCROLL_UP 1
#define SCROLL_DOWN 2
#define KEY_ESC 53
#define KEY_LEFT 65361
#define KEY_UP 65362
#define KEY_RIGHT 65363
#define KEY_DOWN 65364

typedef struct s_complex
{
	double real;
	double imag;
}	t_complex;

typedef struct s_fractal
{
	int type;
	int zoom;
	int color;
	// double mouse_x;
	// double mouse_y;
	t_complex n;
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
int julia(t_fractal *fractal, t_complex *n);

// window management

void reset_win(t_win *win, int frac_type);
void launch(t_win *win, char *av);
int mouse_hooks(int button, int x, int y, void *param);
int key_hooks(int key, t_win *win);

//rendering

void pixel2color(t_win *win, int x, int y, int color); // add_ptr cordinates 
int make_fractal(t_fractal *fract, t_complex *n, int x, double y);
void render(t_win *win);

//utils

void	error_message(char *text, int mode);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int 	ft_strlen(char *s);
void 	ft_putstr(char *s);
double 	ft_atof(char *s);
void 	clearup(t_win *win);


#endif