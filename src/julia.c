/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:55:29 by kotkobay          #+#    #+#             */
/*   Updated: 2024/05/03 14:54:26 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	colorize_image(t_data *img, int x, int y, int iter)
{
	int	r;
	int	g;
	int	b;
	int	t;
	int	color;

	r = (iter * 255) / MAX_ITER;
	g = (255 - (iter * 255) / MAX_ITER);
	b = 128;
	t = 255;
	color = (t << 24) | (r << 16) | (g << 8) | b;
	my_mlx_pixel_put(img, x, y, color);
}

int	julia_set(t_complex z, t_complex c)
{
	int	iter;

	iter = 0;
	while (complex_abs(z) <= 2 && iter <= MAX_ITER)
	{
		z = complex_add(complex_multiply(z, z), c);
		iter++;
	}
	return (iter);
}

void	create_image_mandelbrot(t_vars *vars)
{
	int			iter;
	t_complex	z;
	t_complex	c;
	int			x;
	int			y;

	z.real = 0;
	z.image = 0;
	x = 0;
	while (x < 1080)
	{
		y = 0;
		c.real = vars->size.startreal + x * vars->size.realstep * vars->zoom;
		while (y < 1080)
		{
			c.image = vars->size.startimag + y * vars->size.imagstep
				* vars->zoom;
			iter = julia_set(z, c);
			colorize_image(&vars->img, x, y, iter);
			y++;
		}
		x++;
	}
	return ;
}

void	create_image_julia(t_vars *vars)
{
	int			iter;
	t_complex	z;
	t_complex	c;
	int			x;
	int			y;

	c.real = vars->c_real;
	c.image = vars->c_image;
	x = 0;
	while (x < 1080)
	{
		y = 0;
		z.real = vars->size.startreal + x * vars->size.realstep * vars->zoom;
		while (y < 1080)
		{
			z.image = vars->size.startimag + y * vars->size.imagstep
				* vars->zoom;
			iter = julia_set(z, c);
			colorize_image(&vars->img, x, y, iter);
			y++;
		}
		x++;
	}
	return ;
}
