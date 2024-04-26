/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:55:29 by kotkobay          #+#    #+#             */
/*   Updated: 2024/04/26 21:30:22 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	colorize_image(t_data *img, int x, int y, int iter)
{
	int	R;
	int	G;
	int	B;
	int	T;
	int	color;

	R = (iter * 255) / MAX_ITER;
	G = (255 - (iter * 255) / MAX_ITER);
	B = 128;
	T = 255;
	color = (T << 24) | (R << 16) | (G << 8) | B;
	/* printf("%p\n", img);
	printf("%d %d %d\n", iter, x, y); */
	my_mlx_pixel_put(img, x, y, color);
}

void	create_image_mandelbrot(t_data *img, Complex c, t_vars *vars)
{
	int		iter;
	Complex	z;
	int		x;
	int		y;

	z.real = 0;
	z.image = 0;
	x = 0;
	while (x < 1080)
	{
		y = 0;
		c.real = vars->size.startreal + x * vars->size.realstep;
		while (y < 1080)
		{
			c.image = vars->size.startimag + y * vars->size.imagstep;
			iter = julia_set(z, c);
			colorize_image(img, x, y, iter);
			y++;
		}
		x++;
	}
}

void	create_image_julia(t_data *img, Complex c, t_vars *vars)
{
	int		iter;
	Complex	z;
	int		x;
	int		y;

	x = 0;
	while (x < 1080)
	{
		y = 0;
		z.real = vars->size.startreal + x * vars->size.realstep;
		while (y < 1080)
		{
			z.image = vars->size.startimag + y * vars->size.imagstep;
			iter = julia_set(z, c);
			colorize_image(img, x, y, iter);
			y++;
		}
		x++;
	}
}

int	julia_set(Complex z, Complex c)
{
	int	iter;

	iter = 0;
	/* z.image = 0;
	z.real = 0; */
	/* printf("z real: %f\n", z.real);
	printf("z image: %f\n", z.image);
	printf("c real: %f\n", c.real);
	printf("c image: %f\n", c.image); */
	while (complex_ABS(z) <= 2 && iter <= MAX_ITER)
	{
		z = complex_add(complex_multiply(z, z), c);
		iter++;
	}
	return (iter);
}

void	re_create_image_mandelbrot(t_vars *vars)
{
	int		iter;
	Complex	z;
	Complex	c;
	int		x;
	int		y;

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
}
void	re_create_image_julia(t_vars *vars)
{
	int iter;
	Complex z;
	Complex c;
	int x;
	int y;

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
}