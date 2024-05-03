/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:20:17 by kotkobay          #+#    #+#             */
/*   Updated: 2024/04/28 11:55:11 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define MAX_ITER 60

# include "../mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double	real;
	double	image;
}			t_complex;

typedef struct s_size
{
	double	startreal;
	double	startimag;
	double	endreal;
	double	endimag;
	double	realstep;
	double	imagstep;
}			t_size;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	t_size	size;
	double	zoom;
	char	type_of_fractol;
	double	c_real;
	double	c_image;
	double	center_x;
	double	center_y;
}			t_vars;

t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_multiply(t_complex a, t_complex b);
double		complex_abs(t_complex a);
int			julia_set(t_complex x, t_complex c);
int			create_window(t_complex c, char set);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		test_julia(t_complex c);
void		create_image_julia(t_vars *vars);
void		create_image_mandelbrot(t_vars *vars);
int			parse_sign_part(const char **str);
double		parse_integer_part(const char **str);
double		parse_fraction_part(const char **str);

#endif