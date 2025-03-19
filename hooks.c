#include "fractol.h"


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
    // Movement amount - inversely proportional to zoom level
    double move_amount = 20.0 / win->fractal.zoom;
    int update = 0;
    
    if (key == KEY_ESC)
    {
        mlx_destroy_image(win->mlx, win->image.img_ptr);
        mlx_destroy_window(win->mlx, win->window);
        exit(EXIT_SUCCESS);
    }
    else if (key == KEY_LEFT)
    {
        win->fractal.off_x -= move_amount;
        update = 1;
    }
    else if (key == KEY_RIGHT)
    {
        win->fractal.off_x += move_amount;
        update = 1;
    }
    else if (key == KEY_UP)
    {
        win->fractal.off_y -= move_amount;
        update = 1;
    }
    else if (key == KEY_DOWN)
    {
        win->fractal.off_y += move_amount;
        update = 1;
    }
    
    // Only render if view has changed
    if (update)
        render(win);
    
    return 0;
}
