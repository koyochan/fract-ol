#ifndef FRACT_OL_H
# define FRACT_OL_H

# define MAX_ITER 60
# define STEP 0.0037
# define Z_REAL 2;
# define Z_IMAGE 2;

# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct
{
	double	real;
	double	image;
}			Complex;

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

Complex		complex_add(Complex a, Complex b);
Complex		complex_multiply(Complex a, Complex b);
double		complex_ABS(Complex a);
int			julia_set(Complex x, Complex c);
int			create_window(Complex c, char set);
void		create_image_julia(t_data *img, Complex z, t_vars *vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		test_julia(Complex c);
void		create_image_mandelbrot(t_data *img, Complex c, t_vars *vars);
void		re_create_image_julia(t_vars *vars);
void		re_create_image_mandelbrot(t_vars *vars);

#endif