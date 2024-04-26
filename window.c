/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:48:33 by kotkobay          #+#    #+#             */
/*   Updated: 2024/04/26 20:22:50 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int	close_window(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->mlx_window);
	return (0);
}

void	redraw(t_vars *vars)
{
	Complex	c;

	c.real = vars->c_real;
	c.image = vars->c_image;
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, 1080, 1080);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	printf("redraw\n");
/* 	printf("%p\n", vars->img.img);
	printf("c\\ %f %f", c.real, c.image); */
	re_create_image_julia(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_window, vars->img.img, 0, 0);
}

int	mouse_zoom(int button, int x, int y, t_vars *vars)
{
	printf("c: real: %f\n", vars->c_real);
	printf("c: image: %f\n", vars->c_image);
	printf("botton: %d\n", button);
	if (button == 4)
	{
		vars->zoom *= 1.1;
	}
	else if (button == 5)
	{
		vars->zoom /= 1.1;
	}
	else
		return (0);
	printf("zoom: %f\n", vars->zoom);
	redraw(vars);
	return (0);
}

int	create_window(Complex c, char set)
{
	t_vars	vars;

	vars.type_of_fractol = set;
	vars.zoom = 1;
	vars.c_image = c.image;
	vars.c_real = c.real;
	vars.mlx = mlx_init();
	vars.mlx_window = mlx_new_window(vars.mlx, 1080, 1080, "fract-ol");
	vars.img.img = mlx_new_image(vars.mlx, 1080, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	if (set == 'j')
		create_image_julia(&vars.img, c);
	else if (set == 'm')
		create_image_mandelbrot(&vars.img, c);
	mlx_mouse_hook(vars.mlx_window, mouse_zoom, &vars);
	mlx_put_image_to_window(vars.mlx, vars.mlx_window, vars.img.img, 0, 0);
	mlx_hook(vars.mlx_window, 2, 1L << 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
