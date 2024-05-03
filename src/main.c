/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:21:22 by kotkobay          #+#    #+#             */
/*   Updated: 2024/05/03 10:23:14 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdlib.h>
#include <stdio.h>

double	ft_atod(const char *str)
{
	double	result;
	int		sign;
	double	fraction;

	sign = parse_sign_part(&str);
	result = parse_integer_part(&str);
	fraction = parse_fraction_part(&str);
	return (sign * (result + fraction));
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
	int i = 0;

	if (ac < 3)
	{
		c.real = -0.4;
		c.image = 0.6;
		return (c);
	}
	while(av[2][i])
	{
		if (('0' <= av[2][i] && av[2][i] <= '9') || av[2][i] == '.')
			i++;
		else
		{
			print_usage();
			exit(1);
		}
	}
	i = 0;
	while(av[3][i])
	{
		if (('0' <= av[3][i] && av[3][i] <= '9') || av[3][i] == '.')
			i++;
		else
		{
			print_usage();
			exit(1);
		}
	}
	c.real = ft_atod(av[2]);
	c.image = ft_atod(av[3]);
	return (c);
}

int	main(int ac, char **av)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.image = 2;
	z.real = 2;
	if (ac > 5 || ac == 1 || ac == 3 || (av[1][0] != 'j' && av[1][0] != 'm')
		|| (av[1][0] == 'm' && ac != 2))
	{
		print_usage();
		return (1);
	}
	while (av[1][i])
	{
		if (i == 1)
		{
			print_usage();
			return (1);
		}
		i++;
	}
	c = init_c(av, ac);
	create_window(c, av[1][0]);
	return (0);
}
