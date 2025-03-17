#include "fractol.h"
#define SCROLL_UP 4
#define SCROLL_DOWN 5

int mouse_hooks(int button, int x, int y, void *param)
{
    t_win *win = (t_win *)param;
    int mouse_x, mouse_y;
    double mouse_re, mouse_im;
    double zoom_factor;
    // Use the input parameters directly instead of getting mouse position again
    // This can be more reliable in some systems
    mouse_x = x;
    mouse_y = y; 
    // Calculate real and imaginary coordinates at mouse position
    mouse_re = (mouse_x - WIDTH / 2.0) / win->fractal.zoom + win->fractal.off_x;
    mouse_im = (mouse_y - HIGHT / 2.0) / win->fractal.zoom + win->fractal.off_y; 
    // Apply zoom based on scroll direction
    if (button == SCROLL_UP)
        win->fractal.zoom *= 1.1;
    else if (button == SCROLL_DOWN)
        win->fractal.zoom /= 1.1;
    else
        return (0);
    // Apply minimum zoom limit
    if (win->fractal.zoom < 10)
        win->fractal.zoom = 10;
    // Calculate new offsets to keep mouse_re and mouse_im at the same pixel
    win->fractal.off_x = mouse_re - (mouse_x - WIDTH / 2.0) / win->fractal.zoom;
    win->fractal.off_y = mouse_im - (mouse_y - HIGHT / 2.0) / win->fractal.zoom;  
    render(win); // Re-render with new parameters
    return (0);
}

int key_hooks(int key, t_win *win)
{
	if (key == 65307)
	{
		mlx_destroy_image(win->mlx, win->image.img_ptr);
		mlx_destroy_window(win->mlx, win->window);
		exit(EXIT_SUCCESS);
	}
	render(win);
	return 0;
}

int hook_jul(int x, int y, t_win *win)
{
    if (win->fractal.type == JUL && win->fractal.is_julia)
    {
        // Calculate real and imaginary coordinates at mouse position
        win->fractal.mouse_x = (x - WIDTH / 2.0) / win->fractal.zoom + win->fractal.off_x;
        win->fractal.mouse_y = (y - HIGHT / 2.0) / win->fractal.zoom + win->fractal.off_y;
        
        // Debug log to see parameter changes
        printf("Dynamic Julia params: c = %.4f + %.4fi\n", 
               win->fractal.mouse_x, win->fractal.mouse_y);
        
        // Re-render with new parameters
        render(win);
    }
    return (0);
}