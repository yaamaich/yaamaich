/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albelaiz <albelaiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:56:50 by albelaiz          #+#    #+#             */
/*   Updated: 2025/11/17 16:11:45 by albelaiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <mlx.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define POINT_SIZE 10
#define MOVE_SPEED 5

// Key codes for Linux
#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    char    *img_data;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
    t_point point;
    int     key_w;
    int     key_s;
    int     key_a;
    int     key_d;
    int     key_up;
    int     key_down;
    int     key_left;
    int     key_right;
}   t_mlx_data;

void put_pixel(t_mlx_data *data, int x, int y, int color)
{
    int pixel;

    if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
    {
        pixel = (y * data->size_line) + (x * (data->bits_per_pixel / 8));
        data->img_data[pixel] = color & 0xFF;
        data->img_data[pixel + 1] = (color >> 8) & 0xFF;
        data->img_data[pixel + 2] = (color >> 16) & 0xFF;
    }
}

void draw_square(t_mlx_data *data, int x, int y, int size, int color)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            put_pixel(data, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void clear_image(t_mlx_data *data)
{
    int x;
    int y;

    y = 0;
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            put_pixel(data, x, y, 0x000000);
            x++;
        }
        y++;
    }
}

int render(t_mlx_data *data)
{
    // Update position based on pressed keys
    if (data->key_w || data->key_up)
        data->point.y -= MOVE_SPEED;
    if (data->key_s || data->key_down)
        data->point.y += MOVE_SPEED;
    if (data->key_a || data->key_left)
        data->point.x -= MOVE_SPEED;
    if (data->key_d || data->key_right)
        data->point.x += MOVE_SPEED;
    
    // Keep point within window bounds
    if (data->point.x < 0)
        data->point.x = 0;
    if (data->point.x > WIN_WIDTH - POINT_SIZE)
        data->point.x = WIN_WIDTH - POINT_SIZE;
    if (data->point.y < 0)
        data->point.y = 0;
    if (data->point.y > WIN_HEIGHT - POINT_SIZE)
        data->point.y = WIN_HEIGHT - POINT_SIZE;
    
    clear_image(data);
    draw_square(data, data->point.x, data->point.y, POINT_SIZE, 0xFF0000);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
    return (0);
}

int key_press(int keycode, t_mlx_data *data)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    else if (keycode == KEY_W)
        data->key_w = 1;
    else if (keycode == KEY_S)
        data->key_s = 1;
    else if (keycode == KEY_A)
        data->key_a = 1;
    else if (keycode == KEY_D)
        data->key_d = 1;
    else if (keycode == KEY_UP)
        data->key_up = 1;
    else if (keycode == KEY_DOWN)
        data->key_down = 1;
    else if (keycode == KEY_LEFT)
        data->key_left = 1;
    else if (keycode == KEY_RIGHT)
        data->key_right = 1;
    
    return (0);
}

int key_release(int keycode, t_mlx_data *data)
{
    if (keycode == KEY_W)
        data->key_w = 0;
    else if (keycode == KEY_S)
        data->key_s = 0;
    else if (keycode == KEY_A)
        data->key_a = 0;
    else if (keycode == KEY_D)
        data->key_d = 0;
    else if (keycode == KEY_UP)
        data->key_up = 0;
    else if (keycode == KEY_DOWN)
        data->key_down = 0;
    else if (keycode == KEY_LEFT)
        data->key_left = 0;
    else if (keycode == KEY_RIGHT)
        data->key_right = 0;
    
    return (0);
}

int close_window(t_mlx_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(0);
    return (0);
}

int main(int ac , char **av)
{
    t_mlx_data data;
    
    (void)ac;
    (void)av;
    
    // Initialize MLX
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
    {
        printf("Error\nFailed to initialize MLX\n");
        return (1);
    }
    
    // Create window
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3D - Movable Point");
    if (!data.win_ptr)
    {
        printf("Error\nFailed to create window\n");
        return (1);
    }
    
    // Create image
    data.img_ptr = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    data.img_data = mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel, 
                                      &data.size_line, &data.endian);
    
    // Initialize point position (center of screen)
    data.point.x = WIN_WIDTH / 2;
    data.point.y = WIN_HEIGHT / 2;
    
    // Initialize key states to 0 (not pressed)
    data.key_w = 0;
    data.key_s = 0;
    data.key_a = 0;
    data.key_d = 0;
    data.key_up = 0;
    data.key_down = 0;
    data.key_left = 0;
    data.key_right = 0;
    
    // Initial render
    render(&data);
    
    // Set up hooks
    mlx_hook(data.win_ptr, 2, 1L<<0, key_press, &data);
    mlx_hook(data.win_ptr, 3, 1L<<1, key_release, &data);
    mlx_hook(data.win_ptr, 17, 0, close_window, &data);
    mlx_loop_hook(data.mlx_ptr, render, &data);
    
    // Start the loop
    mlx_loop(data.mlx_ptr);
    
    return (0);
}
