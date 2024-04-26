/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:55:29 by kotkobay          #+#    #+#             */
/*   Updated: 2024/04/26 19:39:39 by kotkobay         ###   ########.fr       */
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

void	create_image_mandelbrot(t_data *img, Complex c)
{
	int		iter;
	Complex	z;

	z.real = 0;
	z.image = 0;
	int x, y;
	double startReal = -2.0, startImag = -2.0;      // 複素平面上の開始点
	double endReal = 2.0, endImag = 2.0;            // 複素平面上の終了点
	double realStep = (endReal - startReal) / 1080; // 実数部のステップ
	double imagStep = (endImag - startImag) / 1080; // 虚数部のステップ
	x = 0;
	while (x < 1080)
	{
		y = 0;
		c.real = startReal + x * realStep;
		while (y < 1080)
		{
			c.image = startImag + y * imagStep;
			iter = julia_set(z, c);
			colorize_image(img, x, y, iter);
			y++;
		}
		x++;
	}
}

void	re_create_image_julia(t_vars *vars)
{
	int		iter;
	Complex	z;
	Complex	c;

	c.real = vars->c_real;
	c.image = vars->c_image;
	int x, y;
	double startReal = -2.0, startImag = -2.0;      // 複素平面上の開始点
	double endReal = 2.0, endImag = 2.0;            // 複素平面上の終了点
	double realStep = (endReal - startReal) / 1080; // 実数部のステップ
	double imagStep = (endImag - startImag) / 1080; // 虚数部のステップ
	x = 0;
	while (x < 1080)
	{
		y = 0;
		z.real = startReal + x * realStep;
		while (y < 1080)
		{
			z.image = startImag + y * imagStep;
			iter = julia_set(z, c);
			colorize_image(&vars->img, x, y, iter);
			y++;
		}
		x++;
	}
}

void	create_image_julia(t_data *img, Complex c)
{
	int		iter;
	Complex	z;

	int x, y;
	double startReal = -2.0, startImag = -2.0;      // 複素平面上の開始点
	double endReal = 2.0, endImag = 2.0;            // 複素平面上の終了点
	double realStep = (endReal - startReal) / 1080; // 実数部のステップ
	double imagStep = (endImag - startImag) / 1080; // 虚数部のステップ
	x = 0;
	
	while (x < 1080)
	{
		y = 0;
		z.real = startReal + x * realStep;
		while (y < 1080)
		{
			z.image = startImag + y * imagStep;
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
