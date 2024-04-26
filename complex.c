/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:08:31 by kotkobay          #+#    #+#             */
/*   Updated: 2024/04/11 11:34:22 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

Complex	complex_add(Complex a, Complex b)
{
	Complex	result;

	result.real = a.real + b.real;
	result.image = a.image + b.image;
	return (result);
}

Complex	complex_multiply(Complex a, Complex b)
{
	Complex	result;

	result.real = a.real * b.real - a.image * b.image;
	result.image = a.real * b.image + a.image * b.real;
	return (result);
}

double	complex_ABS(Complex a)
{
	return (sqrt(a.real * a.real + a.image * a.image));
}
