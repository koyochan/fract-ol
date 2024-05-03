/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:48:33 by kotkobay          #+#    #+#             */
/*   Updated: 2024/04/28 12:13:34 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == 65307 || keycode == 1870326816)
	{
		exit(0);
		mlx_destroy_window(vars->mlx, vars->mlx_window);
	}
	return (0);
}

int	close_window_x(int keycode, t_vars *vars)
{
	(void)keycode;
	exit(0);
	mlx_destroy_window(vars->mlx, vars->mlx_window);
	return (0);
}

void	redraw(t_vars *vars)
{
	t_complex	c;

	c.real = vars->c_real;
	c.image = vars->c_image;
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, 1080, 1080);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	if (vars->type_of_fractol == 'j')
		create_image_julia(vars);
	else if (vars->type_of_fractol == 'm')
		create_image_mandelbrot(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_window, vars->img.img, 0, 0);
	return ;
}

int	mouse_zoom(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
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
	redraw(vars);
	return (0);
}

void	init_vars(t_vars *vars, t_complex c, char set)
{
	vars->type_of_fractol = set;
	vars->zoom = 1;
	vars->c_image = c.image;
	vars->c_real = c.real;
	vars->size.startreal = -2.0;
	vars->size.startimag = -2.0;
	vars->size.endreal = 2.0;
	vars->size.endimag = 2.0;
	vars->size.imagstep = (vars->size.endimag - vars->size.startimag) / 1080;
	vars->size.realstep = (vars->size.endreal - vars->size.startreal) / 1080;
	return ;
}

int	create_window(t_complex c, char set)
{
	t_vars	vars;

	init_vars(&vars, c, set);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);
	vars.mlx_window = mlx_new_window(vars.mlx, 1080, 1080, "fract-ol");
	if (vars.mlx_window == NULL)
		return (1);
	vars.img.img = mlx_new_image(vars.mlx, 1080, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	if (set == 'j')
		create_image_julia(&vars);
	else if (set == 'm')
		create_image_mandelbrot(&vars);
	mlx_mouse_hook(vars.mlx_window, mouse_zoom, &vars);
	mlx_put_image_to_window(vars.mlx, vars.mlx_window, vars.img.img, 0, 0);
	mlx_hook(vars.mlx_window, 2, 1L << 0, close_window, &vars);
	mlx_hook(vars.mlx_window, 17, 0, close_window_x, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
