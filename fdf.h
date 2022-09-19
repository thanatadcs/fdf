/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:00:05 by tanukool          #+#    #+#             */
/*   Updated: 2022/09/19 23:34:25 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define C_H 500
# define C_W 500

typedef struct s_matrix
{
	double	data[4][4];
}	t_matrix;

typedef struct s_mlx_var
{
	void	*mlx;
	void	*win;
}	t_mlx_var;

typedef struct s_vec_2d
{
	double	x;
	double	y;
}	t_vec_2d;

typedef struct s_vec_h
{
	double	x;
	double	y;
	double	z;
	double	h;
}	t_vec_h;

typedef struct s_vec_lst
{
	t_vec_h				v;
	int					is_end_line;
	struct s_vec_lst	*next;
}	t_vec_lst;

typedef struct s_grid
{
	t_vec_lst	*head;
	t_vec_lst	*back;
	t_vec_lst	*origin;
	int			n_row;
	int			n_col;
}	t_grid;

// parse_file.c
void	append_grid(t_grid *grid_ptr, char *line);
t_grid	parse_file(char *path);
void	handle_error(t_grid grid, char *line, char **splited_line, char *msg);
void	free_grid(t_grid grid);

// draw_line.c
void	draw_line(t_vec_2d v0, t_vec_2d v1, int color);

// display_grid_loop.c
void	display_grid_loop(t_grid grid);
t_mlx_var	initialize(void);

// matrix_ops.c
t_matrix	matrix_multiply(t_matrix a, t_matrix b);
t_vec_h	matrix_vector_multiply(t_matrix m, t_vec_h v);

// matrix_transform.c
t_matrix	rotate_x_matrix(double	theta);
t_matrix	rotate_y_matrix(double	theta);
t_matrix	rotate_z_matrix(double	theta);
t_matrix	translate_matrix(double x, double y, double z);
t_matrix	scale_matrix(double k);

#endif
