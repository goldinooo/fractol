#include "fractol.h"

int	mouse_hooks(int button, int x, int y, void *param)
{
	t_win	*win;
	int		mouse_x;
	int		mouse_y;
	double	mouse_re;
	double	mouse_im;

	win = (t_win *)param;
	// Use the input parameters directly instead of getting mouse position again
	mouse_x = x;
	mouse_y = y;
	// Calculate real and imaginary coordinates at mouse position
	mouse_re = (mouse_x - WIDTH / 2.0) / win->fractal.zoom + win->fractal.off_x;
	mouse_im = (mouse_y - HIGHT / 2.0) / win->fractal.zoom + win->fractal.off_y;
	if (button == SCROLL_UP)
		win->fractal.zoom *= 1.1;
	else if (button == SCROLL_DOWN)
		win->fractal.zoom /= 1.1;
	else
		return (0);
	if (win->fractal.zoom < 10)
		win->fractal.zoom = 10;
	// Calculate new offsets to keep mouse_re and mouse_im at the same pixel
	win->fractal.off_x = mouse_re - (mouse_x - WIDTH / 2.0) / win->fractal.zoom;
	win->fractal.off_y = mouse_im - (mouse_y - HIGHT / 2.0) / win->fractal.zoom;
	render(win);
	return (0);
}

int	key_hooks(int key, t_win *win)
{
	double	move_amount;

	move_amount = 20.0 / win->fractal.zoom;
	if (key == KEY_ESC)
		clearup(win);
	else if (key == KEY_LEFT)
		win->fractal.off_x -= move_amount;
	else if (key == KEY_RIGHT)
		win->fractal.off_x += move_amount;
	else if (key == KEY_UP)
		win->fractal.off_y -= move_amount;
	else if (key == KEY_DOWN)
		win->fractal.off_y += move_amount;
	else
		return (0);
	render(win);
	return (0);
}
