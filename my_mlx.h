#ifndef MY_MLX_H
# define MY_MLX_H

# include "mlx.h"

# define CANVAS_W 500
# define CANVAS_H 500

# define VIEWPORT_W 500
# define VIEWPORT_H 500
# define VIEWPORT_D 1

void	*mlx;
void	*win;

typedef struct s_point_2d
{
	double	x;
	double	y;
}	t_point_2d;

typedef struct s_point_3d
{
	double	x;
	double	y;
	double	z;
}	t_point_3d;

typedef struct s_point_h
{
	double	x;
	double	y;
	double	z;
	double	h;
}	t_point_h;

typedef struct s_matrix
{
	double	data[4][4];
}	t_matrix;

// pixel_put.c
void	pixel_put(t_point_2d p, int color);
void	initialize(void);

// draw_line.c
void	draw_line(t_point_2d p0, t_point_2d p1, int color);

// matrix_ops.c
t_matrix	matrix_multiply(t_matrix a, t_matrix b);
t_point_h	matrix_vector_multiply(t_matrix m, t_point_h v);

// matrix_transform.c
t_matrix	rotate_x_matrix(double	theta);
t_matrix	rotate_y_matrix(double	theta);
t_matrix	rotate_z_matrix(double	theta);
t_matrix	translate_matrix(double x, double y, double z);
t_matrix	scale_matrix(double k);

#endif
