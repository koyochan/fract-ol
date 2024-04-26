/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:08:31 by kotkobay          #+#    #+#             */
/*   Updated: 2024/04/27 01:15:05 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.image = a.image + b.image;
	return (result);
}

t_complex	complex_multiply(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real * b.real - a.image * b.image;
	result.image = a.real * b.image + a.image * b.real;
	return (result);
}

double	complex_abs(t_complex a)
{
	return (sqrt(a.real * a.real + a.image * a.image));
}
