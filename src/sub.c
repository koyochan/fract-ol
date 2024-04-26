/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 03:01:35 by kotkobay          #+#    #+#             */
/*   Updated: 2024/04/27 03:20:18 by kotkobay         ###   ########.fr       */
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
