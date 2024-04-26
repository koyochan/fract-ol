/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:21:22 by kotkobay          #+#    #+#             */
/*   Updated: 2024/04/27 01:21:13 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	ft_atod(const char *str)
{
	double		result;
	double		fraction;
	int			sign;
	long long	divisor;

	result = 0.0;
	fraction = 0.0;
	sign = 1;
	divisor = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while ('0' <= *str && *str <= '9')
		{
			fraction = fraction * 10.0 + (*str - '0');
			divisor *= 10;
			str++;
		}
	}
	result += fraction / divisor;
	return (result * sign);
}

void	print_usage(void)
{
	write(1, "Usage: julia [options]\n", 24);
	write(1, "Options:\n", 10);
	write(1, "<type of set> 'j' or 'm''\n", 27);
	write(1, "<real> <imag>  Set the complex parameter 'c'\n", 46);
	return ;
}

t_complex	init_c(char **av, int ac)
{
	t_complex	c;

	if (ac < 3)
	{
		c.real = -0.4;
		c.image = 0.6;
		return (c);
	}
	c.real = ft_atod(av[2]);
	c.image = ft_atod(av[3]);
	return (c);
}

int	main(int ac, char **av)
{
	t_complex	z;
	t_complex	c;

	z.image = 2;
	z.real = 2;
	if (ac > 5 || ac == 1 || (av[1][0] != 'j' && av[1][0] != 'm')
		|| (av[1][0] == 'm' && ac != 2))
	{
		print_usage();
		return (1);
	}
	c = init_c(av, ac);
	create_window(c, av[1][0]);
	return (0);
}
