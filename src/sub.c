/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:01:35 by kotkobay          #+#    #+#             */
/*   Updated: 2024/05/03 10:40:13 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	parse_sign_part(const char **str)
{
	int	sign;

	sign = 1;
	while ((9 <= **str && **str <= 13) || **str == ' ')
		(*str)++;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign *= -1;
		(*str)++;
	}
	return (sign);
}

double	parse_integer_part(const char **str)
{
	double	result;

	result = 0.0;
	while ('0' <= **str && **str <= '9')
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	parse_fraction_part(const char **str)
{
	double		fraction;
	long long	divisor;

	fraction = 0.0;
	divisor = 1;
	if (**str == '.')
	{
		(*str)++;
		while ('0' <= **str && **str <= '9')
		{
			fraction = fraction * 10.0 + (**str - '0');
			divisor *= 10;
			(*str)++;
		}
	}
	return (fraction / divisor);
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
